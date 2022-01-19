// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from turtle_msg:msg/Custom.idl
// generated code does not contain a copyright notice
#include "turtle_msg/msg/custom__rosidl_typesupport_fastrtps_cpp.hpp"
#include "turtle_msg/msg/custom__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace turtle_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_msg
cdr_serialize(
  const turtle_msg::msg::Custom & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: radius
  cdr << ros_message.radius;
  // Member: velocity
  cdr << ros_message.velocity;
  // Member: direction
  cdr << ros_message.direction;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  turtle_msg::msg::Custom & ros_message)
{
  // Member: radius
  cdr >> ros_message.radius;

  // Member: velocity
  cdr >> ros_message.velocity;

  // Member: direction
  cdr >> ros_message.direction;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_msg
get_serialized_size(
  const turtle_msg::msg::Custom & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: radius
  {
    size_t item_size = sizeof(ros_message.radius);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: velocity
  {
    size_t item_size = sizeof(ros_message.velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: direction
  {
    size_t item_size = sizeof(ros_message.direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_msg
max_serialized_size_Custom(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: radius
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: direction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Custom__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const turtle_msg::msg::Custom *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Custom__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<turtle_msg::msg::Custom *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Custom__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const turtle_msg::msg::Custom *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Custom__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Custom(full_bounded, 0);
}

static message_type_support_callbacks_t _Custom__callbacks = {
  "turtle_msg::msg",
  "Custom",
  _Custom__cdr_serialize,
  _Custom__cdr_deserialize,
  _Custom__get_serialized_size,
  _Custom__max_serialized_size
};

static rosidl_message_type_support_t _Custom__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Custom__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace turtle_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_turtle_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<turtle_msg::msg::Custom>()
{
  return &turtle_msg::msg::typesupport_fastrtps_cpp::_Custom__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtle_msg, msg, Custom)() {
  return &turtle_msg::msg::typesupport_fastrtps_cpp::_Custom__handle;
}

#ifdef __cplusplus
}
#endif
