// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robosys:srv/Name.idl
// generated code does not contain a copyright notice

#ifndef ROBOSYS__SRV__DETAIL__NAME__STRUCT_H_
#define ROBOSYS__SRV__DETAIL__NAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "robosys/msg/detail/string__struct.h"

/// Struct defined in srv/Name in the package robosys.
typedef struct robosys__srv__Name_Request
{
  robosys__msg__String name;
} robosys__srv__Name_Request;

// Struct for a sequence of robosys__srv__Name_Request.
typedef struct robosys__srv__Name_Request__Sequence
{
  robosys__srv__Name_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robosys__srv__Name_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
// already included above
// #include "robosys/msg/detail/string__struct.h"

/// Struct defined in srv/Name in the package robosys.
typedef struct robosys__srv__Name_Response
{
  robosys__msg__String response;
} robosys__srv__Name_Response;

// Struct for a sequence of robosys__srv__Name_Response.
typedef struct robosys__srv__Name_Response__Sequence
{
  robosys__srv__Name_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robosys__srv__Name_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOSYS__SRV__DETAIL__NAME__STRUCT_H_
