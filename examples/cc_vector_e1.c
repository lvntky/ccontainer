// This is the iterator example
#define CC_VECTOR_IMPLEMENTATION
#include "../include/ccontainer/cc_vector.h"

int main()
{
	cc_vector_t *vector = cc_vector_create(10);

	int values[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; ++i) {
		cc_vector_push_back(vector, &values[i]);
	}

	cc_vector_iterator_t iter = cc_vector_iterator_begin(vector);
	void *value;
	while ((value = cc_vector_iterator_next(&iter)) != NULL) {
		printf("%d ", *(int *)value);
	}

	cc_vector_free(vector);
	return 0;
}
