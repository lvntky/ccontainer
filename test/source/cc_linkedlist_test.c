#define CC_LINKEDLIST_IMPLEMENTATION
#include "../../include/ccontainer/cc_linkedlist.h"
#include "utest.h"

UTEST(cc_linkedlist, create_node)
{
	int data = 1;
	cc_linkedlist_node_t *head =
		cc_linkedlist_create_node(&data, sizeof(data));
	ASSERT_EQ(*(int *)head->data, data);
}

UTEST(cc_linkedlist, size)
{
	int data = 1;
	cc_linkedlist_node_t *head =
		cc_linkedlist_create_node(&data, sizeof(data));

	ASSERT_EQ(cc_linkedlist_size(head), 1);
}