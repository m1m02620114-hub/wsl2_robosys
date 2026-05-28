// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rsysmsg:srv/Fight.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__SRV__DETAIL__FIGHT__STRUCT_HPP_
#define RSYSMSG__SRV__DETAIL__FIGHT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rsysmsg__srv__Fight_Request __attribute__((deprecated))
#else
# define DEPRECATED__rsysmsg__srv__Fight_Request __declspec(deprecated)
#endif

namespace rsysmsg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Fight_Request_
{
  using Type = Fight_Request_<ContainerAllocator>;

  explicit Fight_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  explicit Fight_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  // field types and members
  using _status_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _status_type status;
  using _id_type =
    int32_t;
  _id_type id;

  // setters for named parameter idiom
  Type & set__status(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rsysmsg::srv::Fight_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rsysmsg::srv::Fight_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rsysmsg::srv::Fight_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rsysmsg::srv::Fight_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rsysmsg::srv::Fight_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::srv::Fight_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rsysmsg::srv::Fight_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::srv::Fight_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rsysmsg::srv::Fight_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rsysmsg::srv::Fight_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rsysmsg__srv__Fight_Request
    std::shared_ptr<rsysmsg::srv::Fight_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rsysmsg__srv__Fight_Request
    std::shared_ptr<rsysmsg::srv::Fight_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Fight_Request_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Fight_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Fight_Request_

// alias to use template instance with default allocator
using Fight_Request =
  rsysmsg::srv::Fight_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rsysmsg


#ifndef _WIN32
# define DEPRECATED__rsysmsg__srv__Fight_Response __attribute__((deprecated))
#else
# define DEPRECATED__rsysmsg__srv__Fight_Response __declspec(deprecated)
#endif

namespace rsysmsg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Fight_Response_
{
  using Type = Fight_Response_<ContainerAllocator>;

  explicit Fight_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = "";
      this->reid = 0l;
    }
  }

  explicit Fight_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : res(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = "";
      this->reid = 0l;
    }
  }

  // field types and members
  using _res_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _res_type res;
  using _reid_type =
    int32_t;
  _reid_type reid;

  // setters for named parameter idiom
  Type & set__res(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->res = _arg;
    return *this;
  }
  Type & set__reid(
    const int32_t & _arg)
  {
    this->reid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rsysmsg::srv::Fight_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rsysmsg::srv::Fight_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rsysmsg::srv::Fight_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rsysmsg::srv::Fight_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rsysmsg::srv::Fight_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::srv::Fight_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rsysmsg::srv::Fight_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::srv::Fight_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rsysmsg::srv::Fight_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rsysmsg::srv::Fight_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rsysmsg__srv__Fight_Response
    std::shared_ptr<rsysmsg::srv::Fight_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rsysmsg__srv__Fight_Response
    std::shared_ptr<rsysmsg::srv::Fight_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Fight_Response_ & other) const
  {
    if (this->res != other.res) {
      return false;
    }
    if (this->reid != other.reid) {
      return false;
    }
    return true;
  }
  bool operator!=(const Fight_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Fight_Response_

// alias to use template instance with default allocator
using Fight_Response =
  rsysmsg::srv::Fight_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rsysmsg

namespace rsysmsg
{

namespace srv
{

struct Fight
{
  using Request = rsysmsg::srv::Fight_Request;
  using Response = rsysmsg::srv::Fight_Response;
};

}  // namespace srv

}  // namespace rsysmsg

#endif  // RSYSMSG__SRV__DETAIL__FIGHT__STRUCT_HPP_
