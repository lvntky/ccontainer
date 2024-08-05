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
//  - 0.1.0 First public release
//
// Status:
//  Missing core functionalities.
//
// Contributors:
//  @lvntky
//
// LICENSE
//
//   See end of file for license information.

#ifndef CC_VECTOR_H__
#define CC_VECTOR_H__

// =====================================================================
//                                Headers
// =====================================================================

#include <stddef.h> // for size_t
#include <stdlib.h> // for malloc
#include "ccontainer_utils.h" // for printing stdout etc.

#ifdef __cplusplus
extern "C" {
#endif

// =====================================================================
//                          Configuration Macros
// =====================================================================

// =====================================================================
//                          Utility Macros
// =====================================================================

// =====================================================================
//                          Struct Definitions
// =====================================================================

typedef struct cc_vector {
	void **data;
	size_t size;
	size_t capacity;
} cc_vector_t;

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

// =====================================================================
//                        Function Definitions
// =====================================================================
#define CC_VECTOR_IMPLEMENTATION
#ifdef CC_VECTOR_IMPLEMENTATION
cc_vector_t *cc_vector_create(size_t initial_capacity)
{
	cc_vector_t *vector = (cc_vector_t *)malloc(sizeof(cc_vector_t));
	if (!vector) {
		return NULL;
	}

	vector->capacity = initial_capacity;
	vector->size = 0;
	vector->data = (void **)malloc(sizeof(void *) * vector->capacity);

	return vector;
}

void cc_vector_free(cc_vector_t *vector)
{
	for (size_t i = 0; i < vector->size; i++) {
		free(vector->data[i]);
	}
	free(vector);
}

void *cc_vector_at(cc_vector_t *vector, size_t index)
{
	if (index > vector->size) {
		CCONTAINER_LOG("Index out of bounds");
		exit(EXIT_FAILURE);
	}
	return vector->data[index];
}

void *cc_vector_front(cc_vector_t *vector)
{
	if (vector == NULL) {
		CCONTAINER_LOG("The vector is uninitialized.");
		exit(EXIT_FAILURE);
	}
	return vector->data[0];
}

void *cc_vector_back(cc_vector_t *vector)
{
	if (vector == NULL) {
		CCONTAINER_LOG("The vector is uninitialized.");
		exit(EXIT_FAILURE);
	}
	return vector->data[vector->size];
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