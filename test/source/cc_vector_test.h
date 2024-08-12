#define CC_VECTOR_IMPLEMENTATION
#include "../../include/ccontainer/cc_vector.h"
#include "unity.h"

void cc_vector_create_test(void)
{
	cc_vector_t *vec = cc_vector_create(1);

	TEST_ASSERT(vec != NULL);
	cc_vector_free(vec);
}

void cc_vector_at_test(void)
{
	cc_vector_t *vec = cc_vector_create(1);
	int data = 5;
	cc_vector_push_back(vec, &data);
	int expected = *(int *)cc_vector_at(vec, 0);

	TEST_ASSERT_EQUAL(5, expected);

	cc_vector_free(vec);
}

void cc_vector_size_test(void)
{
	cc_vector_t *vec = cc_vector_create(1);
	int data1 = 1;
	int data2 = 2;
	int data3 = 3;

	cc_vector_push_back(vec, &data1);
	cc_vector_push_back(vec, &data2);
	cc_vector_push_back(vec, &data3);

	TEST_ASSERT_EQUAL(3, cc_vector_size(vec));
	cc_vector_free(vec);
}

void cc_vector_complex_data_test(void)
{
	typedef struct data {
		int key;
		char *value;
	} data_t;

	data_t d1 = { 0, "abc" };
	data_t d2 = { 1, "def" };
	data_t d3 = { 2, "abc" };

	cc_vector_t *vec = cc_vector_create(3);
	cc_vector_push_back(vec, &d1);
	cc_vector_push_back(vec, &d2);
	cc_vector_push_back(vec, &d3);

	TEST_ASSERT_EQUAL(3, vec->size);

	data_t second_data = *(data_t *)cc_vector_at(vec, 1);

	TEST_ASSERT_EQUAL("def", second_data.value);

	cc_vector_erase(vec, 0);

	TEST_ASSERT_NOT_EQUAL(0, cc_vector_at(vec, 0));
	TEST_ASSERT_EQUAL(2, cc_vector_size(vec));

	cc_vector_free(vec);
}

void cc_vector_iterator_begin_test(void)
{
	cc_vector_t *vec = cc_vector_create(1);
	cc_vector_iterator_t it = cc_vector_iterator_begin(vec);

	TEST_ASSERT_EQUAL(vec, it.vector);
	TEST_ASSERT_EQUAL(0, it.index);

	cc_vector_free(vec);
}