// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtle_msg:msg/Custom.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtle_msg/msg/custom__rosidl_typesupport_introspection_c.h"
#include "turtle_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtle_msg/msg/custom__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

static rosidl_typesupport_introspection_c__MessageMember Custom__rosidl_typesupport_introspection_c__Custom_message_member_array[3] = {
  {
    "radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_msg__msg__Custom, radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_msg__msg__Custom, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_msg__msg__Custom, direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Custom__rosidl_typesupport_introspection_c__Custom_message_members = {
  "turtle_msg__msg",  // message namespace
  "Custom",  // message name
  3,  // number of fields
  sizeof(turtle_msg__msg__Custom),
  Custom__rosidl_typesupport_introspection_c__Custom_message_member_array  // message members
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Custom__rosidl_typesupport_introspection_c__Custom_message_type_support_handle = {
  0,
  &Custom__rosidl_typesupport_introspection_c__Custom_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtle_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_msg, msg, Custom)() {
  if (!Custom__rosidl_typesupport_introspection_c__Custom_message_type_support_handle.typesupport_identifier) {
    Custom__rosidl_typesupport_introspection_c__Custom_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Custom__rosidl_typesupport_introspection_c__Custom_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
