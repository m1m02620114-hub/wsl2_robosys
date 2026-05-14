// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robosys:srv/Name.idl
// generated code does not contain a copyright notice

#ifndef ROBOSYS__SRV__DETAIL__NAME__TRAITS_HPP_
#define ROBOSYS__SRV__DETAIL__NAME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robosys/srv/detail/name__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'name'
#include "robosys/msg/detail/string__traits.hpp"

namespace robosys
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
    to_flow_style_yaml(msg.name, out);
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
    out << "name:\n";
    to_block_style_yaml(msg.name, out, indentation + 2);
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

}  // namespace robosys

namespace rosidl_generator_traits
{

[[deprecated("use robosys::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robosys::srv::Name_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robosys::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robosys::srv::to_yaml() instead")]]
inline std::string to_yaml(const robosys::srv::Name_Request & msg)
{
  return robosys::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robosys::srv::Name_Request>()
{
  return "robosys::srv::Name_Request";
}

template<>
inline const char * name<robosys::srv::Name_Request>()
{
  return "robosys/srv/Name_Request";
}

template<>
struct has_fixed_size<robosys::srv::Name_Request>
  : std::integral_constant<bool, has_fixed_size<robosys::msg::String>::value> {};

template<>
struct has_bounded_size<robosys::srv::Name_Request>
  : std::integral_constant<bool, has_bounded_size<robosys::msg::String>::value> {};

template<>
struct is_message<robosys::srv::Name_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'response'
// already included above
// #include "robosys/msg/detail/string__traits.hpp"

namespace robosys
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
    to_flow_style_yaml(msg.response, out);
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
    out << "response:\n";
    to_block_style_yaml(msg.response, out, indentation + 2);
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

}  // namespace robosys

namespace rosidl_generator_traits
{

[[deprecated("use robosys::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robosys::srv::Name_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robosys::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robosys::srv::to_yaml() instead")]]
inline std::string to_yaml(const robosys::srv::Name_Response & msg)
{
  return robosys::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robosys::srv::Name_Response>()
{
  return "robosys::srv::Name_Response";
}

template<>
inline const char * name<robosys::srv::Name_Response>()
{
  return "robosys/srv/Name_Response";
}

template<>
struct has_fixed_size<robosys::srv::Name_Response>
  : std::integral_constant<bool, has_fixed_size<robosys::msg::String>::value> {};

template<>
struct has_bounded_size<robosys::srv::Name_Response>
  : std::integral_constant<bool, has_bounded_size<robosys::msg::String>::value> {};

template<>
struct is_message<robosys::srv::Name_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robosys::srv::Name>()
{
  return "robosys::srv::Name";
}

template<>
inline const char * name<robosys::srv::Name>()
{
  return "robosys/srv/Name";
}

template<>
struct has_fixed_size<robosys::srv::Name>
  : std::integral_constant<
    bool,
    has_fixed_size<robosys::srv::Name_Request>::value &&
    has_fixed_size<robosys::srv::Name_Response>::value
  >
{
};

template<>
struct has_bounded_size<robosys::srv::Name>
  : std::integral_constant<
    bool,
    has_bounded_size<robosys::srv::Name_Request>::value &&
    has_bounded_size<robosys::srv::Name_Response>::value
  >
{
};

template<>
struct is_service<robosys::srv::Name>
  : std::true_type
{
};

template<>
struct is_service_request<robosys::srv::Name_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robosys::srv::Name_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOSYS__SRV__DETAIL__NAME__TRAITS_HPP_
