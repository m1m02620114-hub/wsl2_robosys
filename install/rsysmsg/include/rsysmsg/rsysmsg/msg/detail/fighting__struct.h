// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__MSG__DETAIL__FIGHTING__STRUCT_H_
#define RSYSMSG__MSG__DETAIL__FIGHTING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pone'
// Member 'ptwo'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Fighting in the package rsysmsg.
typedef struct rsysmsg__msg__Fighting
{
  rosidl_runtime_c__int32__Sequence pone;
  rosidl_runtime_c__int32__Sequence ptwo;
} rsysmsg__msg__Fighting;

// Struct for a sequence of rsysmsg__msg__Fighting.
typedef struct rsysmsg__msg__Fighting__Sequence
{
  rsysmsg__msg__Fighting * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__msg__Fighting__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RSYSMSG__MSG__DETAIL__FIGHTING__STRUCT_H_
