#include <stdlib.h>

#include "vector.h"
#include "float.h"


vector* vector_float_ctor(unsigned int len, void* values)
{
    vector* this = calloc(sizeof(vector), 1);
    int* zero = calloc(sizeof(float), 1);
    (*(float*)zero) = 0;

	return common_ctor(
		this,
		len,
		sizeof(float),
		vector_float_ctor,
		vector_float_add,
		vector_float_multiply,
		float_dump,
		zero,
		values);
}

void* vector_float_add(void* left, void* right)
{
	*(float*)left = *(float*)left + *(float*)right;
	return left;
}

void* vector_float_multiply(void* left, void* right)
{
	*(float*)left = *(float*)left * *(float*)right;
	return left;
}

void float_dump(void* value)
{
	if (value == NULL)
		return;
	
	printf("%f\t", *(float*)value);
}