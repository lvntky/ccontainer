#define CC_VECTOR_IMPLEMENTATIONs
#include "../../include/ccontainer/cc_vector.h"
#include "utest.h"

UTEST(cc_vector, create)
{
	size_t initial_capacity = 10;
	cc_vector_t *vector = cc_vector_create(initial_capacity);

	ASSERT_TRUE(vector != NULL);
	ASSERT_EQ(vector->capacity, initial_capacity);
	ASSERT_EQ(vector->size, 0);
	ASSERT_TRUE(vector->data != NULL);

	free(vector->data);
	free(vector);
}

UTEST(cc_vector, at)
{
	cc_vector_t *vector = cc_vector_create(10);
	cc_vector_push_back(vector, (void *)1);
	void *data = cc_vector_at(vector, 0);

	ASSERT_TRUE(data != NULL);
	cc_vector_free(vector);
}

UTEST(cc_vector, push_back)
{
	cc_vector_t *vector = cc_vector_create(10);
	int *value = (int *)malloc(sizeof(int));
	*value = 1;
	cc_vector_push_back(vector, value);

	ASSERT_EQ(*(int *)cc_vector_at(vector, 0), 1);

	cc_vector_free(vector);
}

UTEST(cc_vector, back)
{
	cc_vector_t *vector = cc_vector_create(5);

	cc_vector_push_back(vector, (void *)5);
	ASSERT_EQ(cc_vector_back(vector),
		  (void *)5); // Dereference the pointer

	cc_vector_free(vector);
}

UTEST(cc_vector, front)
{
	cc_vector_t *vector = cc_vector_create(1);
	cc_vector_push_back(vector, (void *)5);

	ASSERT_EQ(cc_vector_front(vector), (void *)5);

	cc_vector_free(vector);
}

UTEST(cc_vector, type_struct)
{
	cc_vector_t *vector = cc_vector_create(5);

	typedef struct test_str {
		int key;
		char *value;
	} test_str_t;

	test_str_t test1 = { 1, "abc" };
	test_str_t test2 = { 2, "def" };
	test_str_t test3 = { 3, "ghi" };

	cc_vector_push_back(vector, &test1);
	cc_vector_push_back(vector, &test2);
	cc_vector_push_back(vector, &test3);

	ASSERT_EQ(3, cc_vector_size(vector));

	test_str_t *retrieved_test1 = (test_str_t *)cc_vector_at(vector, 0);
	ASSERT_EQ(1, retrieved_test1->key);
	ASSERT_STREQ("abc", retrieved_test1->value);

	test_str_t *retrieved_test2 = (test_str_t *)cc_vector_at(vector, 1);
	ASSERT_EQ(2, retrieved_test2->key);
	ASSERT_STREQ("def", retrieved_test2->value);

	test_str_t *retrieved_test3 = (test_str_t *)cc_vector_at(vector, 2);
	ASSERT_EQ(3, retrieved_test3->key);
	ASSERT_STREQ("ghi", retrieved_test3->value);

	cc_vector_free(vector);
}