#ifndef FLOAT_H
#define FLOAT_H

#include <stdio.h>

#include "matrix.h"

matrix* matrix_float_create_instance(unsigned int size, void* values);

void* matrix_float_add(void* left, void* right);

void* matrix_float_multiply(void* left, void* right);

void float_print(void* value);

#endif