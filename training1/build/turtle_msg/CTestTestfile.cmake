# CMake generated Testfile for 
# Source directory: /home/dongri/ros_training_ws/training1/src/turtle_msg
# Build directory: /home/dongri/ros_training_ws/training1/build/turtle_msg
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(lint_cmake "/usr/bin/python3" "-u" "/opt/ros/dashing/share/ament_cmake_test/cmake/run_test.py" "/home/dongri/ros_training_ws/training1/build/turtle_msg/test_results/turtle_msg/lint_cmake.xunit.xml" "--package-name" "turtle_msg" "--output-file" "/home/dongri/ros_training_ws/training1/build/turtle_msg/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/dashing/bin/ament_lint_cmake" "--xunit-file" "/home/dongri/ros_training_ws/training1/build/turtle_msg/test_results/turtle_msg/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/dongri/ros_training_ws/training1/src/turtle_msg")
add_test(xmllint "/usr/bin/python3" "-u" "/opt/ros/dashing/share/ament_cmake_test/cmake/run_test.py" "/home/dongri/ros_training_ws/training1/build/turtle_msg/test_results/turtle_msg/xmllint.xunit.xml" "--package-name" "turtle_msg" "--output-file" "/home/dongri/ros_training_ws/training1/build/turtle_msg/ament_xmllint/xmllint.txt" "--command" "/opt/ros/dashing/bin/ament_xmllint" "--xunit-file" "/home/dongri/ros_training_ws/training1/build/turtle_msg/test_results/turtle_msg/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/dongri/ros_training_ws/training1/src/turtle_msg")
subdirs("turtle_msg__py")
