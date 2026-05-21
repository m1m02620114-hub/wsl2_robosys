// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rsysmsg:action/Monster.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__ACTION__DETAIL__MONSTER__BUILDER_HPP_
#define RSYSMSG__ACTION__DETAIL__MONSTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rsysmsg/action/detail/monster__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rsysmsg
{

namespace action
{

namespace builder
{

class Init_Monster_Goal_order
{
public:
  Init_Monster_Goal_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rsysmsg::action::Monster_Goal order(::rsysmsg::action::Monster_Goal::_order_type arg)
  {
    msg_.order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::action::Monster_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::action::Monster_Goal>()
{
  return rsysmsg::action::builder::Init_Monster_Goal_order();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace action
{

namespace builder
{

class Init_Monster_Result_result
{
public:
  Init_Monster_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rsysmsg::action::Monster_Result result(::rsysmsg::action::Monster_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::action::Monster_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::action::Monster_Result>()
{
  return rsysmsg::action::builder::Init_Monster_Result_result();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace action
{

namespace builder
{

class Init_Monster_Feedback_feedback
{
public:
  Init_Monster_Feedback_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rsysmsg::action::Monster_Feedback feedback(::rsysmsg::action::Monster_Feedback::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::action::Monster_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::action::Monster_Feedback>()
{
  return rsysmsg::action::builder::Init_Monster_Feedback_feedback();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace action
{

namespace builder
{

class Init_Monster_SendGoal_Request_goal
{
public:
  explicit Init_Monster_SendGoal_Request_goal(::rsysmsg::action::Monster_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::rsysmsg::action::Monster_SendGoal_Request goal(::rsysmsg::action::Monster_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::action::Monster_SendGoal_Request msg_;
};

class Init_Monster_SendGoal_Request_goal_id
{
public:
  Init_Monster_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Monster_SendGoal_Request_goal goal_id(::rsysmsg::action::Monster_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Monster_SendGoal_Request_goal(msg_);
  }

private:
  ::rsysmsg::action::Monster_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::action::Monster_SendGoal_Request>()
{
  return rsysmsg::action::builder::Init_Monster_SendGoal_Request_goal_id();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace action
{

namespace builder
{

class Init_Monster_SendGoal_Response_stamp
{
public:
  explicit Init_Monster_SendGoal_Response_stamp(::rsysmsg::action::Monster_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::rsysmsg::action::Monster_SendGoal_Response stamp(::rsysmsg::action::Monster_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::action::Monster_SendGoal_Response msg_;
};

class Init_Monster_SendGoal_Response_accepted
{
public:
  Init_Monster_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Monster_SendGoal_Response_stamp accepted(::rsysmsg::action::Monster_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Monster_SendGoal_Response_stamp(msg_);
  }

private:
  ::rsysmsg::action::Monster_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::action::Monster_SendGoal_Response>()
{
  return rsysmsg::action::builder::Init_Monster_SendGoal_Response_accepted();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace action
{

namespace builder
{

class Init_Monster_GetResult_Request_goal_id
{
public:
  Init_Monster_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rsysmsg::action::Monster_GetResult_Request goal_id(::rsysmsg::action::Monster_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::action::Monster_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::action::Monster_GetResult_Request>()
{
  return rsysmsg::action::builder::Init_Monster_GetResult_Request_goal_id();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace action
{

namespace builder
{

class Init_Monster_GetResult_Response_result
{
public:
  explicit Init_Monster_GetResult_Response_result(::rsysmsg::action::Monster_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::rsysmsg::action::Monster_GetResult_Response result(::rsysmsg::action::Monster_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::action::Monster_GetResult_Response msg_;
};

class Init_Monster_GetResult_Response_status
{
public:
  Init_Monster_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Monster_GetResult_Response_result status(::rsysmsg::action::Monster_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Monster_GetResult_Response_result(msg_);
  }

private:
  ::rsysmsg::action::Monster_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::action::Monster_GetResult_Response>()
{
  return rsysmsg::action::builder::Init_Monster_GetResult_Response_status();
}

}  // namespace rsysmsg


namespace rsysmsg
{

namespace action
{

namespace builder
{

class Init_Monster_FeedbackMessage_feedback
{
public:
  explicit Init_Monster_FeedbackMessage_feedback(::rsysmsg::action::Monster_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::rsysmsg::action::Monster_FeedbackMessage feedback(::rsysmsg::action::Monster_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rsysmsg::action::Monster_FeedbackMessage msg_;
};

class Init_Monster_FeedbackMessage_goal_id
{
public:
  Init_Monster_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Monster_FeedbackMessage_feedback goal_id(::rsysmsg::action::Monster_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Monster_FeedbackMessage_feedback(msg_);
  }

private:
  ::rsysmsg::action::Monster_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rsysmsg::action::Monster_FeedbackMessage>()
{
  return rsysmsg::action::builder::Init_Monster_FeedbackMessage_goal_id();
}

}  // namespace rsysmsg

#endif  // RSYSMSG__ACTION__DETAIL__MONSTER__BUILDER_HPP_
