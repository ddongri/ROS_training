// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_msg:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_MSG__MSG__CUSTOM__STRUCT_H_
#define TURTLE_MSG__MSG__CUSTOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Custom in the package turtle_msg.
typedef struct turtle_msg__msg__Custom
{
  float radius;
  float velocity;
  int64_t direction;
} turtle_msg__msg__Custom;

// Struct for a sequence of turtle_msg__msg__Custom.
typedef struct turtle_msg__msg__Custom__Sequence
{
  turtle_msg__msg__Custom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_msg__msg__Custom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_MSG__MSG__CUSTOM__STRUCT_H_
