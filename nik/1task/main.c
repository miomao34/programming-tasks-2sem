#include <stdio.h>
#include "matrix.h"
#include "int.h"
#include "float.h"
#include <assert.h>

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define NO_COLOR "\033[0m"

void test_int_add()
{
	printf("%sTEST: add int matrices\n%s", YELLOW, NO_COLOR);
	
	int values1[] = {1,2,3,4,5,6,7,8,9};
	int values2[] = {10,11,12,13,14,15,16,17,18};
	matrix* matr1 = matrix_int_create_instance(3, values1);
	matrix* matr2 = matrix_int_create_instance(3, values2);
	int results[] = {11,13,15,17,19,21,23,25,27};

	print(matr1);
	printf("+\n");
	print(matr2);
	printf("=\n");

	add(matr1, matr2);
	print(matr1);

	for (int i = 0; i < 9; i++)
		assert (*(int*)get_as_array(matr1, i) == *(results + i));

	printf("%sTEST OK%s\n\n", GREEN, NO_COLOR);	
}

void test_int_multiply_scalar()
{
	printf("%sTEST: multiply int matrices on scalar\n%s", YELLOW, NO_COLOR);
	
	int values1[] = {1,2,3,4,5,6,7,8,9};
	matrix* matr1 = matrix_int_create_instance(3, values1);
	int results[] = {2,4,6,8,10,12,14,16,18};

	print(matr1);
	printf("*\n2\n=\n");

	int scalar = 2;
	multiply_on_scalar(matr1, &scalar);
	print(matr1);

	for (int i = 0; i < 9; i++)
		assert (*(int*)get_as_array(matr1, i) == *(results + i));

	printf("%sTEST OK%s\n\n", GREEN, NO_COLOR);	
}

void test_int_multiply_matrices()
{
	printf("%sTEST: multiply int matrices\n%s", YELLOW, NO_COLOR);
	
	int values1[] = {1,2,3,4,5,6,7,8,9};
	int values2[] = {9,8,7,6,5,4,3,2,1};
	matrix* matr1 = matrix_int_create_instance(3, values1);
	matrix* matr2 = matrix_int_create_instance(3, values2);
	int results[] = {30,24,18,84,69,54,138,114,90};

	print(matr1);
	printf("+\n");
	print(matr2);
	printf("=\n");

	multiply_matrices(matr1, matr2);
	print(matr1);

	for (int i = 0; i < 9; i++)
		assert (*(int*)get_as_array(matr1, i) == *(results + i));

	printf("%sTEST OK%s\n\n", GREEN, NO_COLOR);	
}

void test_int_linear_combination()
{
	printf("%sTEST: int matrix linear combination\n%s", YELLOW, NO_COLOR);
	
	int values1[] = {1,2,3,4,5,6,7,8,9};
	matrix* matr1 = matrix_int_create_instance(3, values1);
	int coef[] = {5,6,7};
	int results[] = {1,2,3,58,71,84,7,8,9};

	print(matr1);
	printf("*\n");
	printf("%d _ %d\n", coef[0], coef[2]);
	printf("=\n");

	linear_combination(matr1, 2, coef);
	print(matr1);

	for (int i = 0; i < 9; i++)
		assert (*(int*)get_as_array(matr1, i) == *(results + i));

	printf("%sTEST OK%s\n\n", GREEN, NO_COLOR);	
}

void test_float_add()
{
	printf("%sTEST: add float matrices\n%s", YELLOW, NO_COLOR);
	
	float values1[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	float values2[] = {10.0,11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0};
	matrix* matr1 = matrix_float_create_instance(3, values1);
	matrix* matr2 = matrix_float_create_instance(3, values2);
	float results[] = {11.0,13.0,15.0,17.0,19.0,21.0,23.0,25.0,27.0};

	print(matr1);
	printf("+\n");
	print(matr2);
	printf("=\n");

	add(matr1, matr2);
	print(matr1);

	for (int i = 0; i < 9; i++)
		assert (*(float*)get_as_array(matr1, i) == *(results + i));

	printf("%sTEST OK%s\n\n", GREEN, NO_COLOR);	
}

void test_float_multiply_scalar()
{
	printf("%sTEST: multiply float matrices on scalar\n%s", YELLOW, NO_COLOR);
	
	float values1[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	matrix* matr1 = matrix_float_create_instance(3, values1);
	float results[] = {2.0,4.0,6.0,8.0,10.0,12.0,14.0,16.0,18.0};

	print(matr1);
	printf("*\n2\n=\n");

	float scalar = 2;
	multiply_on_scalar(matr1, &scalar);
	print(matr1);

	for (int i = 0; i < 9; i++)
		assert (*(float*)get_as_array(matr1, i) == *(results + i));

	printf("%sTEST OK%s\n\n", GREEN, NO_COLOR);	
}

void test_float_multiply_matrices()
{
	printf("%sTEST: multiply float matrices\n%s", YELLOW, NO_COLOR);
	
	float values1[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	float values2[] = {9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0};
	matrix* matr1 = matrix_float_create_instance(3, values1);
	matrix* matr2 = matrix_float_create_instance(3, values2);
	float results[] = {30.0,24.0,18.0,84.0,69.0,54.0,138.0,114.0,90.0};

	print(matr1);
	printf("+\n");
	print(matr2);
	printf("=\n");

	multiply_matrices(matr1, matr2);
	print(matr1);

	for (int i = 0; i < 9; i++)
		assert (*(float*)get_as_array(matr1, i) == *(results + i));

	printf("%sTEST OK%s\n\n", GREEN, NO_COLOR);	
}

void test_float_linear_combination()
{
	printf("%sTEST: float matrix linear combination\n%s", YELLOW, NO_COLOR);
	
	float values1[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	matrix* matr1 = matrix_float_create_instance(3, values1);
	float coef[] = {5.0,6.0,7.0};
	float results[] = {1.0,2.0,3.0,58.0,71.0,84.0,7.0,8.0,9.0};

	print(matr1);
	printf("*\n");
	printf("%f _ %f\n", coef[0], coef[2]);
	printf("=\n");

	linear_combination(matr1, 2, coef);
	print(matr1);

	for (int i = 0; i < 9; i++)
		assert (*(float*)get_as_array(matr1, i) == *(results + i));

	printf("%sTEST OK%s\n\n", GREEN, NO_COLOR);	
}


int main(int argc, char** argv)
{
	test_int_add();
	test_int_multiply_scalar();
	test_int_multiply_matrices();
	test_int_linear_combination();

	test_float_add();
	test_float_multiply_scalar();
	test_float_multiply_matrices();
	test_float_linear_combination();
}