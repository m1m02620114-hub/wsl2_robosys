// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rsysmsg:srv/Fight.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rsysmsg/srv/detail/fight__rosidl_typesupport_introspection_c.h"
#include "rsysmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rsysmsg/srv/detail/fight__functions.h"
#include "rsysmsg/srv/detail/fight__struct.h"


// Include directives for member types
// Member `status`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rsysmsg__srv__Fight_Request__init(message_memory);
}

void rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_fini_function(void * message_memory)
{
  rsysmsg__srv__Fight_Request__fini(message_memory);
}

size_t rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__size_function__Fight_Request__status(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__get_const_function__Fight_Request__status(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__get_function__Fight_Request__status(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__fetch_function__Fight_Request__status(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__get_const_function__Fight_Request__status(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__assign_function__Fight_Request__status(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__get_function__Fight_Request__status(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__resize_function__Fight_Request__status(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rsysmsg__srv__Fight_Request, status),  // bytes offset in struct
    NULL,  // default value
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__size_function__Fight_Request__status,  // size() function pointer
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__get_const_function__Fight_Request__status,  // get_const(index) function pointer
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__get_function__Fight_Request__status,  // get(index) function pointer
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__fetch_function__Fight_Request__status,  // fetch(index, &value) function pointer
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__assign_function__Fight_Request__status,  // assign(index, value) function pointer
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__resize_function__Fight_Request__status  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rsysmsg__srv__Fight_Request, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_message_members = {
  "rsysmsg__srv",  // message namespace
  "Fight_Request",  // message name
  2,  // number of fields
  sizeof(rsysmsg__srv__Fight_Request),
  rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_message_member_array,  // message members
  rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_message_type_support_handle = {
  0,
  &rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rsysmsg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rsysmsg, srv, Fight_Request)() {
  if (!rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_message_type_support_handle.typesupport_identifier) {
    rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rsysmsg__srv__Fight_Request__rosidl_typesupport_introspection_c__Fight_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rsysmsg/srv/detail/fight__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rsysmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rsysmsg/srv/detail/fight__functions.h"
// already included above
// #include "rsysmsg/srv/detail/fight__struct.h"


// Include directives for member types
// Member `res`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rsysmsg__srv__Fight_Response__init(message_memory);
}

void rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_fini_function(void * message_memory)
{
  rsysmsg__srv__Fight_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_message_member_array[2] = {
  {
    "res",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rsysmsg__srv__Fight_Response, res),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rsysmsg__srv__Fight_Response, reid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_message_members = {
  "rsysmsg__srv",  // message namespace
  "Fight_Response",  // message name
  2,  // number of fields
  sizeof(rsysmsg__srv__Fight_Response),
  rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_message_member_array,  // message members
  rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_message_type_support_handle = {
  0,
  &rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rsysmsg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rsysmsg, srv, Fight_Response)() {
  if (!rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_message_type_support_handle.typesupport_identifier) {
    rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rsysmsg__srv__Fight_Response__rosidl_typesupport_introspection_c__Fight_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rsysmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rsysmsg/srv/detail/fight__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_service_members = {
  "rsysmsg__srv",  // service namespace
  "Fight",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_Request_message_type_support_handle,
  NULL  // response message
  // rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_Response_message_type_support_handle
};

static rosidl_service_type_support_t rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_service_type_support_handle = {
  0,
  &rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rsysmsg, srv, Fight_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rsysmsg, srv, Fight_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rsysmsg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rsysmsg, srv, Fight)() {
  if (!rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_service_type_support_handle.typesupport_identifier) {
    rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rsysmsg, srv, Fight_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rsysmsg, srv, Fight_Response)()->data;
  }

  return &rsysmsg__srv__detail__fight__rosidl_typesupport_introspection_c__Fight_service_type_support_handle;
}
