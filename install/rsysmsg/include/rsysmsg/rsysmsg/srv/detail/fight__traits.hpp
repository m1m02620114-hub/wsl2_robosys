// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rsysmsg:srv/Fight.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__SRV__DETAIL__FIGHT__TRAITS_HPP_
#define RSYSMSG__SRV__DETAIL__FIGHT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rsysmsg/srv/detail/fight__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rsysmsg
{

namespace srv
{

inline void to_flow_style_yaml(
  const Fight_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    if (msg.status.size() == 0) {
      out << "status: []";
    } else {
      out << "status: [";
      size_t pending_items = msg.status.size();
      for (auto item : msg.status) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Fight_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.status.size() == 0) {
      out << "status: []\n";
    } else {
      out << "status:\n";
      for (auto item : msg.status) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Fight_Request & msg, bool use_flow_style = false)
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
  const rsysmsg::srv::Fight_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rsysmsg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rsysmsg::srv::to_yaml() instead")]]
inline std::string to_yaml(const rsysmsg::srv::Fight_Request & msg)
{
  return rsysmsg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rsysmsg::srv::Fight_Request>()
{
  return "rsysmsg::srv::Fight_Request";
}

template<>
inline const char * name<rsysmsg::srv::Fight_Request>()
{
  return "rsysmsg/srv/Fight_Request";
}

template<>
struct has_fixed_size<rsysmsg::srv::Fight_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rsysmsg::srv::Fight_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rsysmsg::srv::Fight_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rsysmsg
{

namespace srv
{

inline void to_flow_style_yaml(
  const Fight_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: res
  {
    out << "res: ";
    rosidl_generator_traits::value_to_yaml(msg.res, out);
    out << ", ";
  }

  // member: reid
  {
    out << "reid: ";
    rosidl_generator_traits::value_to_yaml(msg.reid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Fight_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: res
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "res: ";
    rosidl_generator_traits::value_to_yaml(msg.res, out);
    out << "\n";
  }

  // member: reid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reid: ";
    rosidl_generator_traits::value_to_yaml(msg.reid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Fight_Response & msg, bool use_flow_style = false)
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
  const rsysmsg::srv::Fight_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rsysmsg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rsysmsg::srv::to_yaml() instead")]]
inline std::string to_yaml(const rsysmsg::srv::Fight_Response & msg)
{
  return rsysmsg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rsysmsg::srv::Fight_Response>()
{
  return "rsysmsg::srv::Fight_Response";
}

template<>
inline const char * name<rsysmsg::srv::Fight_Response>()
{
  return "rsysmsg/srv/Fight_Response";
}

template<>
struct has_fixed_size<rsysmsg::srv::Fight_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rsysmsg::srv::Fight_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rsysmsg::srv::Fight_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rsysmsg::srv::Fight>()
{
  return "rsysmsg::srv::Fight";
}

template<>
inline const char * name<rsysmsg::srv::Fight>()
{
  return "rsysmsg/srv/Fight";
}

template<>
struct has_fixed_size<rsysmsg::srv::Fight>
  : std::integral_constant<
    bool,
    has_fixed_size<rsysmsg::srv::Fight_Request>::value &&
    has_fixed_size<rsysmsg::srv::Fight_Response>::value
  >
{
};

template<>
struct has_bounded_size<rsysmsg::srv::Fight>
  : std::integral_constant<
    bool,
    has_bounded_size<rsysmsg::srv::Fight_Request>::value &&
    has_bounded_size<rsysmsg::srv::Fight_Response>::value
  >
{
};

template<>
struct is_service<rsysmsg::srv::Fight>
  : std::true_type
{
};

template<>
struct is_service_request<rsysmsg::srv::Fight_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rsysmsg::srv::Fight_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RSYSMSG__SRV__DETAIL__FIGHT__TRAITS_HPP_
