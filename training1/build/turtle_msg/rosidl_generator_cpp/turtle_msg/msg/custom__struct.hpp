// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_msg:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_MSG__MSG__CUSTOM__STRUCT_HPP_
#define TURTLE_MSG__MSG__CUSTOM__STRUCT_HPP_

#include <rosidl_generator_cpp/bounded_vector.hpp>
#include <rosidl_generator_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

// Protect against ERROR being predefined on Windows, in case somebody defines a
// constant by that name.
#if defined(_WIN32)
  #if defined(ERROR)
    #undef ERROR
  #endif
  #if defined(NO_ERROR)
    #undef NO_ERROR
  #endif
#endif

#ifndef _WIN32
# define DEPRECATED__turtle_msg__msg__Custom __attribute__((deprecated))
#else
# define DEPRECATED__turtle_msg__msg__Custom __declspec(deprecated)
#endif

namespace turtle_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Custom_
{
  using Type = Custom_<ContainerAllocator>;

  explicit Custom_(rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  {
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->radius = 0.0f;
      this->velocity = 0.0f;
      this->direction = 0ll;
    }
  }

  explicit Custom_(const ContainerAllocator & _alloc, rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->radius = 0.0f;
      this->velocity = 0.0f;
      this->direction = 0ll;
    }
  }

  // field types and members
  using _radius_type =
    float;
  _radius_type radius;
  using _velocity_type =
    float;
  _velocity_type velocity;
  using _direction_type =
    int64_t;
  _direction_type direction;

  // setters for named parameter idiom
  Type & set__radius(
    const float & _arg)
  {
    this->radius = _arg;
    return *this;
  }
  Type & set__velocity(
    const float & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__direction(
    const int64_t & _arg)
  {
    this->direction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_msg::msg::Custom_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_msg::msg::Custom_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_msg::msg::Custom_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_msg::msg::Custom_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_msg::msg::Custom_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_msg::msg::Custom_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_msg::msg::Custom_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_msg::msg::Custom_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_msg::msg::Custom_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_msg::msg::Custom_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_msg__msg__Custom
    std::shared_ptr<turtle_msg::msg::Custom_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_msg__msg__Custom
    std::shared_ptr<turtle_msg::msg::Custom_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Custom_ & other) const
  {
    if (this->radius != other.radius) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    return true;
  }
  bool operator!=(const Custom_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Custom_

// alias to use template instance with default allocator
using Custom =
  turtle_msg::msg::Custom_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtle_msg

#endif  // TURTLE_MSG__MSG__CUSTOM__STRUCT_HPP_
