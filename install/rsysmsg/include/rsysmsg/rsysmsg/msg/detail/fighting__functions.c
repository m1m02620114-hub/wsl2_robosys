// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rsysmsg:msg/Fighting.idl
// generated code does not contain a copyright notice
#include "rsysmsg/msg/detail/fighting__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pone`
// Member `ptwo`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rsysmsg__msg__Fighting__init(rsysmsg__msg__Fighting * msg)
{
  if (!msg) {
    return false;
  }
  // pone
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->pone, 0)) {
    rsysmsg__msg__Fighting__fini(msg);
    return false;
  }
  // ptwo
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->ptwo, 0)) {
    rsysmsg__msg__Fighting__fini(msg);
    return false;
  }
  return true;
}

void
rsysmsg__msg__Fighting__fini(rsysmsg__msg__Fighting * msg)
{
  if (!msg) {
    return;
  }
  // pone
  rosidl_runtime_c__int32__Sequence__fini(&msg->pone);
  // ptwo
  rosidl_runtime_c__int32__Sequence__fini(&msg->ptwo);
}

bool
rsysmsg__msg__Fighting__are_equal(const rsysmsg__msg__Fighting * lhs, const rsysmsg__msg__Fighting * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pone
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->pone), &(rhs->pone)))
  {
    return false;
  }
  // ptwo
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->ptwo), &(rhs->ptwo)))
  {
    return false;
  }
  return true;
}

bool
rsysmsg__msg__Fighting__copy(
  const rsysmsg__msg__Fighting * input,
  rsysmsg__msg__Fighting * output)
{
  if (!input || !output) {
    return false;
  }
  // pone
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->pone), &(output->pone)))
  {
    return false;
  }
  // ptwo
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->ptwo), &(output->ptwo)))
  {
    return false;
  }
  return true;
}

rsysmsg__msg__Fighting *
rsysmsg__msg__Fighting__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__msg__Fighting * msg = (rsysmsg__msg__Fighting *)allocator.allocate(sizeof(rsysmsg__msg__Fighting), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rsysmsg__msg__Fighting));
  bool success = rsysmsg__msg__Fighting__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rsysmsg__msg__Fighting__destroy(rsysmsg__msg__Fighting * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rsysmsg__msg__Fighting__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rsysmsg__msg__Fighting__Sequence__init(rsysmsg__msg__Fighting__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__msg__Fighting * data = NULL;

  if (size) {
    data = (rsysmsg__msg__Fighting *)allocator.zero_allocate(size, sizeof(rsysmsg__msg__Fighting), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rsysmsg__msg__Fighting__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rsysmsg__msg__Fighting__fini(&data[i - 1]);
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
rsysmsg__msg__Fighting__Sequence__fini(rsysmsg__msg__Fighting__Sequence * array)
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
      rsysmsg__msg__Fighting__fini(&array->data[i]);
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

rsysmsg__msg__Fighting__Sequence *
rsysmsg__msg__Fighting__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rsysmsg__msg__Fighting__Sequence * array = (rsysmsg__msg__Fighting__Sequence *)allocator.allocate(sizeof(rsysmsg__msg__Fighting__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rsysmsg__msg__Fighting__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rsysmsg__msg__Fighting__Sequence__destroy(rsysmsg__msg__Fighting__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rsysmsg__msg__Fighting__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rsysmsg__msg__Fighting__Sequence__are_equal(const rsysmsg__msg__Fighting__Sequence * lhs, const rsysmsg__msg__Fighting__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rsysmsg__msg__Fighting__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rsysmsg__msg__Fighting__Sequence__copy(
  const rsysmsg__msg__Fighting__Sequence * input,
  rsysmsg__msg__Fighting__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rsysmsg__msg__Fighting);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rsysmsg__msg__Fighting * data =
      (rsysmsg__msg__Fighting *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rsysmsg__msg__Fighting__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rsysmsg__msg__Fighting__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rsysmsg__msg__Fighting__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
