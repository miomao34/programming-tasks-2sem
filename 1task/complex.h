#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>

#include "vector.h"

typedef struct _complex
{
	double re;
	double im;
} complex;


vector* vector_complex_ctor(unsigned int len, void* values);

void* vector_complex_add(void* left, void* right);

void* vector_complex_multiply(void* left, void* right);

void complex_dump(void* value);

#endif