#ifndef INT_H
#define INT_H

#include <stdio.h>

#include "vector.h"

vector* vector_int_ctor(unsigned int len, void* values);

void* vector_int_add(void* left, void* right);

void* vector_int_multiply(void* left, void* right);

void int_dump(void* value);

#endif