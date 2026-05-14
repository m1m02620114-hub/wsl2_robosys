// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rsysmsg:srv/Name.idl
// generated code does not contain a copyright notice
#include "rsysmsg/srv/detail/name__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
rsysmsg__srv__Name_Request__init(rsysmsg__srv__Name_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    rsysmsg__srv__Name_Request__fini(msg);
    return false;
  }
  return true;
}

void
rsysmsg__srv__Name_Request__fini(rsysmsg__srv__Name_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
}

bool
rsysmsg__srv__Name_Request__are_equal(const rsysmsg__srv__Name_Request * lhs, const rsysmsg__srv__Name_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  return true;
}

bool
rsysmsg__srv__Name_Request__copy(
  const rsysmsg__srv__Name_Request * input,
  rsysmsg__srv__Name_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  return true;
}

rsysmsg__srv__Name_Request *
rsysmsg__srv__Name_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__srv__Name_Request * msg = (rsysmsg__srv__Name_Request *)allocator.allocate(sizeof(rsysmsg__srv__Name_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rsysmsg__srv__Name_Request));
  bool success = rsysmsg__srv__Name_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rsysmsg__srv__Name_Request__destroy(rsysmsg__srv__Name_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rsysmsg__srv__Name_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rsysmsg__srv__Name_Request__Sequence__init(rsysmsg__srv__Name_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__srv__Name_Request * data = NULL;

  if (size) {
    data = (rsysmsg__srv__Name_Request *)allocator.zero_allocate(size, sizeof(rsysmsg__srv__Name_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rsysmsg__srv__Name_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rsysmsg__srv__Name_Request__fini(&data[i - 1]);
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
rsysmsg__srv__Name_Request__Sequence__fini(rsysmsg__srv__Name_Request__Sequence * array)
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
      rsysmsg__srv__Name_Request__fini(&array->data[i]);
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

rsysmsg__srv__Name_Request__Sequence *
rsysmsg__srv__Name_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__srv__Name_Request__Sequence * array = (rsysmsg__srv__Name_Request__Sequence *)allocator.allocate(sizeof(rsysmsg__srv__Name_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rsysmsg__srv__Name_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rsysmsg__srv__Name_Request__Sequence__destroy(rsysmsg__srv__Name_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rsysmsg__srv__Name_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rsysmsg__srv__Name_Request__Sequence__are_equal(const rsysmsg__srv__Name_Request__Sequence * lhs, const rsysmsg__srv__Name_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rsysmsg__srv__Name_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rsysmsg__srv__Name_Request__Sequence__copy(
  const rsysmsg__srv__Name_Request__Sequence * input,
  rsysmsg__srv__Name_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rsysmsg__srv__Name_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rsysmsg__srv__Name_Request * data =
      (rsysmsg__srv__Name_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rsysmsg__srv__Name_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rsysmsg__srv__Name_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rsysmsg__srv__Name_Request__copy(
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
// #include "rosidl_runtime_c/string_functions.h"

bool
rsysmsg__srv__Name_Response__init(rsysmsg__srv__Name_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    rsysmsg__srv__Name_Response__fini(msg);
    return false;
  }
  return true;
}

void
rsysmsg__srv__Name_Response__fini(rsysmsg__srv__Name_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
rsysmsg__srv__Name_Response__are_equal(const rsysmsg__srv__Name_Response * lhs, const rsysmsg__srv__Name_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
rsysmsg__srv__Name_Response__copy(
  const rsysmsg__srv__Name_Response * input,
  rsysmsg__srv__Name_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

rsysmsg__srv__Name_Response *
rsysmsg__srv__Name_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__srv__Name_Response * msg = (rsysmsg__srv__Name_Response *)allocator.allocate(sizeof(rsysmsg__srv__Name_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rsysmsg__srv__Name_Response));
  bool success = rsysmsg__srv__Name_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rsysmsg__srv__Name_Response__destroy(rsysmsg__srv__Name_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rsysmsg__srv__Name_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rsysmsg__srv__Name_Response__Sequence__init(rsysmsg__srv__Name_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__srv__Name_Response * data = NULL;

  if (size) {
    data = (rsysmsg__srv__Name_Response *)allocator.zero_allocate(size, sizeof(rsysmsg__srv__Name_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rsysmsg__srv__Name_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rsysmsg__srv__Name_Response__fini(&data[i - 1]);
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
rsysmsg__srv__Name_Response__Sequence__fini(rsysmsg__srv__Name_Response__Sequence * array)
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
      rsysmsg__srv__Name_Response__fini(&array->data[i]);
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

rsysmsg__srv__Name_Response__Sequence *
rsysmsg__srv__Name_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__srv__Name_Response__Sequence * array = (rsysmsg__srv__Name_Response__Sequence *)allocator.allocate(sizeof(rsysmsg__srv__Name_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rsysmsg__srv__Name_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rsysmsg__srv__Name_Response__Sequence__destroy(rsysmsg__srv__Name_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rsysmsg__srv__Name_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rsysmsg__srv__Name_Response__Sequence__are_equal(const rsysmsg__srv__Name_Response__Sequence * lhs, const rsysmsg__srv__Name_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rsysmsg__srv__Name_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rsysmsg__srv__Name_Response__Sequence__copy(
  const rsysmsg__srv__Name_Response__Sequence * input,
  rsysmsg__srv__Name_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rsysmsg__srv__Name_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rsysmsg__srv__Name_Response * data =
      (rsysmsg__srv__Name_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rsysmsg__srv__Name_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rsysmsg__srv__Name_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rsysmsg__srv__Name_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
