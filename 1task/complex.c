#include <stdlib.h>

#include "vector.h"
#include "complex.h"


vector* vector_complex_ctor(unsigned int len, void* values)
{
    vector* this = calloc(sizeof(vector), 1);
    complex* zero = calloc(sizeof(complex), 1);
	((complex*)zero)->re = 0;
	((complex*)zero)->im = 0;

	return common_ctor(
		this,
		len,
		sizeof(complex),
		vector_complex_ctor,
		vector_complex_add,
		vector_complex_multiply,
		complex_dump,
		zero,
		values);
}

void* vector_complex_add(void* left, void* right)
{
	((complex*)left)->re = ((complex*)left)->re + ((complex*)right)->re;
	((complex*)left)->im = ((complex*)left)->im + ((complex*)right)->im;
	return left;
}

void* vector_complex_multiply(void* left, void* right)
{
	((complex*)left)->re = ((complex*)left)->re * ((complex*)right)->re - ((complex*)left)->im * ((complex*)right)->im;
	((complex*)left)->im = ((complex*)left)->re * ((complex*)right)->im + ((complex*)left)->im * ((complex*)right)->re;
	return left;
}

void complex_dump(void* value)
{
	if (value == NULL)
		return;
	
	printf("[%lf + %lfi]\t", ((complex *)value)->re, ((complex *)value)->im);
}