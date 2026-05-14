// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robosys:srv/Name.idl
// generated code does not contain a copyright notice

#ifndef ROBOSYS__SRV__DETAIL__NAME__STRUCT_HPP_
#define ROBOSYS__SRV__DETAIL__NAME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'name'
#include "robosys/msg/detail/string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robosys__srv__Name_Request __attribute__((deprecated))
#else
# define DEPRECATED__robosys__srv__Name_Request __declspec(deprecated)
#endif

namespace robosys
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Name_Request_
{
  using Type = Name_Request_<ContainerAllocator>;

  explicit Name_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_init)
  {
    (void)_init;
  }

  explicit Name_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _name_type =
    robosys::msg::String_<ContainerAllocator>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__name(
    const robosys::msg::String_<ContainerAllocator> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robosys::srv::Name_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robosys::srv::Name_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robosys::srv::Name_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robosys::srv::Name_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robosys::srv::Name_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robosys::srv::Name_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robosys::srv::Name_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robosys::srv::Name_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robosys::srv::Name_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robosys::srv::Name_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robosys__srv__Name_Request
    std::shared_ptr<robosys::srv::Name_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robosys__srv__Name_Request
    std::shared_ptr<robosys::srv::Name_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Name_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const Name_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Name_Request_

// alias to use template instance with default allocator
using Name_Request =
  robosys::srv::Name_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robosys


// Include directives for member types
// Member 'response'
// already included above
// #include "robosys/msg/detail/string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robosys__srv__Name_Response __attribute__((deprecated))
#else
# define DEPRECATED__robosys__srv__Name_Response __declspec(deprecated)
#endif

namespace robosys
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Name_Response_
{
  using Type = Name_Response_<ContainerAllocator>;

  explicit Name_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_init)
  {
    (void)_init;
  }

  explicit Name_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _response_type =
    robosys::msg::String_<ContainerAllocator>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const robosys::msg::String_<ContainerAllocator> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robosys::srv::Name_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robosys::srv::Name_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robosys::srv::Name_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robosys::srv::Name_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robosys::srv::Name_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robosys::srv::Name_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robosys::srv::Name_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robosys::srv::Name_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robosys::srv::Name_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robosys::srv::Name_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robosys__srv__Name_Response
    std::shared_ptr<robosys::srv::Name_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robosys__srv__Name_Response
    std::shared_ptr<robosys::srv::Name_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Name_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Name_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Name_Response_

// alias to use template instance with default allocator
using Name_Response =
  robosys::srv::Name_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robosys

namespace robosys
{

namespace srv
{

struct Name
{
  using Request = robosys::srv::Name_Request;
  using Response = robosys::srv::Name_Response;
};

}  // namespace srv

}  // namespace robosys

#endif  // ROBOSYS__SRV__DETAIL__NAME__STRUCT_HPP_
