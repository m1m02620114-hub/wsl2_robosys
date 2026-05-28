// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__MSG__DETAIL__FIGHTING__FUNCTIONS_H_
#define RSYSMSG__MSG__DETAIL__FIGHTING__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rsysmsg/msg/rosidl_generator_c__visibility_control.h"

#include "rsysmsg/msg/detail/fighting__struct.h"

/// Initialize msg/Fighting message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__msg__Fighting
 * )) before or use
 * rsysmsg__msg__Fighting__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__msg__Fighting__init(rsysmsg__msg__Fighting * msg);

/// Finalize msg/Fighting message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__msg__Fighting__fini(rsysmsg__msg__Fighting * msg);

/// Create msg/Fighting message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__msg__Fighting__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__msg__Fighting *
rsysmsg__msg__Fighting__create();

/// Destroy msg/Fighting message.
/**
 * It calls
 * rsysmsg__msg__Fighting__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__msg__Fighting__destroy(rsysmsg__msg__Fighting * msg);

/// Check for msg/Fighting message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__msg__Fighting__are_equal(const rsysmsg__msg__Fighting * lhs, const rsysmsg__msg__Fighting * rhs);

/// Copy a msg/Fighting message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__msg__Fighting__copy(
  const rsysmsg__msg__Fighting * input,
  rsysmsg__msg__Fighting * output);

/// Initialize array of msg/Fighting messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__msg__Fighting__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__msg__Fighting__Sequence__init(rsysmsg__msg__Fighting__Sequence * array, size_t size);

/// Finalize array of msg/Fighting messages.
/**
 * It calls
 * rsysmsg__msg__Fighting__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__msg__Fighting__Sequence__fini(rsysmsg__msg__Fighting__Sequence * array);

/// Create array of msg/Fighting messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__msg__Fighting__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__msg__Fighting__Sequence *
rsysmsg__msg__Fighting__Sequence__create(size_t size);

/// Destroy array of msg/Fighting messages.
/**
 * It calls
 * rsysmsg__msg__Fighting__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__msg__Fighting__Sequence__destroy(rsysmsg__msg__Fighting__Sequence * array);

/// Check for msg/Fighting message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__msg__Fighting__Sequence__are_equal(const rsysmsg__msg__Fighting__Sequence * lhs, const rsysmsg__msg__Fighting__Sequence * rhs);

/// Copy an array of msg/Fighting messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__msg__Fighting__Sequence__copy(
  const rsysmsg__msg__Fighting__Sequence * input,
  rsysmsg__msg__Fighting__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RSYSMSG__MSG__DETAIL__FIGHTING__FUNCTIONS_H_
