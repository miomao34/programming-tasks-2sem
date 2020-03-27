#ifndef FLOAT_H
#define FLOAT_H

#include <stdio.h>

#include "vector.h"

vector* vector_float_ctor(unsigned int len, void* values);

void* vector_float_add(void* left, void* right);

void* vector_float_multiply(void* left, void* right);

void float_dump(void* value);

#endif