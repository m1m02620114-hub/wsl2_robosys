// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rsysmsg:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__MSG__DETAIL__NUM__BUILDER_HPP_
#define RSYSMSG__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rsysmsg/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rsysmsg
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rsysmsg::msg::Num num(::rsysmsg::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::msg::Num>()
{
  return rsysmsg::msg::builder::Init_Num_num();
}

}  // namespace rsysmsg

#endif  // RSYSMSG__MSG__DETAIL__NUM__BUILDER_HPP_
