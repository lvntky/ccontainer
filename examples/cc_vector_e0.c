#define CC_VECTOR_IMPLEMENTATION
#include "../include/ccontainer/cc_vector.h"
#include <stdio.h>

int main()
{
	cc_vector_t *vec = cc_vector_create(1);
	for (size_t i = 0; i < 5; i++) {
		int *value = (int *)malloc(sizeof(int));
		*value = i;
		printf("Vector size at insertion-%zu: %zu\n", i,
		       cc_vector_size(vec));
		cc_vector_push_back(vec, value);
	}

	for (size_t j = 0; j < 5; j++) {
		printf("Data at-%zu: %p\n", j, cc_vector_at(vec, j));
	}

	return 0;
}