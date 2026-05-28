// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rsysmsg/msg/detail/fighting__rosidl_typesupport_introspection_c.h"
#include "rsysmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rsysmsg/msg/detail/fighting__functions.h"
#include "rsysmsg/msg/detail/fighting__struct.h"


// Include directives for member types
// Member `pone`
// Member `ptwo`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rsysmsg__msg__Fighting__init(message_memory);
}

void rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_fini_function(void * message_memory)
{
  rsysmsg__msg__Fighting__fini(message_memory);
}

size_t rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__size_function__Fighting__pone(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_const_function__Fighting__pone(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_function__Fighting__pone(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__fetch_function__Fighting__pone(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_const_function__Fighting__pone(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__assign_function__Fighting__pone(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_function__Fighting__pone(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__resize_function__Fighting__pone(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__size_function__Fighting__ptwo(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_const_function__Fighting__ptwo(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_function__Fighting__ptwo(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__fetch_function__Fighting__ptwo(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_const_function__Fighting__ptwo(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__assign_function__Fighting__ptwo(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_function__Fighting__ptwo(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__resize_function__Fighting__ptwo(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_message_member_array[2] = {
  {
    "pone",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rsysmsg__msg__Fighting, pone),  // bytes offset in struct
    NULL,  // default value
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__size_function__Fighting__pone,  // size() function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_const_function__Fighting__pone,  // get_const(index) function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_function__Fighting__pone,  // get(index) function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__fetch_function__Fighting__pone,  // fetch(index, &value) function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__assign_function__Fighting__pone,  // assign(index, value) function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__resize_function__Fighting__pone  // resize(index) function pointer
  },
  {
    "ptwo",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rsysmsg__msg__Fighting, ptwo),  // bytes offset in struct
    NULL,  // default value
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__size_function__Fighting__ptwo,  // size() function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_const_function__Fighting__ptwo,  // get_const(index) function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__get_function__Fighting__ptwo,  // get(index) function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__fetch_function__Fighting__ptwo,  // fetch(index, &value) function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__assign_function__Fighting__ptwo,  // assign(index, value) function pointer
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__resize_function__Fighting__ptwo  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_message_members = {
  "rsysmsg__msg",  // message namespace
  "Fighting",  // message name
  2,  // number of fields
  sizeof(rsysmsg__msg__Fighting),
  rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_message_member_array,  // message members
  rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_init_function,  // function to initialize message memory (memory has to be allocated)
  rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_message_type_support_handle = {
  0,
  &rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rsysmsg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rsysmsg, msg, Fighting)() {
  if (!rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_message_type_support_handle.typesupport_identifier) {
    rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rsysmsg__msg__Fighting__rosidl_typesupport_introspection_c__Fighting_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
