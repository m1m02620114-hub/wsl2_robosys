// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rsysmsg:srv/Name.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__SRV__DETAIL__NAME__BUILDER_HPP_
#define RSYSMSG__SRV__DETAIL__NAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rsysmsg/srv/detail/name__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rsysmsg
{

namespace srv
{

namespace builder
{

class Init_Name_Request_name
{
public:
  Init_Name_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rsysmsg::srv::Name_Request name(::rsysmsg::srv::Name_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::srv::Name_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::srv::Name_Request>()
{
  return rsysmsg::srv::builder::Init_Name_Request_name();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace srv
{

namespace builder
{

class Init_Name_Response_response
{
public:
  Init_Name_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rsysmsg::srv::Name_Response response(::rsysmsg::srv::Name_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::srv::Name_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::srv::Name_Response>()
{
  return rsysmsg::srv::builder::Init_Name_Response_response();
}

}  // namespace rsysmsg

#endif  // RSYSMSG__SRV__DETAIL__NAME__BUILDER_HPP_
