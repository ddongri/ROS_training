"""
Mobile robot motion planning sample with Dynamic Window Approach
author: Atsushi Sakai (@Atsushi_twi), Göktuğ Karakaşlı
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Vector3
from turtlesim.msg import Pose
from std_msgs.msg import Float32

import math
from enum import Enum

import numpy as np


#################################################################################################################################################
#################################################################################################################################################


class Dwa(Node):

    def __init__(self):
        super().__init__('turtle_dwa')

        # robot parameter
        self.max_speed = 0.7  # [m/s]
        self.min_speed = -0.5  # [m/s]
        self.max_yaw_rate = 70.0 * math.pi / 180.0  # [rad/s]
        self.max_accel = 0.2  # [m/ss]
        self.max_delta_yaw_rate = 40.0 * math.pi / 180.0  # [rad/ss]
        self.v_resolution = 0.01  # [m/s]
        self.yaw_rate_resolution = 0.1 * math.pi / 180.0  # [rad/s]
        self.dt = 0.1  # [s] Time tick for motion prediction
        self.predict_time = 3.0  # [s]
        self.to_goal_cost_gain = 0.15
        self.speed_cost_gain = 1.0
        self.obstacle_cost_gain = 1.0
        self.robot_stuck_flag_cons = 0.001  # constant to prevent robot stucked
        self.robot_type = 0

        # if robot_type == RobotType.circle
        # Also used to check if is reached in both types
        self.robot_radius = 1.0  # [m] for collision check

        # if robot_type == RobotType.rectangle
        self.robot_width = 0.5  # [m] for collision check
        self.robot_length = 1.2  # [m] for collision check
        # obstacles [x(m) y(m), ....]
        self.ob = np.array([[-1, -1]])
        self.waypoint = np.array([[8.58, 2.5], [2.5, 8.58], [2.5, 2.5], [8.58, 8.58]])
        self.point_index = 0

        self.u = np.array([0, 0])
        self.x = np.array([0,0,0,0,0])
        self.location = np.array([0,0,0,0,0])
        
        self.obs = self.create_subscription(Pose, '/turtle1/pose', self.obst, 10)
        self.sub = self.create_subscription(Pose, '/turtle2/pose', self.subscribe, 10)
        self.pub = self.create_publisher(Twist, '/turtle2/cmd_vel', 10) 

        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.publish)

    def obst(self, msg):
        self.ob_pose = np.array([[msg.x, msg.y]])
        self.ob = self.ob_pose

    def subscribe(self, msg):
        self.x = msg.x
        self.y = msg.y
        self.theta = msg.theta
        self.linear_velocity = msg.linear_velocity
        self.angular_velocity = msg.angular_velocity
        # state [x(m), y(m), yaw(rad), v(m/s), omega(rad/s)]
        self.location = np.array([self.x, self.y, self.theta, self.linear_velocity, self.angular_velocity])

    def publish(self):
        self.cmd = Twist()
        self.linear = Vector3()
        self.angular = Vector3()

        self.dwa_run(robot_type=0)

        self.cmd.linear = self.linear
        self.cmd.angular = self.angular

        self.pub.publish(self.cmd)

    def dwa_run(self, robot_type=0):

        # goal position [x(m), y(m)]
        self.goal = np.array([self.waypoint[self.point_index%4][0], self.waypoint[self.point_index%4][1]])

        # input [forward speed, yaw_rate]

        self.robot_type = robot_type
        self.trajectory = np.array(self.location)

        self.u, self.predicted_trajectory = self.dwa_control(self.location, self.goal, self.ob)

        self.linear.x = self.u[0] * math.cos(self.location[2])
        self.linear.y = self.u[0] * math.sin(self.location[2])
        self.linear.z = 0.0
        self.angular.x = 0.0
        self.angular.y = 0.0
        self.angular.z = self.u[1]

        # check reaching goal
        self.dist_to_goal = math.hypot(self.location[0] - self.goal[0], self.location[1] - self.goal[1])

        if self.dist_to_goal <= self.robot_radius:
            self.point_index += 1

        print("Waypoint : {}".format(self.point_index%4))
        print("Goal : {a}, {b}".format(a = self.goal[0], b = self.goal[1]))
        print("Location : {a}, {b}, {c}".format(a = self.location[0], b = self.location[1], c = self.location[2]))
        print("ob : {a}, {b}".format(a = self.ob[0][0], b = self.ob[0][1]))

    def dwa_control(self, x, goal, ob):
        """
        Dynamic Window Approach control
        """
        self.dw = self.calc_dynamic_window(x)

        u, trajectory = self.calc_control_and_trajectory(x, self.dw, goal, ob)

        return u, trajectory

    def motion(self, x, u, dt):
        """
        motion model
        """

        x[2] += u[1] * dt
        x[0] += u[0] * math.cos(x[2]) * dt
        x[1] += u[0] * math.sin(x[2]) * dt
        x[3] = u[0]
        x[4] = u[1]

        return x


    def calc_dynamic_window(self, x):
        """
        calculation dynamic window based on current state x
        """

        # Dynamic window from robot specification
        Vs = [self.min_speed, self.max_speed,
            -self.max_yaw_rate, self.max_yaw_rate]

        # Dynamic window from motion model
        Vd = [x[3] - self.max_accel * self.dt,
            x[3] + self.max_accel * self.dt,
            x[4] - self.max_delta_yaw_rate * self.dt,
            x[4] + self.max_delta_yaw_rate * self.dt]

        #  [v_min, v_max, yaw_rate_min, yaw_rate_max]
        dw = [max(Vs[0], Vd[0]), min(Vs[1], Vd[1]),
            max(Vs[2], Vd[2]), min(Vs[3], Vd[3])]

        return dw


    def predict_trajectory(self, x_init, v, y):
        """
        predict trajectory with an input
        """

        x = np.array(x_init)
        trajectory = np.array(x)
        time = 0
        while time <= self.predict_time:
            x = self.motion(x, [v, y], self.dt)
            trajectory = np.vstack((trajectory, x))
            time += self.dt

        return trajectory


    def calc_control_and_trajectory(self, x, dw, goal, ob):
        """
        calculation final input with dynamic window
        """

        x_init = x[:]
        min_cost = float("inf")
        best_u = [0.0, 0.0]
        best_trajectory = np.array([x])

        # evaluate all trajectory with sampled input in dynamic window
        for v in np.arange(dw[0], dw[1], self.v_resolution):
            for y in np.arange(dw[2], dw[3], self.yaw_rate_resolution):

                trajectory = self.predict_trajectory(x_init, v, y)
                # calc cost
                to_goal_cost = self.to_goal_cost_gain * self.calc_to_goal_cost(trajectory, goal)
                speed_cost = self.speed_cost_gain * (self.max_speed - trajectory[-1, 3])
                ob_cost = self.obstacle_cost_gain * self.calc_obstacle_cost(trajectory, ob)

                final_cost = to_goal_cost + speed_cost + ob_cost

                # search minimum trajectory
                if min_cost >= final_cost:
                    min_cost = final_cost
                    best_u = [v, y]
                    best_trajectory = trajectory
                    if abs(best_u[0]) < self.robot_stuck_flag_cons \
                            and abs(x[3]) < self.robot_stuck_flag_cons:
                        # to ensure the robot do not get stuck in
                        # best v=0 m/s (in front of an obstacle) and
                        # best omega=0 rad/s (heading to the goal with
                        # angle difference of 0)
                        best_u[1] = -self.max_delta_yaw_rate
        return best_u, best_trajectory


    def calc_obstacle_cost(self, trajectory, ob):
        """
        calc obstacle cost inf: collision
        """
        ox = ob[:, 0]
        oy = ob[:, 1]
        dx = trajectory[:, 0] - ox[:, None]
        dy = trajectory[:, 1] - oy[:, None]
        r = np.hypot(dx, dy)

        if self.robot_type == 1:
            yaw = trajectory[:, 2]
            rot = np.array([[np.cos(yaw), -np.sin(yaw)], [np.sin(yaw), np.cos(yaw)]])
            rot = np.transpose(rot, [2, 0, 1])
            local_ob = ob[:, None] - trajectory[:, 0:2]
            local_ob = local_ob.reshape(-1, local_ob.shape[-1])
            local_ob = np.array([local_ob @ x for x in rot])
            local_ob = local_ob.reshape(-1, local_ob.shape[-1])
            upper_check = local_ob[:, 0] <= self.robot_length / 2
            right_check = local_ob[:, 1] <= self.robot_width / 2
            bottom_check = local_ob[:, 0] >= -self.robot_length / 2
            left_check = local_ob[:, 1] >= -self.robot_width / 2
            if (np.logical_and(np.logical_and(upper_check, right_check),
                            np.logical_and(bottom_check, left_check))).any():
                return float("Inf")
        elif self.robot_type == 0:
            if np.array(r <= self.robot_radius).any():
                return float("Inf")

        min_r = np.min(r)
        return 1.0 / min_r  # OK


    def calc_to_goal_cost(self, trajectory, goal):
        """
            calc to goal cost with angle difference
        """

        dx = goal[0] - trajectory[-1, 0]
        dy = goal[1] - trajectory[-1, 1]
        error_angle = math.atan2(dy, dx)
        cost_angle = error_angle - trajectory[-1, 2]
        cost = abs(math.atan2(math.sin(cost_angle), math.cos(cost_angle)))

        return cost


#################################################################################################################################################
#################################################################################################################################################


def main(args=None):
    rclpy.init(args=args)

    dwa = Dwa()
    rclpy.spin(dwa)

    dwa.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main(robot_type=0)


