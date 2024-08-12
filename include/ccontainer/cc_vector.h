// cc_vector.h - v0.1.0 - public domain Levent Kaya 2024
// ccontainers dynamic array (vector) library.
//
// This file provides both the interface and the implementation.
// To instantiate the implementation,
//      #define CC_VECTOR_IMPLEMENTATION
// in *ONE* source file, before #including this file.
//
//
// History:
// 	- 0.2.0 Iterator Support
//  - 0.1.0 First public release
//
// Status:
//	08/11/2024 TODO: Add thread safety locks
// 	08/11/2024 TODO: Add safe allocation macro
//	08/11/2024 Added Iterator support
//  Implemented the core functionalities
// 	More tests required
//
// Contributors:
//  @lvntky
//
// LICENSE
//
//   See end of file for license information.

#ifndef __CC_VECTOR_H__
#define __CC_VECTOR_H__

// =====================================================================
//                                Headers
// =====================================================================

#include <stddef.h> // for size_t
#include <stdlib.h> // for malloc
#include <stdio.h> // for snprintf
#include <pthread.h> // for pthread_mutex_t, pthread_mutex_lock, pthread_mutex_unlock

#ifdef __cplusplus
extern "C" {
#endif

// =====================================================================
//                          Configuration Macros
// =====================================================================

#define CC_VECTOR_DEFAULT_CAPACITY_INCREASE_SIZE 2
#define CC_VECTOR_MAX_SIZE 4096
#define CC_VECTOR_DEFAULT_CAPACITY 1
#define CC_VECTOR_EXIT_FAILURE -1

// =====================================================================
//                          Utility Macros
// =====================================================================

#define CC_VECTOR_LOG(format, ...)                                         \
	do {                                                               \
		char buffer[256];                                          \
		snprintf(buffer, sizeof(buffer), "%s: " format, "Error",   \
			 ##__VA_ARGS__);                                   \
		fprintf(stderr, "[CC_LINKEDLIST_H ERROR] - %s\n", buffer); \
	} while (0)

// =====================================================================
//                          Struct Definitions
// =====================================================================

typedef struct cc_vector {
	void **data;
	size_t size;
	size_t capacity;
	pthread_mutex_t lock;
} cc_vector_t;

/**
 * @brief Iterator support for cc_vector
 * 
 */
typedef struct cc_vector_iterator {
	cc_vector_t *vector;
	size_t index;
} cc_vector_iterator_t;

// =====================================================================
//                          Library Function Declarations
// =====================================================================

/**
 * @brief create cc_vector
 *
 * @param initial_capacity initial capacity of cc_vector
 * @return cc_vector_t*
 */
cc_vector_t *cc_vector_create(size_t initial_capacity);

/**
 * @brief free cc_vector from memory
 *
 * @param vector cc_vector_t to free
 */
void cc_vector_free(cc_vector_t *vector);

/**
 * @brief get request data at given index (with bound checking)
 *
 * @param vector vector to look for
 * @param index index to look for given vector
 * @return cc_vector_t*
 */
void *cc_vector_at(cc_vector_t *vector, size_t index);

/**
 * @brief Get first element of the vector
 *
 * @param vector
 * @return void*
 */
void *cc_vector_front(cc_vector_t *vector);

/**
 * @brief get the last element of the vector
 *
 * @param vector
 * @return void*
 */
void *cc_vector_back(cc_vector_t *vector);

/**
 * @brief insert new data to the vector as last element
 *
 * @param vector
 * @param data
 */
void cc_vector_push_back(cc_vector_t *vector, void *data);

/**
 * @brief return the size of elements inside vector
 *
 * @param cc_vector
 * @return size_t
 */
size_t cc_vector_size(cc_vector_t *vector);

/**
 * @brief Returns the maximum number of elements the container is
 * able to hold due to system or library implementation limitations
 *
 * @return const size_t
 */
size_t cc_vector_maxsize(void);

/**
 * @brief Requests the removal of unused capacity.
 *
 * @param vector
 */
void cc_vector_shrint_to_fix(cc_vector_t *vector);

/**
 * @brief Returns the number of elements that the container has currently allocated space for.
 *
 * @param vector
 * @return size_t
 */
size_t cc_vector_capacity(cc_vector_t *vector);

/**
 * @brief Clears the entire vector
 *
 * @param vector
 */
void cc_vector_clear(cc_vector_t *vector);

/**
 * @brief Erase the element at position
 *
 * @param vector
 * @param pos
 */
void cc_vector_erase(cc_vector_t *vector, size_t pos);

/**
 * @brief  initializes the iterator at the beginning of the vector.
 * 
 * @param vector to initilize iterator on
 * @return cc_vector_iterator_t iterator itself
 */
cc_vector_iterator_t cc_vector_iterator_begin(cc_vector_t *vector);

/**
 * @brief advances the iterator and returns the current element.
 * 
 * @param iter iterator that runs
 * @return void* data to return
 */
void *cc_vector_iterator_next(cc_vector_iterator_t *iter);

// =====================================================================
//                        Function Definitions
// =====================================================================

#ifdef CC_VECTOR_IMPLEMENTATION
cc_vector_t *cc_vector_create(size_t initial_capacity)
{
	cc_vector_t *vector = (cc_vector_t *)malloc(sizeof(cc_vector_t));
	if (!vector) {
		return NULL;
	}

	size_t capacity;
	if (initial_capacity <= 0) {
		capacity = CC_VECTOR_DEFAULT_CAPACITY;
	} else {
		capacity = initial_capacity;
	}

	vector->capacity = initial_capacity;
	vector->size = 0;
	vector->data = (void **)malloc(sizeof(void *) * vector->capacity);
	pthread_mutex_init(&vector->lock, NULL); // No mutex attribute
	return vector;
}

void cc_vector_free(cc_vector_t *vector)
{
	if (vector) {
		pthread_mutex_destroy(&vector->lock);
		free(vector->data);
		free(vector);
	}
}

void *cc_vector_at(cc_vector_t *vector, size_t index)
{
	pthread_mutex_lock(&vector->lock);
	if (index > vector->size) {
		CC_VECTOR_LOG(
			"Index out of bounds. Terminating program with failing exit status.");
		pthread_mutex_unlock(&vector->lock);
		exit(CC_VECTOR_EXIT_FAILURE);
	}
	pthread_mutex_unlock(&vector->lock);
	return vector->data[index];
}

void *cc_vector_front(cc_vector_t *vector)
{
	pthread_mutex_lock(&vector->lock);
	if (vector == NULL) {
		CC_VECTOR_LOG("The vector is uninitialized.");
		pthread_mutex_unlock(&vector->lock);
		exit(CC_VECTOR_EXIT_FAILURE);
	}
	pthread_mutex_unlock(&vector->lock);
	return vector->data[0];
}

void *cc_vector_back(cc_vector_t *vector)
{
	pthread_mutex_lock(&vector->lock);
	if (vector == NULL) {
		CC_VECTOR_LOG("The vector is uninitialized.");
		pthread_mutex_unlock(&vector->lock);
		exit(CC_VECTOR_EXIT_FAILURE);
	}
	pthread_mutex_unlock(&vector->lock);
	return vector->data[vector->size - 1];
}

void cc_vector_push_back(cc_vector_t *vector, void *data)
{
	pthread_mutex_lock(&vector->lock);
	if (vector->size == vector->capacity) {
		// Double the capacity or set it to 1 if it's currently 0
		vector->capacity = vector->capacity == 0 ? 1 :
							   vector->capacity * 2;
		void **new_data = (void **)realloc(
			vector->data, sizeof(void *) * vector->capacity);
		if (!new_data) {
			CC_VECTOR_LOG(
				"Memory allocation has failed for cc_vector_push_back(). Terminating program with failing exit status.");
			pthread_mutex_unlock(&vector->lock);
			exit(CC_VECTOR_EXIT_FAILURE);
		}
		vector->data = new_data;
	}
	vector->data[vector->size++] = data;
	pthread_mutex_unlock(&vector->lock);
}

size_t cc_vector_size(cc_vector_t *vector)
{
	pthread_mutex_lock(&vector->lock);
	size_t size = vector->size;
	pthread_mutex_unlock(&vector->lock);
	//TODO: NULL check might be needed.
	return size;
}

size_t cc_vector_maxsize(void)
{
	//TODO: needs cheks
	return CC_VECTOR_MAX_SIZE;
}

size_t cc_vector_capacity(cc_vector_t *vector)
{
	pthread_mutex_lock(&vector->lock);
	size_t capacity = vector->capacity;
	pthread_mutex_unlock(&vector->lock);
	return capacity;
}

void cc_vector_clear(cc_vector_t *vector)
{
	pthread_mutex_lock(&vector->lock);
	cc_vector_free(vector);

	// and re-initialize for reuse (TODO: Possibly gonna fvck up, check it)
	vector = cc_vector_create(0);
	pthread_mutex_unlock(&vector->lock);
}

// Works at O(n), can we make it more efficient ?
void cc_vector_erase(cc_vector_t *vector, size_t pos)
{
	pthread_mutex_lock(&vector->lock);
	if (vector == NULL || pos >= vector->size) {
		CC_VECTOR_LOG("Invalid position for cc_vector_erase.");
		pthread_mutex_unlock(&vector->lock);
		exit(CC_VECTOR_EXIT_FAILURE);
	}

	for (size_t i = pos; i < vector->size - 1; ++i) {
		vector->data[i] = vector->data[i + 1];
	}

	vector->size--;
	pthread_mutex_unlock(&vector->lock);
}

void cc_vector_shrink_to_fit(cc_vector_t *vector)
{
	pthread_mutex_lock(&vector->lock);
	if (vector == NULL) {
		CC_VECTOR_LOG("The vector is uninitialized.");
		pthread_mutex_unlock(&vector->lock);
		exit(CC_VECTOR_EXIT_FAILURE);
	}

	void **new_data =
		(void **)realloc(vector->data, vector->size * sizeof(void *));

	if (new_data) {
		vector->data = new_data;
		vector->capacity = vector->size;
	}
	pthread_mutex_unlock(&vector->lock);
}

cc_vector_iterator_t cc_vector_iterator_begin(cc_vector_t *vector)
{
	cc_vector_iterator_t iterator = { vector, 0 };
	return iterator;
}

void *cc_vector_iterator_next(cc_vector_iterator_t *iter)
{
	if (iter == NULL || iter->vector == NULL) {
		CC_VECTOR_LOG("Iterator or vector is uninitialized.");
		exit(CC_VECTOR_EXIT_FAILURE);
	}

	if (iter->index >= iter->vector->size) {
		return NULL; // No more elements
	}

	return iter->vector->data[iter->index++];
}

#endif // CC_VECTOR_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // CC_VECTOR_H__

/*
------------------------------------------------------------------------------
This software is available under 2 licenses -- choose whichever you prefer.
------------------------------------------------------------------------------
ALTERNATIVE A - MIT License
Copyright (c) 2024 Levent Kaya
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
------------------------------------------------------------------------------
ALTERNATIVE B - Public Domain (www.unlicense.org)
This is free and unencumbered software released into the public domain.
Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
software, either in source code form or as a compiled binary, for any purpose,
commercial or non-commercial, and by any means.
In jurisdictions that recognize copyright laws, the author or authors of this
software dedicate any and all copyright interest in the software to the public
domain. We make this dedication for the benefit of the public at large and to
the detriment of our heirs and successors. We intend this dedication to be an
overt act of relinquishment in perpetuity of all present and future rights to
this software under copyright law.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
------------------------------------------------------------------------------
*/
