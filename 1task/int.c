#include <stdlib.h>

#include "vector.h"
#include "int.h"


vector* vector_int_ctor(unsigned int len, void* values)
{
    vector* this = calloc(sizeof(vector), 1);
    int* zero = calloc(sizeof(int), 1);
    (*(int*)zero) = 0;

	return common_ctor(
		this,
		len,
		sizeof(int),
		vector_int_ctor,
		vector_int_add,
		vector_int_multiply,
		int_dump,
		zero,
		values);
}

void* vector_int_add(void* left, void* right)
{
	*(int*)left = *(int*)left + *(int*)right;
	return left;
}

void* vector_int_multiply(void* left, void* right)
{
	*(int*)left = *(int*)left * *(int*)right;
	return left;
}

void int_dump(void* value)
{
	if (value == NULL)
		return;
	
	printf("%d\t", *(int*)value);
}