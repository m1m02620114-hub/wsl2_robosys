// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__MSG__DETAIL__FIGHTING__STRUCT_HPP_
#define RSYSMSG__MSG__DETAIL__FIGHTING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rsysmsg__msg__Fighting __attribute__((deprecated))
#else
# define DEPRECATED__rsysmsg__msg__Fighting __declspec(deprecated)
#endif

namespace rsysmsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Fighting_
{
  using Type = Fighting_<ContainerAllocator>;

  explicit Fighting_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Fighting_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _pone_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _pone_type pone;
  using _ptwo_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _ptwo_type ptwo;

  // setters for named parameter idiom
  Type & set__pone(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->pone = _arg;
    return *this;
  }
  Type & set__ptwo(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->ptwo = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rsysmsg::msg::Fighting_<ContainerAllocator> *;
  using ConstRawPtr =
    const rsysmsg::msg::Fighting_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rsysmsg::msg::Fighting_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rsysmsg::msg::Fighting_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rsysmsg::msg::Fighting_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::msg::Fighting_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rsysmsg::msg::Fighting_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rsysmsg::msg::Fighting_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rsysmsg::msg::Fighting_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rsysmsg::msg::Fighting_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rsysmsg__msg__Fighting
    std::shared_ptr<rsysmsg::msg::Fighting_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rsysmsg__msg__Fighting
    std::shared_ptr<rsysmsg::msg::Fighting_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Fighting_ & other) const
  {
    if (this->pone != other.pone) {
      return false;
    }
    if (this->ptwo != other.ptwo) {
      return false;
    }
    return true;
  }
  bool operator!=(const Fighting_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Fighting_

// alias to use template instance with default allocator
using Fighting =
  rsysmsg::msg::Fighting_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rsysmsg

#endif  // RSYSMSG__MSG__DETAIL__FIGHTING__STRUCT_HPP_
