// cc_linkedlist.h - v0.1.0 - public domain Levent Kaya 2024
// Linked list library for C.
//
// This file provides both the interface and the implementation.
// To instantiate the implementation,
//      #define CC_LINKEDLIST_IMPLEMENTATION
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

#ifndef __CC_LINKEDLIST_H__
#define __CC_LINKEDLIST_H__

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
#include <pthread.h> // for mutex
// =====================================================================
//                          Configuration Macros
// =====================================================================

// =====================================================================
//                          Utility Macros
// =====================================================================

#define CC_LINKEDLIST_LOG(format, ...)                                     \
	do {                                                               \
		char buffer[256];                                          \
		snprintf(buffer, sizeof(buffer), "%s: " format, "Error",   \
			 ##__VA_ARGS__);                                   \
		fprintf(stderr, "[CC_LINKEDLIST_H ERROR] - %s\n", buffer); \
	} while (0)

// =====================================================================
//                          Struct Definitions
// =====================================================================

typedef struct cc_linkedlist_node {
	void *data;
	struct cc_linkedlist_node *next;
} cc_linkedlist_node_t;

typedef struct cc_linkedlist {
	cc_linkedlist_node_t *head;
        cc_linkedlist_node_t *tail;
	pthread_mutex_t _lock;
	size_t size;
} cc_linkedlist_t;

// =====================================================================
//                          	Util Functions
// =====================================================================

int compare(void *a, void *b, size_t size)
{
	return memcmp(a, b, size);
}

// =====================================================================
//                          Library Function Declarations
// =====================================================================

/**
 * @brief create single node for linked list
 *
 * @param data to push to the linked list
 * @param danta_size size of the data for allocating memory for it
 * @return cc_linkedlist_node_t*
 */
cc_linkedlist_node_t *cc_linkedlist_node_create(void *data, size_t data_size);

/**
 * @brief initialize an empty list
 *
 * @param list list that head node points to NULL
 * @param data_size given by user
 */
void cc_linkedlist_init(cc_linkedlist_t *list, size_t data_size);

/**
 * @brief gets the current size of linked list
 *
 * @param head to point specified linked list
 * @return size_t number of nodes
 */
size_t cc_linkedlist_size(cc_linkedlist_node_t *head);

/**
 * @brief insert data beggining of the list
 *
 * @param list list that data will be instered
 * @param data data that will be insert
 */
void cc_linkedlist_insert_front(cc_linkedlist_t *list, void *data);

/**
 * @brief insert data end of the list
 *
 * @param list list that data will be instered
 * @param data data that will be insert
 */
void cc_linkedlist_insert_back(cc_linkedlist_t *list, void *data);

/**
 * @brief delete the first node with given data
 *
 * @param list
 * @param data
 * @param cmp
 */
void cc_linkedlist_node_delete(cc_linkedlist_t *list, void *data);

/**
 * @brief search node with given data
 *
 * @param list
 * @param data
 * @param cmp
 * @return cc_linkedlist_node_t* node that contains requested data
 */
cc_linkedlist_node_t *cc_linkedlist_node_search(cc_linkedlist_t *list,
						void *data);

/**
 * @brief delete the entire list from heap
 *
 * @param list to delete
 */
void cc_linkedlist_free(cc_linkedlist_t *list);

// =====================================================================
//                        Function Definitions
// =====================================================================

#ifdef CC_LINKEDLIST_IMPLEMENTATION
cc_linkedlist_node_t *cc_linkedlist_create_node(void *data, size_t data_size)

{
	cc_linkedlist_node_t *new_node =
		(cc_linkedlist_node_t *)malloc(sizeof(cc_linkedlist_node_t));

	if (new_node == NULL) {
		CC_LINKEDLIST_LOG(
			"An error occured while creating node. Terminating program with failing exit status.");
		exit(EXIT_FAILURE);
	}

	new_node->data = malloc(data_size);
	new_node->next = NULL;

	if (sizeof(new_node->data) >= sizeof(data)) {
		memcpy(new_node->data, data, data_size);
	} else {
		CC_LINKEDLIST_LOG(
			"The destination node should be bigger or equal than source node. Terminating program with failing exit status.");
		exit(EXIT_FAILURE);
	}

	return new_node;
}

//TODO: Can we implement more faste solution then O(n) ?
size_t cc_linkedlist_size(cc_linkedlist_node_t *head)
{
	size_t counter = 0;

	while (head != NULL) {
		counter++;
		head = head->next;
	}

	return counter;
}

void cc_linkedlist_init(cc_linkedlist_t *list, size_t data_size)
{
	list->head = NULL;
	list->size = data_size;
}

void cc_linkedlist_insert_front(cc_linkedlist_t *list, void *data)
{
	cc_linkedlist_node_t *newnode =
		cc_linkedlist_create_node(data, list->size);
	newnode->next = list->head;
	list->head = newnode;
}

void cc_linkedlist_free(cc_linkedlist_t *list)
{
	while (list->head != NULL) {
		free(list->head);
	}
	free(list);
}

cc_linkedlist_node_t *cc_linkedlist_node_search(cc_linkedlist_t *list,
						void *data)
{
	cc_linkedlist_node_t *current_node = list->head;
	while (current_node != NULL) {
		if (compare(current_node->data, data, list->size) == 0) {
			return current_node;
		}
		current_node = current_node->next;
	}

	return NULL;
}

#endif // CC_LINKEDLIST_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // __CC_LINKEDLIST_H__

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
