#include "unity.h"
#include "cc_vector_test.h"
#include "cc_linkedlist_test.h"

void setUp(void)
{
	// This is run before EACH test
}

void tearDown(void)
{
	// This is run after EACH test
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(cc_vector_create_test);
	RUN_TEST(cc_vector_at_test);
	RUN_TEST(cc_vector_size_test);
	RUN_TEST(cc_vector_complex_data_test);
	RUN_TEST(cc_vector_iterator_begin_test);
	RUN_TEST(cc_vector_front_test);
	RUN_TEST(cc_vector_back_test);
	RUN_TEST(cc_linkedlist_init_test);
	//RUN_TEST(cc_linkedlist_node_search_test);
	RUN_TEST(cc_linkedlist_insert_front_test);

	return UNITY_END();
}
