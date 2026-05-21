// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rsysmsg:action/Monster.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__ACTION__DETAIL__MONSTER__STRUCT_H_
#define RSYSMSG__ACTION__DETAIL__MONSTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'order'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Monster in the package rsysmsg.
typedef struct rsysmsg__action__Monster_Goal
{
  rosidl_runtime_c__String order;
} rsysmsg__action__Monster_Goal;

// Struct for a sequence of rsysmsg__action__Monster_Goal.
typedef struct rsysmsg__action__Monster_Goal__Sequence
{
  rsysmsg__action__Monster_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__action__Monster_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Monster in the package rsysmsg.
typedef struct rsysmsg__action__Monster_Result
{
  int32_t result;
} rsysmsg__action__Monster_Result;

// Struct for a sequence of rsysmsg__action__Monster_Result.
typedef struct rsysmsg__action__Monster_Result__Sequence
{
  rsysmsg__action__Monster_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__action__Monster_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Monster in the package rsysmsg.
typedef struct rsysmsg__action__Monster_Feedback
{
  int32_t feedback;
} rsysmsg__action__Monster_Feedback;

// Struct for a sequence of rsysmsg__action__Monster_Feedback.
typedef struct rsysmsg__action__Monster_Feedback__Sequence
{
  rsysmsg__action__Monster_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__action__Monster_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "rsysmsg/action/detail/monster__struct.h"

/// Struct defined in action/Monster in the package rsysmsg.
typedef struct rsysmsg__action__Monster_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  rsysmsg__action__Monster_Goal goal;
} rsysmsg__action__Monster_SendGoal_Request;

// Struct for a sequence of rsysmsg__action__Monster_SendGoal_Request.
typedef struct rsysmsg__action__Monster_SendGoal_Request__Sequence
{
  rsysmsg__action__Monster_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__action__Monster_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Monster in the package rsysmsg.
typedef struct rsysmsg__action__Monster_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} rsysmsg__action__Monster_SendGoal_Response;

// Struct for a sequence of rsysmsg__action__Monster_SendGoal_Response.
typedef struct rsysmsg__action__Monster_SendGoal_Response__Sequence
{
  rsysmsg__action__Monster_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__action__Monster_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Monster in the package rsysmsg.
typedef struct rsysmsg__action__Monster_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} rsysmsg__action__Monster_GetResult_Request;

// Struct for a sequence of rsysmsg__action__Monster_GetResult_Request.
typedef struct rsysmsg__action__Monster_GetResult_Request__Sequence
{
  rsysmsg__action__Monster_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__action__Monster_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rsysmsg/action/detail/monster__struct.h"

/// Struct defined in action/Monster in the package rsysmsg.
typedef struct rsysmsg__action__Monster_GetResult_Response
{
  int8_t status;
  rsysmsg__action__Monster_Result result;
} rsysmsg__action__Monster_GetResult_Response;

// Struct for a sequence of rsysmsg__action__Monster_GetResult_Response.
typedef struct rsysmsg__action__Monster_GetResult_Response__Sequence
{
  rsysmsg__action__Monster_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__action__Monster_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "rsysmsg/action/detail/monster__struct.h"

/// Struct defined in action/Monster in the package rsysmsg.
typedef struct rsysmsg__action__Monster_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  rsysmsg__action__Monster_Feedback feedback;
} rsysmsg__action__Monster_FeedbackMessage;

// Struct for a sequence of rsysmsg__action__Monster_FeedbackMessage.
typedef struct rsysmsg__action__Monster_FeedbackMessage__Sequence
{
  rsysmsg__action__Monster_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rsysmsg__action__Monster_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RSYSMSG__ACTION__DETAIL__MONSTER__STRUCT_H_
