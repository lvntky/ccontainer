#define CC_VECTOR_IMPLEMENTATIONs
#include "../../include/ccontainer/cc_vector.h"
#include "../utest.h/utest.h"

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

	void *data = cc_vector_at(vector, 1110);

	ASSERT_TRUE(data != NULL);
}