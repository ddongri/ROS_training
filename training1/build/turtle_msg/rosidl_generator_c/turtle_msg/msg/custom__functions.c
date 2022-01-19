// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtle_msg:msg/Custom.idl
// generated code does not contain a copyright notice
#include "turtle_msg/msg/custom__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
turtle_msg__msg__Custom__init(turtle_msg__msg__Custom * msg)
{
  if (!msg) {
    return false;
  }
  // radius
  // velocity
  // direction
  return true;
}

void
turtle_msg__msg__Custom__fini(turtle_msg__msg__Custom * msg)
{
  if (!msg) {
    return;
  }
  // radius
  // velocity
  // direction
}

turtle_msg__msg__Custom *
turtle_msg__msg__Custom__create()
{
  turtle_msg__msg__Custom * msg = (turtle_msg__msg__Custom *)malloc(sizeof(turtle_msg__msg__Custom));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_msg__msg__Custom));
  bool success = turtle_msg__msg__Custom__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
turtle_msg__msg__Custom__destroy(turtle_msg__msg__Custom * msg)
{
  if (msg) {
    turtle_msg__msg__Custom__fini(msg);
  }
  free(msg);
}


bool
turtle_msg__msg__Custom__Sequence__init(turtle_msg__msg__Custom__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  turtle_msg__msg__Custom * data = NULL;
  if (size) {
    data = (turtle_msg__msg__Custom *)calloc(size, sizeof(turtle_msg__msg__Custom));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_msg__msg__Custom__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_msg__msg__Custom__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_msg__msg__Custom__Sequence__fini(turtle_msg__msg__Custom__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_msg__msg__Custom__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_msg__msg__Custom__Sequence *
turtle_msg__msg__Custom__Sequence__create(size_t size)
{
  turtle_msg__msg__Custom__Sequence * array = (turtle_msg__msg__Custom__Sequence *)malloc(sizeof(turtle_msg__msg__Custom__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = turtle_msg__msg__Custom__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
turtle_msg__msg__Custom__Sequence__destroy(turtle_msg__msg__Custom__Sequence * array)
{
  if (array) {
    turtle_msg__msg__Custom__Sequence__fini(array);
  }
  free(array);
}
