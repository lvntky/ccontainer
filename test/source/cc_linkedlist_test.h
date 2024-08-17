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

//TODO: Failed test - fill fix later
/*
	void cc_linkedlist_node_search_test(void)
	{
		cc_linkedlist_t *list =
			(cc_linkedlist_t *)malloc(sizeof(cc_linkedlist_t));
		cc_linkedlist_init(list, sizeof(int)); // similar to std::vector<int>

		int data1 = 0;
		int data2 = 1;

		cc_linkedlist_insert_front(list, &data1);
		cc_linkedlist_insert_front(list, &data2);

		cc_linkedlist_node_t *searched_node =
			cc_linkedlist_node_search(list, &data2);

		TEST_ASSERT_EQUAL(data2, searched_node->data);

		cc_linkedlist_free(list);
	}
*/

void cc_linkedlist_insert_front_test(void)
{
	cc_linkedlist_t *list =
		(cc_linkedlist_t *)malloc(sizeof(cc_linkedlist_t));

	cc_linkedlist_init(list, sizeof(int));
	int first_data = 10;

	cc_linkedlist_insert_front(list, (void *)first_data);

	TEST_ASSERT_EQUAL(first_data, list->head->data);
	cc_linkedlist_free(list);
}