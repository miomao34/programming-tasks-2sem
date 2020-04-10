#include <stdlib.h>

#include "matrix.h"
#include "float.h"


matrix* matrix_float_create_instance(unsigned int size, void* values)
{
    matrix* this = calloc(sizeof(matrix), 1);
    float* zero = calloc(sizeof(float), 1);
    (*(float*)zero) = 0;

	return common_create_instance(
		this,
		size,
		sizeof(float),
		matrix_float_create_instance,
		matrix_float_add,
		matrix_float_multiply,
		float_print,
		zero,
		values);
}

void* matrix_float_add(void* left, void* right)
{
	*(float*)left = *(float*)left + *(float*)right;
	return left;
}

void* matrix_float_multiply(void* left, void* right)
{
	*(float*)left = *(float*)left * *(float*)right;
	return left;
}

void float_print(void* value)
{
	if (value == NULL)
		return;
	
	printf("%f\t", *(float*)value);
}