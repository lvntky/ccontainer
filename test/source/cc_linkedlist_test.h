#pragma once
#define CC_LINKEDLIST_IMPLEMENTATION
#include "../../include/ccontainer/cc_linkedlist.h"
#include "unity.h"
#include <stdlib.h>

void cc_linkedlist_init_test(void)
{
	cc_linkedlist_t *list =
		(cc_linkedlist_t *)malloc(sizeof(cc_linkedlist_t));
	cc_linkedlist_init(list, 10);

	TEST_ASSERT_EQUAL(list->size, 10);
	TEST_ASSERT_EQUAL(list->head, NULL);

	cc_linkedlist_free(list);
}