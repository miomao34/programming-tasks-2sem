#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

matrix* common_create_instance(
		matrix* this,
		unsigned int size,
		unsigned int elem_size,
		matrix* (*create_instance)(unsigned int size, void* values),
		void* (*add)(void* left, void* right),
		void* (*multiply)(void* left, void* right),
		void  (*print)(void* value),
		void* zero,
		void* values)
{
	if (this == NULL || zero == NULL || \
		add == NULL || multiply == NULL)
		return NULL;
	
	this->size = size;
	this->elem_size = elem_size;
	this->elem_zero = calloc(1, elem_size);
	memcpy(this->elem_zero, (const void *) zero, elem_size);
	this->values = calloc(size * size, elem_size);
	if (values != NULL)
		memcpy(this->values, (const void *) values, elem_size * size * size);
	
	this->add = add;
	this->multiply = multiply;
	this->create_instance = create_instance;
	this->print = print;

	return this;
}

matrix* copy(matrix* matr)
{
	return matr->create_instance(matr->size, matr->values);
}

void print(matrix* matr)
{
    for (int i = 0; i < matr->size * matr->size; i++)
	{
        matr->print(get_as_array(matr, i));
		if ((i+1) % matr->size == 0)
			printf("\n");
	}
}

void* get(matrix* matr, int line, int column)
{
	return (matr->values + matr->elem_size * ((line-1) * matr->size + (column-1)));
}

void* get_as_array(matrix* matr, int i)
{
	return (matr->values + matr->elem_size * i);
}

void set(matrix* matr, int line, int column, void* value)
{
	memcpy((matr->values + matr->elem_size * ((line-1) * matr->size + (column-1))),
		value,
		matr->elem_size);
}

void set_as_array(matrix* matr, int index, void* value)
{
	memcpy(matr->values + matr->elem_size * index,
		value,
		matr->elem_size);
}

matrix* add(matrix* left, matrix* right)
{
	if (left->size != right->size || \
		left->elem_size != right->elem_size || \
		left->values == NULL    || right->values == NULL || \
		left->elem_zero == NULL || right->elem_zero == NULL)
		return NULL;
	
	for (int i=0; i < left->size*left->size; i++)
		left->add(get_as_array(left, i), get_as_array(right, i));
	return left;
}

matrix* multiply_on_scalar(matrix* matr, void* scalar)
{
    if (matr == NULL || scalar == NULL)
        return NULL;
    
    for (int i=0; i < matr->size * matr->size; i++)
        matr->multiply(get_as_array(matr, i), scalar);
    
    return matr;
}

matrix* multiply_matrices(matrix* left, matrix* right)
{
	if (left->size != right->size || \
		left->elem_size != right->elem_size || \
		left->values == NULL    || right->values == NULL || \
		left->elem_zero == NULL || right->elem_zero == NULL)
		return NULL;
    
	matrix* matr = left->create_instance(left->size, NULL);
	void* value = calloc(left->elem_size, 1);
	void* mul_value = calloc(left->elem_size, 1);

	for (int i = 1; i <= left->size; i++)
		for (int j = 1; j <= left->size; j++)
		{
			memcpy(value, matr->elem_zero, matr->elem_size);
			for (int k = 1; k <= left->size; k++)
			{
				memcpy(mul_value, matr->elem_zero, matr->elem_size);
				matr->add(mul_value, get(left, i, k));
				matr->multiply(mul_value, get(right, k, j));
				matr->add(value, mul_value);
			}
			set(matr, i, j, value);
		}
	
	free(value);
	free(mul_value);

	memcpy(left->values, matr->values, matr->size * matr->size * matr->elem_size);
	return left;	
}

matrix* linear_combination(matrix* matr, int target_line, void* coefficients)
{
    void* mul_value = calloc(matr->elem_size, 1);

    for (int i = 1; i <= matr->size; i++)
    {
		if (i == target_line)
			continue;

        for (int j = 1; j <= matr->size; j++)
        {
			memcpy(mul_value, matr->elem_zero, matr->elem_size);

			matr->add(mul_value, (coefficients + (i-1)*matr->elem_size));
			// printf("\n");
			// matr->print(mul_value);
			// printf("\n");
			matr->multiply(mul_value, get(matr, i, j));
			matr->add(get(matr, target_line, j), mul_value);

			// print(matr);
            // value = matr->Sum(Get(matr, TargetLine, i), matr->Multiplication(Get(matr, j, i), (coefficients + (i-1))));
        }
    }
    return matr;
}