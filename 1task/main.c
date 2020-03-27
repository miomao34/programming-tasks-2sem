#include <stdio.h>
#include "vector.h"
#include "int.h"
#include "float.h"
#include <assert.h>

void test_int_add()
{
	int values1[] = {1,2,3};
	int values2[] = {4,5,6};
	int results[] = {5,7,9};

	vector* int_vec_1 = vector_int_ctor(3, values1);
	vector* int_vec_2 = vector_int_ctor(3, values2);
	
	print(int_vec_1);
	printf("+\n");
	print(int_vec_2);
	printf("=\n");

	add(int_vec_1, int_vec_2);

	print(int_vec_1);	
	printf("\n");

	for (int i=0; i<3; i++)
		assert (*((int*)(get(int_vec_1, i))) == results[i]);

	dtor(int_vec_1);
	dtor(int_vec_2);
}

void test_int_scalar_multiply()
{	
	int scalar = 3;
	int values1[] = {1,2,3};
	int results[] = {3,6,9};

	vector* int_vec_1 = vector_int_ctor(3, values1);
	
	print(int_vec_1);

	printf("multiplying by 3\n");
	assert (multiply_on_scalar(int_vec_1, &scalar) != NULL);

	print(int_vec_1);	
	printf("\n");

	for (int i=0; i<3; i++)
		assert (*((int*)(get(int_vec_1, i))) == results[i]);

	dtor(int_vec_1);
}

void test_float_add()
{
	float values1[] = {1.0,2.0,3.0};
	float values2[] = {4.0,5.0,6.0};
	float results[] = {5.0,7.0,9.0};

	vector* float_vec_1 = vector_float_ctor(3, values1);
	vector* float_vec_2 = vector_float_ctor(3, values2);
	
	print(float_vec_1);
	printf("+\n");
	print(float_vec_2);
	printf("=\n");

	add(float_vec_1, float_vec_2);

	print(float_vec_1);	
	printf("\n");

	for (int i=0; i<3; i++)
		assert (*((float*)(get(float_vec_1, i))) == results[i]);

	dtor(float_vec_1);
	dtor(float_vec_2);
}

void test_float_scalar_multiply()
{	
	float scalar = 3.0;
	float values1[] = {1.0,2.0,3.0};
	float results[] = {3.0,6.0,9.0};

	vector* float_vec_1 = vector_float_ctor(3, values1);
	
	print(float_vec_1);

	printf("multiplying by 3\n");
	assert (multiply_on_scalar(float_vec_1, &scalar) != NULL);

	print(float_vec_1);	
	printf("\n");

	for (int i=0; i<3; i++)
		assert (*((float*)(get(float_vec_1, i))) == results[i]);

	dtor(float_vec_1);
}

int main(int argc, char** argv)
{
	printf("Test 1: int add\n");
	test_int_add();
	printf("Test 1 OK\n\n\n");
	
	printf("Test 2: int scalar multiply\n");
	test_int_scalar_multiply();
	printf("Test 2 OK\n\n\n");

	printf("Test 3: float add\n");
	test_float_add();
	printf("Test 3 OK\n\n\n");

	printf("Test 4: float scalar multiply\n");
	test_float_scalar_multiply();
	printf("Test 4 OK\n\n\n");
}