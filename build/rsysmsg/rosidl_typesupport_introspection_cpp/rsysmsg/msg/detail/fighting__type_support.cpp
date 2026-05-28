// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rsysmsg/msg/detail/fighting__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rsysmsg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Fighting_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rsysmsg::msg::Fighting(_init);
}

void Fighting_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rsysmsg::msg::Fighting *>(message_memory);
  typed_message->~Fighting();
}

size_t size_function__Fighting__pone(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Fighting__pone(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__Fighting__pone(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__Fighting__pone(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__Fighting__pone(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__Fighting__pone(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__Fighting__pone(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__Fighting__pone(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Fighting__ptwo(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Fighting__ptwo(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__Fighting__ptwo(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__Fighting__ptwo(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__Fighting__ptwo(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__Fighting__ptwo(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__Fighting__ptwo(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__Fighting__ptwo(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Fighting_message_member_array[2] = {
  {
    "pone",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rsysmsg::msg::Fighting, pone),  // bytes offset in struct
    nullptr,  // default value
    size_function__Fighting__pone,  // size() function pointer
    get_const_function__Fighting__pone,  // get_const(index) function pointer
    get_function__Fighting__pone,  // get(index) function pointer
    fetch_function__Fighting__pone,  // fetch(index, &value) function pointer
    assign_function__Fighting__pone,  // assign(index, value) function pointer
    resize_function__Fighting__pone  // resize(index) function pointer
  },
  {
    "ptwo",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rsysmsg::msg::Fighting, ptwo),  // bytes offset in struct
    nullptr,  // default value
    size_function__Fighting__ptwo,  // size() function pointer
    get_const_function__Fighting__ptwo,  // get_const(index) function pointer
    get_function__Fighting__ptwo,  // get(index) function pointer
    fetch_function__Fighting__ptwo,  // fetch(index, &value) function pointer
    assign_function__Fighting__ptwo,  // assign(index, value) function pointer
    resize_function__Fighting__ptwo  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Fighting_message_members = {
  "rsysmsg::msg",  // message namespace
  "Fighting",  // message name
  2,  // number of fields
  sizeof(rsysmsg::msg::Fighting),
  Fighting_message_member_array,  // message members
  Fighting_init_function,  // function to initialize message memory (memory has to be allocated)
  Fighting_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Fighting_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Fighting_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rsysmsg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rsysmsg::msg::Fighting>()
{
  return &::rsysmsg::msg::rosidl_typesupport_introspection_cpp::Fighting_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rsysmsg, msg, Fighting)() {
  return &::rsysmsg::msg::rosidl_typesupport_introspection_cpp::Fighting_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
