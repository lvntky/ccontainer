#define CC_VECTOR_IMPLEMENTATION
#include "../../include/ccontainer/cc_vector.h"
#include "unity.h"

/* ===================================
*               Declarations
*  ===================================
*/

void cc_vector_create_test();
void cc_vector_at_test();
void cc_vector_size_test();

/* ===================================
*               Definitions
*  ===================================
*/
void cc_vector_create_test()
{
	cc_vector_t *vec = cc_vector_create(1);

	TEST_ASSERT(vec != NULL);
	cc_vector_free(vec);
}

void cc_vector_at_test()
{
	cc_vector_t *vec = cc_vector_create(1);
	int data = 5;
	cc_vector_push_back(vec, &data);
	int expected = *(int *)cc_vector_at(vec, 0);

	TEST_ASSERT_EQUAL(5, expected);

	cc_vector_free(vec);
}

void cc_vector_size_test()
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
