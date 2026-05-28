// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rsysmsg:srv/Fight.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__SRV__DETAIL__FIGHT__BUILDER_HPP_
#define RSYSMSG__SRV__DETAIL__FIGHT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rsysmsg/srv/detail/fight__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rsysmsg
{

namespace srv
{

namespace builder
{

class Init_Fight_Request_id
{
public:
  explicit Init_Fight_Request_id(::rsysmsg::srv::Fight_Request & msg)
  : msg_(msg)
  {}
  ::rsysmsg::srv::Fight_Request id(::rsysmsg::srv::Fight_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::srv::Fight_Request msg_;
};

class Init_Fight_Request_status
{
public:
  Init_Fight_Request_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fight_Request_id status(::rsysmsg::srv::Fight_Request::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Fight_Request_id(msg_);
  }

private:
  ::rsysmsg::srv::Fight_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::srv::Fight_Request>()
{
  return rsysmsg::srv::builder::Init_Fight_Request_status();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace srv
{

namespace builder
{

class Init_Fight_Response_reid
{
public:
  explicit Init_Fight_Response_reid(::rsysmsg::srv::Fight_Response & msg)
  : msg_(msg)
  {}
  ::rsysmsg::srv::Fight_Response reid(::rsysmsg::srv::Fight_Response::_reid_type arg)
  {
    msg_.reid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::srv::Fight_Response msg_;
};

class Init_Fight_Response_res
{
public:
  Init_Fight_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fight_Response_reid res(::rsysmsg::srv::Fight_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return Init_Fight_Response_reid(msg_);
  }

private:
  ::rsysmsg::srv::Fight_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::srv::Fight_Response>()
{
  return rsysmsg::srv::builder::Init_Fight_Response_res();
}

}  // namespace rsysmsg

#endif  // RSYSMSG__SRV__DETAIL__FIGHT__BUILDER_HPP_
