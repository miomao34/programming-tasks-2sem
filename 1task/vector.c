#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

vector* common_ctor(
		vector* this,
		unsigned int len,
		unsigned int elem_size,
		vector* (*ctor)(unsigned int len, void* values),
		void* (*add)(void* left, void* right),
		void* (*multiply)(void* left, void* right),
		void  (*dump)(void* value),
		void* zero,
		void* values)
{
	if (this == NULL || values == NULL || zero == NULL || \
		add == NULL || multiply == NULL)
		return NULL;
	
	this->length = len;
	this->elem_size = elem_size;
	this->elem_zero = calloc(1, elem_size);
	memcpy(this->elem_zero, (const void *) zero, elem_size);
	this->values = calloc(len, elem_size);
	memcpy(this->values, (const void *) values, elem_size * len);
	
	this->add = add;
	this->multiply = multiply;
	this->ctor = ctor;
	this->dtor = dtor;
	this->dump = dump;

	return this;
}

void dtor(vector* this)
{
	if (this == NULL || this->values == NULL || this->elem_zero == NULL)
		return;
	
	free(this->values);
	free(this->elem_zero);
}

void print(vector* vect)
{
    for (int i = 0; i < vect->length; i++)
        vect->dump(get(vect, i));
    printf("\n");
}

void* get(vector* vect, int i)
{
	return (vect->values + vect->elem_size * i);
}

void set(vector* vect, int index, void* value)
{
	memcpy(vect->values + vect->elem_size * index,
		value,
		vect->elem_size);
}

vector* add (vector* left, vector* right)
{
	if (left->length != right->length || \
		left->elem_size != right->elem_size || \
		left->values == NULL    || right->values == NULL || \
		left->elem_zero == NULL || right->elem_zero == NULL)
		return NULL;
	
	for (int i=0; i < left->length*left->length; i++)
		left->add(get(left, i), get(right, i));
	return left;
}

vector* multiply_on_scalar (vector* vect, void* scalar)
{
    if (vect == NULL || scalar == NULL)
        return NULL;
    
    for (int i=0; i < vect->length; i++)
        vect->multiply(get(vect, i), scalar);
    
    return vect;
}