// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_msg:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_MSG__MSG__CUSTOM__FUNCTIONS_H_
#define TURTLE_MSG__MSG__CUSTOM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_generator_c/visibility_control.h"
#include "turtle_msg/msg/rosidl_generator_c__visibility_control.h"

#include "turtle_msg/msg/custom__struct.h"

/// Initialize msg/Custom message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turtle_msg__msg__Custom
 * )) before or use
 * turtle_msg__msg__Custom__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turtle_msg
bool
turtle_msg__msg__Custom__init(turtle_msg__msg__Custom * msg);

/// Finalize msg/Custom message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtle_msg
void
turtle_msg__msg__Custom__fini(turtle_msg__msg__Custom * msg);

/// Create msg/Custom message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turtle_msg__msg__Custom__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtle_msg
turtle_msg__msg__Custom *
turtle_msg__msg__Custom__create();

/// Destroy msg/Custom message.
/**
 * It calls
 * turtle_msg__msg__Custom__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtle_msg
void
turtle_msg__msg__Custom__destroy(turtle_msg__msg__Custom * msg);


/// Initialize array of msg/Custom messages.
/**
 * It allocates the memory for the number of elements and calls
 * turtle_msg__msg__Custom__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtle_msg
bool
turtle_msg__msg__Custom__Sequence__init(turtle_msg__msg__Custom__Sequence * array, size_t size);

/// Finalize array of msg/Custom messages.
/**
 * It calls
 * turtle_msg__msg__Custom__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtle_msg
void
turtle_msg__msg__Custom__Sequence__fini(turtle_msg__msg__Custom__Sequence * array);

/// Create array of msg/Custom messages.
/**
 * It allocates the memory for the array and calls
 * turtle_msg__msg__Custom__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtle_msg
turtle_msg__msg__Custom__Sequence *
turtle_msg__msg__Custom__Sequence__create(size_t size);

/// Destroy array of msg/Custom messages.
/**
 * It calls
 * turtle_msg__msg__Custom__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtle_msg
void
turtle_msg__msg__Custom__Sequence__destroy(turtle_msg__msg__Custom__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_MSG__MSG__CUSTOM__FUNCTIONS_H_
