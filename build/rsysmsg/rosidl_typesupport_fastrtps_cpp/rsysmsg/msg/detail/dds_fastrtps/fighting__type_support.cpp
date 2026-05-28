// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice
#include "rsysmsg/msg/detail/fighting__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rsysmsg/msg/detail/fighting__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rsysmsg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rsysmsg
cdr_serialize(
  const rsysmsg::msg::Fighting & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pone
  {
    cdr << ros_message.pone;
  }
  // Member: ptwo
  {
    cdr << ros_message.ptwo;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rsysmsg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rsysmsg::msg::Fighting & ros_message)
{
  // Member: pone
  {
    cdr >> ros_message.pone;
  }

  // Member: ptwo
  {
    cdr >> ros_message.ptwo;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rsysmsg
get_serialized_size(
  const rsysmsg::msg::Fighting & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pone
  {
    size_t array_size = ros_message.pone.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.pone[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ptwo
  {
    size_t array_size = ros_message.ptwo.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.ptwo[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rsysmsg
max_serialized_size_Fighting(
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


  // Member: pone
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

  // Member: ptwo
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rsysmsg::msg::Fighting;
    is_plain =
      (
      offsetof(DataType, ptwo) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Fighting__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rsysmsg::msg::Fighting *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Fighting__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rsysmsg::msg::Fighting *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Fighting__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rsysmsg::msg::Fighting *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Fighting__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Fighting(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Fighting__callbacks = {
  "rsysmsg::msg",
  "Fighting",
  _Fighting__cdr_serialize,
  _Fighting__cdr_deserialize,
  _Fighting__get_serialized_size,
  _Fighting__max_serialized_size
};

static rosidl_message_type_support_t _Fighting__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Fighting__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rsysmsg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rsysmsg
const rosidl_message_type_support_t *
get_message_type_support_handle<rsysmsg::msg::Fighting>()
{
  return &rsysmsg::msg::typesupport_fastrtps_cpp::_Fighting__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rsysmsg, msg, Fighting)() {
  return &rsysmsg::msg::typesupport_fastrtps_cpp::_Fighting__handle;
}

#ifdef __cplusplus
}
#endif
