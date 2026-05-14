// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rsysmsg:srv/Name.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__SRV__DETAIL__NAME__FUNCTIONS_H_
#define RSYSMSG__SRV__DETAIL__NAME__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rsysmsg/msg/rosidl_generator_c__visibility_control.h"

#include "rsysmsg/srv/detail/name__struct.h"

/// Initialize srv/Name message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__srv__Name_Request
 * )) before or use
 * rsysmsg__srv__Name_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__srv__Name_Request__init(rsysmsg__srv__Name_Request * msg);

/// Finalize srv/Name message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__srv__Name_Request__fini(rsysmsg__srv__Name_Request * msg);

/// Create srv/Name message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__srv__Name_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__srv__Name_Request *
rsysmsg__srv__Name_Request__create();

/// Destroy srv/Name message.
/**
 * It calls
 * rsysmsg__srv__Name_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__srv__Name_Request__destroy(rsysmsg__srv__Name_Request * msg);

/// Check for srv/Name message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__srv__Name_Request__are_equal(const rsysmsg__srv__Name_Request * lhs, const rsysmsg__srv__Name_Request * rhs);

/// Copy a srv/Name message.
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
rsysmsg__srv__Name_Request__copy(
  const rsysmsg__srv__Name_Request * input,
  rsysmsg__srv__Name_Request * output);

/// Initialize array of srv/Name messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__srv__Name_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__srv__Name_Request__Sequence__init(rsysmsg__srv__Name_Request__Sequence * array, size_t size);

/// Finalize array of srv/Name messages.
/**
 * It calls
 * rsysmsg__srv__Name_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__srv__Name_Request__Sequence__fini(rsysmsg__srv__Name_Request__Sequence * array);

/// Create array of srv/Name messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__srv__Name_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__srv__Name_Request__Sequence *
rsysmsg__srv__Name_Request__Sequence__create(size_t size);

/// Destroy array of srv/Name messages.
/**
 * It calls
 * rsysmsg__srv__Name_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__srv__Name_Request__Sequence__destroy(rsysmsg__srv__Name_Request__Sequence * array);

/// Check for srv/Name message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__srv__Name_Request__Sequence__are_equal(const rsysmsg__srv__Name_Request__Sequence * lhs, const rsysmsg__srv__Name_Request__Sequence * rhs);

/// Copy an array of srv/Name messages.
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
rsysmsg__srv__Name_Request__Sequence__copy(
  const rsysmsg__srv__Name_Request__Sequence * input,
  rsysmsg__srv__Name_Request__Sequence * output);

/// Initialize srv/Name message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__srv__Name_Response
 * )) before or use
 * rsysmsg__srv__Name_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__srv__Name_Response__init(rsysmsg__srv__Name_Response * msg);

/// Finalize srv/Name message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__srv__Name_Response__fini(rsysmsg__srv__Name_Response * msg);

/// Create srv/Name message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__srv__Name_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__srv__Name_Response *
rsysmsg__srv__Name_Response__create();

/// Destroy srv/Name message.
/**
 * It calls
 * rsysmsg__srv__Name_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__srv__Name_Response__destroy(rsysmsg__srv__Name_Response * msg);

/// Check for srv/Name message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__srv__Name_Response__are_equal(const rsysmsg__srv__Name_Response * lhs, const rsysmsg__srv__Name_Response * rhs);

/// Copy a srv/Name message.
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
rsysmsg__srv__Name_Response__copy(
  const rsysmsg__srv__Name_Response * input,
  rsysmsg__srv__Name_Response * output);

/// Initialize array of srv/Name messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__srv__Name_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__srv__Name_Response__Sequence__init(rsysmsg__srv__Name_Response__Sequence * array, size_t size);

/// Finalize array of srv/Name messages.
/**
 * It calls
 * rsysmsg__srv__Name_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__srv__Name_Response__Sequence__fini(rsysmsg__srv__Name_Response__Sequence * array);

/// Create array of srv/Name messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__srv__Name_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__srv__Name_Response__Sequence *
rsysmsg__srv__Name_Response__Sequence__create(size_t size);

/// Destroy array of srv/Name messages.
/**
 * It calls
 * rsysmsg__srv__Name_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__srv__Name_Response__Sequence__destroy(rsysmsg__srv__Name_Response__Sequence * array);

/// Check for srv/Name message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__srv__Name_Response__Sequence__are_equal(const rsysmsg__srv__Name_Response__Sequence * lhs, const rsysmsg__srv__Name_Response__Sequence * rhs);

/// Copy an array of srv/Name messages.
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
rsysmsg__srv__Name_Response__Sequence__copy(
  const rsysmsg__srv__Name_Response__Sequence * input,
  rsysmsg__srv__Name_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RSYSMSG__SRV__DETAIL__NAME__FUNCTIONS_H_
