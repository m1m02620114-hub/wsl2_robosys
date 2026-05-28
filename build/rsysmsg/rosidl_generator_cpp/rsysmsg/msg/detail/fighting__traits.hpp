// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__MSG__DETAIL__FIGHTING__TRAITS_HPP_
#define RSYSMSG__MSG__DETAIL__FIGHTING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rsysmsg/msg/detail/fighting__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rsysmsg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Fighting & msg,
  std::ostream & out)
{
  out << "{";
  // member: pone
  {
    if (msg.pone.size() == 0) {
      out << "pone: []";
    } else {
      out << "pone: [";
      size_t pending_items = msg.pone.size();
      for (auto item : msg.pone) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: ptwo
  {
    if (msg.ptwo.size() == 0) {
      out << "ptwo: []";
    } else {
      out << "ptwo: [";
      size_t pending_items = msg.ptwo.size();
      for (auto item : msg.ptwo) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Fighting & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pone
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pone.size() == 0) {
      out << "pone: []\n";
    } else {
      out << "pone:\n";
      for (auto item : msg.pone) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: ptwo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ptwo.size() == 0) {
      out << "ptwo: []\n";
    } else {
      out << "ptwo:\n";
      for (auto item : msg.ptwo) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Fighting & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rsysmsg

namespace rosidl_generator_traits
{

[[deprecated("use rsysmsg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rsysmsg::msg::Fighting & msg,
  std::ostream & out, size_t indentation = 0)
{
  rsysmsg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rsysmsg::msg::to_yaml() instead")]]
inline std::string to_yaml(const rsysmsg::msg::Fighting & msg)
{
  return rsysmsg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rsysmsg::msg::Fighting>()
{
  return "rsysmsg::msg::Fighting";
}

template<>
inline const char * name<rsysmsg::msg::Fighting>()
{
  return "rsysmsg/msg/Fighting";
}

template<>
struct has_fixed_size<rsysmsg::msg::Fighting>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rsysmsg::msg::Fighting>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rsysmsg::msg::Fighting>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RSYSMSG__MSG__DETAIL__FIGHTING__TRAITS_HPP_
