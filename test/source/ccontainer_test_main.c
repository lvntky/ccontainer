#include "unity.h"

void setUp(void)
{
	// This is run before EACH test
}

void tearDown(void)
{
	// This is run after EACH test
}

int add(int a, int b)
{
	return a + b;
}

void test_add_two_positive_numbers(void)
{
	TEST_ASSERT_EQUAL(12, add(5, 7));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_add_two_positive_numbers);

	return UNITY_END();
}