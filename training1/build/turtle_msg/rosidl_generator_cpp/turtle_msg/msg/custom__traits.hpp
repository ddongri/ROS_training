// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_msg:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_MSG__MSG__CUSTOM__TRAITS_HPP_
#define TURTLE_MSG__MSG__CUSTOM__TRAITS_HPP_

#include "turtle_msg/msg/custom__struct.hpp"
#include <rosidl_generator_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtle_msg::msg::Custom>()
{
  return "turtle_msg::msg::Custom";
}

template<>
struct has_fixed_size<turtle_msg::msg::Custom>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_msg::msg::Custom>
  : std::integral_constant<bool, true> {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_MSG__MSG__CUSTOM__TRAITS_HPP_
