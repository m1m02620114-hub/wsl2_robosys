// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robosys:srv/Name.idl
// generated code does not contain a copyright notice

#ifndef ROBOSYS__SRV__DETAIL__NAME__BUILDER_HPP_
#define ROBOSYS__SRV__DETAIL__NAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robosys/srv/detail/name__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robosys
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
  ::robosys::srv::Name_Request name(::robosys::srv::Name_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robosys::srv::Name_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robosys::srv::Name_Request>()
{
  return robosys::srv::builder::Init_Name_Request_name();
}

}  // namespace robosys


namespace robosys
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
  ::robosys::srv::Name_Response response(::robosys::srv::Name_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robosys::srv::Name_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robosys::srv::Name_Response>()
{
  return robosys::srv::builder::Init_Name_Response_response();
}

}  // namespace robosys

#endif  // ROBOSYS__SRV__DETAIL__NAME__BUILDER_HPP_
