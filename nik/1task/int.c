#include <stdlib.h>

#include "matrix.h"
#include "int.h"


matrix* matrix_int_create_instance(unsigned int size, void* values)
{
    matrix* this = calloc(sizeof(matrix), 1);
    int* zero = calloc(sizeof(int), 1);
    (*(int*)zero) = 0;

	return common_create_instance(
		this,
		size,
		sizeof(int),
		matrix_int_create_instance,
		matrix_int_add,
		matrix_int_multiply,
		int_print,
		zero,
		values);
}

void* matrix_int_add(void* left, void* right)
{
	*(int*)left = *(int*)left + *(int*)right;
	return left;
}

void* matrix_int_multiply(void* left, void* right)
{
	*(int*)left = *(int*)left * *(int*)right;
	return left;
}

void int_print(void* value)
{
	if (value == NULL)
		return;
	
	printf("%d\t", *(int*)value);
}