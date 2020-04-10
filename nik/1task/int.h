#ifndef INT_H
#define INT_H

#include <stdio.h>

#include "matrix.h"

matrix* matrix_int_create_instance(unsigned int size, void* values);

void* matrix_int_add(void* left, void* right);

void* matrix_int_multiply(void* left, void* right);

void int_print(void* value);

#endif