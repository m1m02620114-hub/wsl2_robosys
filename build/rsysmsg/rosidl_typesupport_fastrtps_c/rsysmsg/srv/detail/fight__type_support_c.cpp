// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rsysmsg:srv/Fight.idl
// generated code does not contain a copyright notice
#include "rsysmsg/srv/detail/fight__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rsysmsg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rsysmsg/srv/detail/fight__struct.h"
#include "rsysmsg/srv/detail/fight__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // status
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // status

// forward declare type support functions


using _Fight_Request__ros_msg_type = rsysmsg__srv__Fight_Request;

static bool _Fight_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Fight_Request__ros_msg_type * ros_message = static_cast<const _Fight_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    size_t size = ros_message->status.size;
    auto array_ptr = ros_message->status.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: id
  {
    cdr << ros_message->id;
  }

  return true;
}

static bool _Fight_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Fight_Request__ros_msg_type * ros_message = static_cast<_Fight_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->status.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->status);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->status, size)) {
      fprintf(stderr, "failed to create array for field 'status'");
      return false;
    }
    auto array_ptr = ros_message->status.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: id
  {
    cdr >> ros_message->id;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rsysmsg
size_t get_serialized_size_rsysmsg__srv__Fight_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Fight_Request__ros_msg_type * ros_message = static_cast<const _Fight_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name status
  {
    size_t array_size = ros_message->status.size;
    auto array_ptr = ros_message->status.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name id
  {
    size_t item_size = sizeof(ros_message->id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Fight_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rsysmsg__srv__Fight_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rsysmsg
size_t max_serialized_size_rsysmsg__srv__Fight_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: status
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rsysmsg__srv__Fight_Request;
    is_plain =
      (
      offsetof(DataType, id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Fight_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rsysmsg__srv__Fight_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Fight_Request = {
  "rsysmsg::srv",
  "Fight_Request",
  _Fight_Request__cdr_serialize,
  _Fight_Request__cdr_deserialize,
  _Fight_Request__get_serialized_size,
  _Fight_Request__max_serialized_size
};

static rosidl_message_type_support_t _Fight_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Fight_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rsysmsg, srv, Fight_Request)() {
  return &_Fight_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rsysmsg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "rsysmsg/srv/detail/fight__struct.h"
// already included above
// #include "rsysmsg/srv/detail/fight__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // res
#include "rosidl_runtime_c/string_functions.h"  // res

// forward declare type support functions


using _Fight_Response__ros_msg_type = rsysmsg__srv__Fight_Response;

static bool _Fight_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Fight_Response__ros_msg_type * ros_message = static_cast<const _Fight_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: res
  {
    const rosidl_runtime_c__String * str = &ros_message->res;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: reid
  {
    cdr << ros_message->reid;
  }

  return true;
}

static bool _Fight_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Fight_Response__ros_msg_type * ros_message = static_cast<_Fight_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: res
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->res.data) {
      rosidl_runtime_c__String__init(&ros_message->res);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->res,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'res'\n");
      return false;
    }
  }

  // Field name: reid
  {
    cdr >> ros_message->reid;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rsysmsg
size_t get_serialized_size_rsysmsg__srv__Fight_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Fight_Response__ros_msg_type * ros_message = static_cast<const _Fight_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name res
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->res.size + 1);
  // field.name reid
  {
    size_t item_size = sizeof(ros_message->reid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Fight_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rsysmsg__srv__Fight_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rsysmsg
size_t max_serialized_size_rsysmsg__srv__Fight_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: res
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: reid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rsysmsg__srv__Fight_Response;
    is_plain =
      (
      offsetof(DataType, reid) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Fight_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rsysmsg__srv__Fight_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Fight_Response = {
  "rsysmsg::srv",
  "Fight_Response",
  _Fight_Response__cdr_serialize,
  _Fight_Response__cdr_deserialize,
  _Fight_Response__get_serialized_size,
  _Fight_Response__max_serialized_size
};

static rosidl_message_type_support_t _Fight_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Fight_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rsysmsg, srv, Fight_Response)() {
  return &_Fight_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rsysmsg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rsysmsg/srv/fight.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Fight__callbacks = {
  "rsysmsg::srv",
  "Fight",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rsysmsg, srv, Fight_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rsysmsg, srv, Fight_Response)(),
};

static rosidl_service_type_support_t Fight__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Fight__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rsysmsg, srv, Fight)() {
  return &Fight__handle;
}

#if defined(__cplusplus)
}
#endif
