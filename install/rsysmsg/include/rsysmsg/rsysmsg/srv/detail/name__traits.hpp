// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rsysmsg:srv/Name.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__SRV__DETAIL__NAME__TRAITS_HPP_
#define RSYSMSG__SRV__DETAIL__NAME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rsysmsg/srv/detail/name__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rsysmsg
{

namespace srv
{

inline void to_flow_style_yaml(
  const Name_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Name_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Name_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rsysmsg

namespace rosidl_generator_traits
{

[[deprecated("use rsysmsg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rsysmsg::srv::Name_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rsysmsg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rsysmsg::srv::to_yaml() instead")]]
inline std::string to_yaml(const rsysmsg::srv::Name_Request & msg)
{
  return rsysmsg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rsysmsg::srv::Name_Request>()
{
  return "rsysmsg::srv::Name_Request";
}

template<>
inline const char * name<rsysmsg::srv::Name_Request>()
{
  return "rsysmsg/srv/Name_Request";
}

template<>
struct has_fixed_size<rsysmsg::srv::Name_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rsysmsg::srv::Name_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rsysmsg::srv::Name_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rsysmsg
{

namespace srv
{

inline void to_flow_style_yaml(
  const Name_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Name_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Name_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rsysmsg

namespace rosidl_generator_traits
{

[[deprecated("use rsysmsg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rsysmsg::srv::Name_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rsysmsg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rsysmsg::srv::to_yaml() instead")]]
inline std::string to_yaml(const rsysmsg::srv::Name_Response & msg)
{
  return rsysmsg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rsysmsg::srv::Name_Response>()
{
  return "rsysmsg::srv::Name_Response";
}

template<>
inline const char * name<rsysmsg::srv::Name_Response>()
{
  return "rsysmsg/srv/Name_Response";
}

template<>
struct has_fixed_size<rsysmsg::srv::Name_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rsysmsg::srv::Name_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rsysmsg::srv::Name_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rsysmsg::srv::Name>()
{
  return "rsysmsg::srv::Name";
}

template<>
inline const char * name<rsysmsg::srv::Name>()
{
  return "rsysmsg/srv/Name";
}

template<>
struct has_fixed_size<rsysmsg::srv::Name>
  : std::integral_constant<
    bool,
    has_fixed_size<rsysmsg::srv::Name_Request>::value &&
    has_fixed_size<rsysmsg::srv::Name_Response>::value
  >
{
};

template<>
struct has_bounded_size<rsysmsg::srv::Name>
  : std::integral_constant<
    bool,
    has_bounded_size<rsysmsg::srv::Name_Request>::value &&
    has_bounded_size<rsysmsg::srv::Name_Response>::value
  >
{
};

template<>
struct is_service<rsysmsg::srv::Name>
  : std::true_type
{
};

template<>
struct is_service_request<rsysmsg::srv::Name_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rsysmsg::srv::Name_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RSYSMSG__SRV__DETAIL__NAME__TRAITS_HPP_
