// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__MSG__DETAIL__FIGHTING__BUILDER_HPP_
#define RSYSMSG__MSG__DETAIL__FIGHTING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rsysmsg/msg/detail/fighting__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rsysmsg
{

namespace msg
{

namespace builder
{

class Init_Fighting_ptwo
{
public:
  explicit Init_Fighting_ptwo(::rsysmsg::msg::Fighting & msg)
  : msg_(msg)
  {}
  ::rsysmsg::msg::Fighting ptwo(::rsysmsg::msg::Fighting::_ptwo_type arg)
  {
    msg_.ptwo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::msg::Fighting msg_;
};

class Init_Fighting_pone
{
public:
  Init_Fighting_pone()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fighting_ptwo pone(::rsysmsg::msg::Fighting::_pone_type arg)
  {
    msg_.pone = std::move(arg);
    return Init_Fighting_ptwo(msg_);
  }

private:
  ::rsysmsg::msg::Fighting msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::msg::Fighting>()
{
  return rsysmsg::msg::builder::Init_Fighting_pone();
}

}  // namespace rsysmsg

#endif  // RSYSMSG__MSG__DETAIL__FIGHTING__BUILDER_HPP_
