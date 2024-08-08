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
