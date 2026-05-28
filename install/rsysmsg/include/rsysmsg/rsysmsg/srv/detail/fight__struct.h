// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rsysmsg:srv/Fight.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__SRV__DETAIL__FIGHT__STRUCT_H_
#define RSYSMSG__SRV__DETAIL__FIGHT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/Fight in the package rsysmsg.
typedef struct rsysmsg__srv__Fight_Request
{
  rosidl_runtime_c__int32__Sequence status;
  int32_t id;
} rsysmsg__srv__Fight_Request;

// Struct for a sequence of rsysmsg__srv__Fight_Request.
typedef struct rsysmsg__srv__Fight_Request__Sequence
{
  rsysmsg__srv__Fight_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__srv__Fight_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'res'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Fight in the package rsysmsg.
typedef struct rsysmsg__srv__Fight_Response
{
  rosidl_runtime_c__String res;
  int32_t reid;
} rsysmsg__srv__Fight_Response;

// Struct for a sequence of rsysmsg__srv__Fight_Response.
typedef struct rsysmsg__srv__Fight_Response__Sequence
{
  rsysmsg__srv__Fight_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__srv__Fight_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RSYSMSG__SRV__DETAIL__FIGHT__STRUCT_H_
