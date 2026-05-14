// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rsysmsg:srv/Name.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__SRV__DETAIL__NAME__STRUCT_HPP_
#define RSYSMSG__SRV__DETAIL__NAME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rsysmsg__srv__Name_Request __attribute__((deprecated))
#else
# define DEPRECATED__rsysmsg__srv__Name_Request __declspec(deprecated)
#endif

namespace rsysmsg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Name_Request_
{
  using Type = Name_Request_<ContainerAllocator>;

  explicit Name_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit Name_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rsysmsg::srv::Name_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rsysmsg::srv::Name_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rsysmsg::srv::Name_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rsysmsg::srv::Name_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rsysmsg::srv::Name_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::srv::Name_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rsysmsg::srv::Name_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::srv::Name_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rsysmsg::srv::Name_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rsysmsg::srv::Name_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rsysmsg__srv__Name_Request
    std::shared_ptr<rsysmsg::srv::Name_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rsysmsg__srv__Name_Request
    std::shared_ptr<rsysmsg::srv::Name_Request_<ContainerAllocator> const>
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
  rsysmsg::srv::Name_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rsysmsg


#ifndef _WIN32
# define DEPRECATED__rsysmsg__srv__Name_Response __attribute__((deprecated))
#else
# define DEPRECATED__rsysmsg__srv__Name_Response __declspec(deprecated)
#endif

namespace rsysmsg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Name_Response_
{
  using Type = Name_Response_<ContainerAllocator>;

  explicit Name_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  explicit Name_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  // field types and members
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rsysmsg::srv::Name_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rsysmsg::srv::Name_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rsysmsg::srv::Name_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rsysmsg::srv::Name_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rsysmsg::srv::Name_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::srv::Name_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rsysmsg::srv::Name_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::srv::Name_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rsysmsg::srv::Name_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rsysmsg::srv::Name_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rsysmsg__srv__Name_Response
    std::shared_ptr<rsysmsg::srv::Name_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rsysmsg__srv__Name_Response
    std::shared_ptr<rsysmsg::srv::Name_Response_<ContainerAllocator> const>
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
  rsysmsg::srv::Name_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rsysmsg

namespace rsysmsg
{

namespace srv
{

struct Name
{
  using Request = rsysmsg::srv::Name_Request;
  using Response = rsysmsg::srv::Name_Response;
};

}  // namespace srv

}  // namespace rsysmsg

#endif  // RSYSMSG__SRV__DETAIL__NAME__STRUCT_HPP_
