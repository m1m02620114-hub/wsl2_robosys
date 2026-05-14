// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robosys:srv/Name.idl
// generated code does not contain a copyright notice
#include "robosys/srv/detail/name__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
#include "robosys/msg/detail/string__functions.h"

bool
robosys__srv__Name_Request__init(robosys__srv__Name_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!robosys__msg__String__init(&msg->name)) {
    robosys__srv__Name_Request__fini(msg);
    return false;
  }
  return true;
}

void
robosys__srv__Name_Request__fini(robosys__srv__Name_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  robosys__msg__String__fini(&msg->name);
}

bool
robosys__srv__Name_Request__are_equal(const robosys__srv__Name_Request * lhs, const robosys__srv__Name_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!robosys__msg__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  return true;
}

bool
robosys__srv__Name_Request__copy(
  const robosys__srv__Name_Request * input,
  robosys__srv__Name_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!robosys__msg__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  return true;
}

robosys__srv__Name_Request *
robosys__srv__Name_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robosys__srv__Name_Request * msg = (robosys__srv__Name_Request *)allocator.allocate(sizeof(robosys__srv__Name_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robosys__srv__Name_Request));
  bool success = robosys__srv__Name_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robosys__srv__Name_Request__destroy(robosys__srv__Name_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robosys__srv__Name_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robosys__srv__Name_Request__Sequence__init(robosys__srv__Name_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robosys__srv__Name_Request * data = NULL;

  if (size) {
    data = (robosys__srv__Name_Request *)allocator.zero_allocate(size, sizeof(robosys__srv__Name_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robosys__srv__Name_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robosys__srv__Name_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robosys__srv__Name_Request__Sequence__fini(robosys__srv__Name_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robosys__srv__Name_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robosys__srv__Name_Request__Sequence *
robosys__srv__Name_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robosys__srv__Name_Request__Sequence * array = (robosys__srv__Name_Request__Sequence *)allocator.allocate(sizeof(robosys__srv__Name_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robosys__srv__Name_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robosys__srv__Name_Request__Sequence__destroy(robosys__srv__Name_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robosys__srv__Name_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robosys__srv__Name_Request__Sequence__are_equal(const robosys__srv__Name_Request__Sequence * lhs, const robosys__srv__Name_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robosys__srv__Name_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robosys__srv__Name_Request__Sequence__copy(
  const robosys__srv__Name_Request__Sequence * input,
  robosys__srv__Name_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robosys__srv__Name_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robosys__srv__Name_Request * data =
      (robosys__srv__Name_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robosys__srv__Name_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robosys__srv__Name_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robosys__srv__Name_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
// already included above
// #include "robosys/msg/detail/string__functions.h"

bool
robosys__srv__Name_Response__init(robosys__srv__Name_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!robosys__msg__String__init(&msg->response)) {
    robosys__srv__Name_Response__fini(msg);
    return false;
  }
  return true;
}

void
robosys__srv__Name_Response__fini(robosys__srv__Name_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  robosys__msg__String__fini(&msg->response);
}

bool
robosys__srv__Name_Response__are_equal(const robosys__srv__Name_Response * lhs, const robosys__srv__Name_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!robosys__msg__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robosys__srv__Name_Response__copy(
  const robosys__srv__Name_Response * input,
  robosys__srv__Name_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!robosys__msg__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robosys__srv__Name_Response *
robosys__srv__Name_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robosys__srv__Name_Response * msg = (robosys__srv__Name_Response *)allocator.allocate(sizeof(robosys__srv__Name_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robosys__srv__Name_Response));
  bool success = robosys__srv__Name_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robosys__srv__Name_Response__destroy(robosys__srv__Name_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robosys__srv__Name_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robosys__srv__Name_Response__Sequence__init(robosys__srv__Name_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robosys__srv__Name_Response * data = NULL;

  if (size) {
    data = (robosys__srv__Name_Response *)allocator.zero_allocate(size, sizeof(robosys__srv__Name_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robosys__srv__Name_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robosys__srv__Name_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robosys__srv__Name_Response__Sequence__fini(robosys__srv__Name_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robosys__srv__Name_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robosys__srv__Name_Response__Sequence *
robosys__srv__Name_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robosys__srv__Name_Response__Sequence * array = (robosys__srv__Name_Response__Sequence *)allocator.allocate(sizeof(robosys__srv__Name_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robosys__srv__Name_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robosys__srv__Name_Response__Sequence__destroy(robosys__srv__Name_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robosys__srv__Name_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robosys__srv__Name_Response__Sequence__are_equal(const robosys__srv__Name_Response__Sequence * lhs, const robosys__srv__Name_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robosys__srv__Name_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robosys__srv__Name_Response__Sequence__copy(
  const robosys__srv__Name_Response__Sequence * input,
  robosys__srv__Name_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robosys__srv__Name_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robosys__srv__Name_Response * data =
      (robosys__srv__Name_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robosys__srv__Name_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robosys__srv__Name_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robosys__srv__Name_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
