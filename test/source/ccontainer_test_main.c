#include "unity.h"
#include "cc_vector_test.h"

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

	return UNITY_END();
}