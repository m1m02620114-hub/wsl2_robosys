// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rsysmsg:action/Monster.idl
// generated code does not contain a copyright notice

#ifndef RSYSMSG__ACTION__DETAIL__MONSTER__FUNCTIONS_H_
#define RSYSMSG__ACTION__DETAIL__MONSTER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rsysmsg/msg/rosidl_generator_c__visibility_control.h"

#include "rsysmsg/action/detail/monster__struct.h"

/// Initialize action/Monster message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__action__Monster_Goal
 * )) before or use
 * rsysmsg__action__Monster_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Goal__init(rsysmsg__action__Monster_Goal * msg);

/// Finalize action/Monster message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Goal__fini(rsysmsg__action__Monster_Goal * msg);

/// Create action/Monster message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__action__Monster_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_Goal *
rsysmsg__action__Monster_Goal__create();

/// Destroy action/Monster message.
/**
 * It calls
 * rsysmsg__action__Monster_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Goal__destroy(rsysmsg__action__Monster_Goal * msg);

/// Check for action/Monster message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Goal__are_equal(const rsysmsg__action__Monster_Goal * lhs, const rsysmsg__action__Monster_Goal * rhs);

/// Copy a action/Monster message.
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
rsysmsg__action__Monster_Goal__copy(
  const rsysmsg__action__Monster_Goal * input,
  rsysmsg__action__Monster_Goal * output);

/// Initialize array of action/Monster messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__action__Monster_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Goal__Sequence__init(rsysmsg__action__Monster_Goal__Sequence * array, size_t size);

/// Finalize array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Goal__Sequence__fini(rsysmsg__action__Monster_Goal__Sequence * array);

/// Create array of action/Monster messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__action__Monster_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_Goal__Sequence *
rsysmsg__action__Monster_Goal__Sequence__create(size_t size);

/// Destroy array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Goal__Sequence__destroy(rsysmsg__action__Monster_Goal__Sequence * array);

/// Check for action/Monster message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Goal__Sequence__are_equal(const rsysmsg__action__Monster_Goal__Sequence * lhs, const rsysmsg__action__Monster_Goal__Sequence * rhs);

/// Copy an array of action/Monster messages.
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
rsysmsg__action__Monster_Goal__Sequence__copy(
  const rsysmsg__action__Monster_Goal__Sequence * input,
  rsysmsg__action__Monster_Goal__Sequence * output);

/// Initialize action/Monster message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__action__Monster_Result
 * )) before or use
 * rsysmsg__action__Monster_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Result__init(rsysmsg__action__Monster_Result * msg);

/// Finalize action/Monster message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Result__fini(rsysmsg__action__Monster_Result * msg);

/// Create action/Monster message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__action__Monster_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_Result *
rsysmsg__action__Monster_Result__create();

/// Destroy action/Monster message.
/**
 * It calls
 * rsysmsg__action__Monster_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Result__destroy(rsysmsg__action__Monster_Result * msg);

/// Check for action/Monster message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Result__are_equal(const rsysmsg__action__Monster_Result * lhs, const rsysmsg__action__Monster_Result * rhs);

/// Copy a action/Monster message.
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
rsysmsg__action__Monster_Result__copy(
  const rsysmsg__action__Monster_Result * input,
  rsysmsg__action__Monster_Result * output);

/// Initialize array of action/Monster messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__action__Monster_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Result__Sequence__init(rsysmsg__action__Monster_Result__Sequence * array, size_t size);

/// Finalize array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Result__Sequence__fini(rsysmsg__action__Monster_Result__Sequence * array);

/// Create array of action/Monster messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__action__Monster_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_Result__Sequence *
rsysmsg__action__Monster_Result__Sequence__create(size_t size);

/// Destroy array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Result__Sequence__destroy(rsysmsg__action__Monster_Result__Sequence * array);

/// Check for action/Monster message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Result__Sequence__are_equal(const rsysmsg__action__Monster_Result__Sequence * lhs, const rsysmsg__action__Monster_Result__Sequence * rhs);

/// Copy an array of action/Monster messages.
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
rsysmsg__action__Monster_Result__Sequence__copy(
  const rsysmsg__action__Monster_Result__Sequence * input,
  rsysmsg__action__Monster_Result__Sequence * output);

/// Initialize action/Monster message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__action__Monster_Feedback
 * )) before or use
 * rsysmsg__action__Monster_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Feedback__init(rsysmsg__action__Monster_Feedback * msg);

/// Finalize action/Monster message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Feedback__fini(rsysmsg__action__Monster_Feedback * msg);

/// Create action/Monster message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__action__Monster_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_Feedback *
rsysmsg__action__Monster_Feedback__create();

/// Destroy action/Monster message.
/**
 * It calls
 * rsysmsg__action__Monster_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Feedback__destroy(rsysmsg__action__Monster_Feedback * msg);

/// Check for action/Monster message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Feedback__are_equal(const rsysmsg__action__Monster_Feedback * lhs, const rsysmsg__action__Monster_Feedback * rhs);

/// Copy a action/Monster message.
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
rsysmsg__action__Monster_Feedback__copy(
  const rsysmsg__action__Monster_Feedback * input,
  rsysmsg__action__Monster_Feedback * output);

/// Initialize array of action/Monster messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__action__Monster_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Feedback__Sequence__init(rsysmsg__action__Monster_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Feedback__Sequence__fini(rsysmsg__action__Monster_Feedback__Sequence * array);

/// Create array of action/Monster messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__action__Monster_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_Feedback__Sequence *
rsysmsg__action__Monster_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_Feedback__Sequence__destroy(rsysmsg__action__Monster_Feedback__Sequence * array);

/// Check for action/Monster message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_Feedback__Sequence__are_equal(const rsysmsg__action__Monster_Feedback__Sequence * lhs, const rsysmsg__action__Monster_Feedback__Sequence * rhs);

/// Copy an array of action/Monster messages.
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
rsysmsg__action__Monster_Feedback__Sequence__copy(
  const rsysmsg__action__Monster_Feedback__Sequence * input,
  rsysmsg__action__Monster_Feedback__Sequence * output);

/// Initialize action/Monster message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__action__Monster_SendGoal_Request
 * )) before or use
 * rsysmsg__action__Monster_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_SendGoal_Request__init(rsysmsg__action__Monster_SendGoal_Request * msg);

/// Finalize action/Monster message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_SendGoal_Request__fini(rsysmsg__action__Monster_SendGoal_Request * msg);

/// Create action/Monster message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__action__Monster_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_SendGoal_Request *
rsysmsg__action__Monster_SendGoal_Request__create();

/// Destroy action/Monster message.
/**
 * It calls
 * rsysmsg__action__Monster_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_SendGoal_Request__destroy(rsysmsg__action__Monster_SendGoal_Request * msg);

/// Check for action/Monster message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_SendGoal_Request__are_equal(const rsysmsg__action__Monster_SendGoal_Request * lhs, const rsysmsg__action__Monster_SendGoal_Request * rhs);

/// Copy a action/Monster message.
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
rsysmsg__action__Monster_SendGoal_Request__copy(
  const rsysmsg__action__Monster_SendGoal_Request * input,
  rsysmsg__action__Monster_SendGoal_Request * output);

/// Initialize array of action/Monster messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__action__Monster_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_SendGoal_Request__Sequence__init(rsysmsg__action__Monster_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_SendGoal_Request__Sequence__fini(rsysmsg__action__Monster_SendGoal_Request__Sequence * array);

/// Create array of action/Monster messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__action__Monster_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_SendGoal_Request__Sequence *
rsysmsg__action__Monster_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_SendGoal_Request__Sequence__destroy(rsysmsg__action__Monster_SendGoal_Request__Sequence * array);

/// Check for action/Monster message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_SendGoal_Request__Sequence__are_equal(const rsysmsg__action__Monster_SendGoal_Request__Sequence * lhs, const rsysmsg__action__Monster_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Monster messages.
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
rsysmsg__action__Monster_SendGoal_Request__Sequence__copy(
  const rsysmsg__action__Monster_SendGoal_Request__Sequence * input,
  rsysmsg__action__Monster_SendGoal_Request__Sequence * output);

/// Initialize action/Monster message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__action__Monster_SendGoal_Response
 * )) before or use
 * rsysmsg__action__Monster_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_SendGoal_Response__init(rsysmsg__action__Monster_SendGoal_Response * msg);

/// Finalize action/Monster message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_SendGoal_Response__fini(rsysmsg__action__Monster_SendGoal_Response * msg);

/// Create action/Monster message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__action__Monster_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_SendGoal_Response *
rsysmsg__action__Monster_SendGoal_Response__create();

/// Destroy action/Monster message.
/**
 * It calls
 * rsysmsg__action__Monster_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_SendGoal_Response__destroy(rsysmsg__action__Monster_SendGoal_Response * msg);

/// Check for action/Monster message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_SendGoal_Response__are_equal(const rsysmsg__action__Monster_SendGoal_Response * lhs, const rsysmsg__action__Monster_SendGoal_Response * rhs);

/// Copy a action/Monster message.
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
rsysmsg__action__Monster_SendGoal_Response__copy(
  const rsysmsg__action__Monster_SendGoal_Response * input,
  rsysmsg__action__Monster_SendGoal_Response * output);

/// Initialize array of action/Monster messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__action__Monster_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_SendGoal_Response__Sequence__init(rsysmsg__action__Monster_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_SendGoal_Response__Sequence__fini(rsysmsg__action__Monster_SendGoal_Response__Sequence * array);

/// Create array of action/Monster messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__action__Monster_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_SendGoal_Response__Sequence *
rsysmsg__action__Monster_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_SendGoal_Response__Sequence__destroy(rsysmsg__action__Monster_SendGoal_Response__Sequence * array);

/// Check for action/Monster message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_SendGoal_Response__Sequence__are_equal(const rsysmsg__action__Monster_SendGoal_Response__Sequence * lhs, const rsysmsg__action__Monster_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Monster messages.
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
rsysmsg__action__Monster_SendGoal_Response__Sequence__copy(
  const rsysmsg__action__Monster_SendGoal_Response__Sequence * input,
  rsysmsg__action__Monster_SendGoal_Response__Sequence * output);

/// Initialize action/Monster message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__action__Monster_GetResult_Request
 * )) before or use
 * rsysmsg__action__Monster_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_GetResult_Request__init(rsysmsg__action__Monster_GetResult_Request * msg);

/// Finalize action/Monster message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_GetResult_Request__fini(rsysmsg__action__Monster_GetResult_Request * msg);

/// Create action/Monster message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__action__Monster_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_GetResult_Request *
rsysmsg__action__Monster_GetResult_Request__create();

/// Destroy action/Monster message.
/**
 * It calls
 * rsysmsg__action__Monster_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_GetResult_Request__destroy(rsysmsg__action__Monster_GetResult_Request * msg);

/// Check for action/Monster message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_GetResult_Request__are_equal(const rsysmsg__action__Monster_GetResult_Request * lhs, const rsysmsg__action__Monster_GetResult_Request * rhs);

/// Copy a action/Monster message.
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
rsysmsg__action__Monster_GetResult_Request__copy(
  const rsysmsg__action__Monster_GetResult_Request * input,
  rsysmsg__action__Monster_GetResult_Request * output);

/// Initialize array of action/Monster messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__action__Monster_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_GetResult_Request__Sequence__init(rsysmsg__action__Monster_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_GetResult_Request__Sequence__fini(rsysmsg__action__Monster_GetResult_Request__Sequence * array);

/// Create array of action/Monster messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__action__Monster_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_GetResult_Request__Sequence *
rsysmsg__action__Monster_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_GetResult_Request__Sequence__destroy(rsysmsg__action__Monster_GetResult_Request__Sequence * array);

/// Check for action/Monster message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_GetResult_Request__Sequence__are_equal(const rsysmsg__action__Monster_GetResult_Request__Sequence * lhs, const rsysmsg__action__Monster_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Monster messages.
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
rsysmsg__action__Monster_GetResult_Request__Sequence__copy(
  const rsysmsg__action__Monster_GetResult_Request__Sequence * input,
  rsysmsg__action__Monster_GetResult_Request__Sequence * output);

/// Initialize action/Monster message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__action__Monster_GetResult_Response
 * )) before or use
 * rsysmsg__action__Monster_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_GetResult_Response__init(rsysmsg__action__Monster_GetResult_Response * msg);

/// Finalize action/Monster message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_GetResult_Response__fini(rsysmsg__action__Monster_GetResult_Response * msg);

/// Create action/Monster message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__action__Monster_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_GetResult_Response *
rsysmsg__action__Monster_GetResult_Response__create();

/// Destroy action/Monster message.
/**
 * It calls
 * rsysmsg__action__Monster_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_GetResult_Response__destroy(rsysmsg__action__Monster_GetResult_Response * msg);

/// Check for action/Monster message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_GetResult_Response__are_equal(const rsysmsg__action__Monster_GetResult_Response * lhs, const rsysmsg__action__Monster_GetResult_Response * rhs);

/// Copy a action/Monster message.
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
rsysmsg__action__Monster_GetResult_Response__copy(
  const rsysmsg__action__Monster_GetResult_Response * input,
  rsysmsg__action__Monster_GetResult_Response * output);

/// Initialize array of action/Monster messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__action__Monster_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_GetResult_Response__Sequence__init(rsysmsg__action__Monster_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_GetResult_Response__Sequence__fini(rsysmsg__action__Monster_GetResult_Response__Sequence * array);

/// Create array of action/Monster messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__action__Monster_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_GetResult_Response__Sequence *
rsysmsg__action__Monster_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_GetResult_Response__Sequence__destroy(rsysmsg__action__Monster_GetResult_Response__Sequence * array);

/// Check for action/Monster message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_GetResult_Response__Sequence__are_equal(const rsysmsg__action__Monster_GetResult_Response__Sequence * lhs, const rsysmsg__action__Monster_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Monster messages.
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
rsysmsg__action__Monster_GetResult_Response__Sequence__copy(
  const rsysmsg__action__Monster_GetResult_Response__Sequence * input,
  rsysmsg__action__Monster_GetResult_Response__Sequence * output);

/// Initialize action/Monster message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rsysmsg__action__Monster_FeedbackMessage
 * )) before or use
 * rsysmsg__action__Monster_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_FeedbackMessage__init(rsysmsg__action__Monster_FeedbackMessage * msg);

/// Finalize action/Monster message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_FeedbackMessage__fini(rsysmsg__action__Monster_FeedbackMessage * msg);

/// Create action/Monster message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rsysmsg__action__Monster_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_FeedbackMessage *
rsysmsg__action__Monster_FeedbackMessage__create();

/// Destroy action/Monster message.
/**
 * It calls
 * rsysmsg__action__Monster_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_FeedbackMessage__destroy(rsysmsg__action__Monster_FeedbackMessage * msg);

/// Check for action/Monster message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_FeedbackMessage__are_equal(const rsysmsg__action__Monster_FeedbackMessage * lhs, const rsysmsg__action__Monster_FeedbackMessage * rhs);

/// Copy a action/Monster message.
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
rsysmsg__action__Monster_FeedbackMessage__copy(
  const rsysmsg__action__Monster_FeedbackMessage * input,
  rsysmsg__action__Monster_FeedbackMessage * output);

/// Initialize array of action/Monster messages.
/**
 * It allocates the memory for the number of elements and calls
 * rsysmsg__action__Monster_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_FeedbackMessage__Sequence__init(rsysmsg__action__Monster_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_FeedbackMessage__Sequence__fini(rsysmsg__action__Monster_FeedbackMessage__Sequence * array);

/// Create array of action/Monster messages.
/**
 * It allocates the memory for the array and calls
 * rsysmsg__action__Monster_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
rsysmsg__action__Monster_FeedbackMessage__Sequence *
rsysmsg__action__Monster_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Monster messages.
/**
 * It calls
 * rsysmsg__action__Monster_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
void
rsysmsg__action__Monster_FeedbackMessage__Sequence__destroy(rsysmsg__action__Monster_FeedbackMessage__Sequence * array);

/// Check for action/Monster message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rsysmsg
bool
rsysmsg__action__Monster_FeedbackMessage__Sequence__are_equal(const rsysmsg__action__Monster_FeedbackMessage__Sequence * lhs, const rsysmsg__action__Monster_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Monster messages.
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
rsysmsg__action__Monster_FeedbackMessage__Sequence__copy(
  const rsysmsg__action__Monster_FeedbackMessage__Sequence * input,
  rsysmsg__action__Monster_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RSYSMSG__ACTION__DETAIL__MONSTER__FUNCTIONS_H_
