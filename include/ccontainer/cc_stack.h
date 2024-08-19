// cc_.h - v0.1.0 - public domain Levent Kaya 2024
// LIFO stack library for C
//
// This file provides both the interface and the implementation.
// To instantiate the implementation,
//      #define CC_STACK_IMPLEMENTATION
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

#ifndef CC_STACK_H__
#define CC_STACK_H__

#ifdef __cplusplus
extern "C" {
#endif

// =====================================================================
//                                Headers
// =====================================================================

#include <stddef.h> // for size_t
#include <stdlib.h> // for malloc
#include <string.h> // for memcpy
#include <stdio.h> // for snprintf

// =====================================================================
//                          Configuration Macros
// =====================================================================

#define CC_STACK_INITIAL_CAPACITY 2 // can be overwriteable

// =====================================================================
//                          Utility Macros
// =====================================================================

// =====================================================================
//                          Struct Definitions
// =====================================================================

typedef struct cc_stack {
	void *data;
	size_t element_size;
	size_t capacity;
	size_t size;
} cc_stack_t;

// =====================================================================
//                          Library Function Declarations
// =====================================================================

void cc_stack_create(cc_stack_t *stack, size_t element_size);

// =====================================================================
//                          Struct Function Declarations
// =====================================================================

// =====================================================================
//                        Function Definitions
// =====================================================================

#define CC_STACK_IMPLEMENTATION
#ifdef CC_STACK_IMPLEMENTATION

void cc_stack_create(cc_stack_t *stack, size_t element_size)
{
	stack->capacity = CC_STACK_INITIAL_CAPACITY;
	stack->element_size = element_size;
	stack->size = 0;
	stack->data = malloc(CC_STACK_INITIAL_CAPACITY * element_size);
}

#endif // CC_STACK_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // CC_STACK_H__

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
