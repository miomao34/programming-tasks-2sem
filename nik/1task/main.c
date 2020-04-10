#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "matrix.h"
#include "int.h"
#include "float.h"
#include "tests.h"

enum TYPES
{
	INT,
	FLOAT
};

typedef struct _config
{
	int size;
	int type;
} config;

void tests()
{
	test_int_add();
	test_int_add_negative();
	
	test_int_multiply_scalar();
	test_int_multiply_scalar_negative();
	
	test_int_multiply_matrices();
	test_int_multiply_matrices_negative();
	
	test_int_linear_combination();
	test_int_linear_combination_negative();


	test_float_add();
	test_float_add_negative();

	test_float_multiply_scalar();
	test_float_multiply_scalar_negative();
	
	test_float_multiply_matrices();
	test_float_multiply_matrices_negative();
	
	test_float_linear_combination();
	test_float_linear_combination_negative();
}

void initial_menu()
{
	int option = 0;
	while (true)
	{
		printf("choose an option:\n\
		[0] enter operations menu\n\
		[1] run tests\n\
		[2] exit\n");

		scanf("%d", &option);
		switch(option)
		{
		case 0:
			return;
		case 1:
			tests();
		case 2:
			exit(0);
		
		default:
			printf("wrong option\n");
			continue;
		}
	}
}

config* read_config()
{
	config* cfg = calloc(sizeof(config), 1);
	int option = 0;
	while (true)
	{
		printf("enter type:\n\
		[%d] int\n\
		[%d] float\n", INT, FLOAT);

		scanf("%d", &option);
		switch(option)
		{
		case INT:
			cfg->type = INT;
			break;
		case FLOAT:
			cfg->type = FLOAT;
			break;
		
		default:
			printf("wrong type\n");
			continue;
		}
		break;
	}
	
	printf("enter matrix size:\n");
	scanf("%d", &(cfg->size));

	return cfg;
}

matrix* read_matrix(config* cfg, char* message)
{
	printf("%s", message);

	void* values = NULL;
	matrix* matr = NULL;
	switch (cfg->type)
	{
	case INT:
		values = calloc(cfg->size*cfg->size, sizeof(int));
		for (int i = 0; i < cfg->size*cfg->size; i++)
			scanf("%d", (int*)(values + i*sizeof(int)));
		
		matr = matrix_int_create_instance(cfg->size, values);
		break;

	case FLOAT:
		values = calloc(cfg->size*cfg->size, sizeof(float));
		for (int i = 0; i < cfg->size*cfg->size; i++)
			scanf("%f", (float*)(values + i*sizeof(float)));
		
		matr = matrix_float_create_instance(cfg->size, values);
		break;
	
	default:
		printf("wrong config! aborting\n");
		exit(-1);
	}

	return matr;
}

void menu_add(config* cfg, matrix* left, matrix* right)
{
	print(left);
	printf("+\n");
	print(right);
	printf("=\n");

	add(left, right);
	print(left);
}

void menu_multiply_scalar(config* cfg, matrix* left)
{
	printf("enter scalar:\n");

	void* scalar = NULL;
	switch(cfg->type)
	{
	case INT:
		scalar = calloc(1, sizeof(int));
		scanf("%d", (int*)scalar);
		break;

	case FLOAT:
		scalar = calloc(1, sizeof(float));
		scanf("%f", (float*)scalar);
		break;

	default:
		printf("wrong config! aborting\n");
		exit(-1);
	}

	print(left);
	printf("*\n");
	if (cfg->type == INT)
		printf("%d\n", *((int*)scalar));
	else
		printf("%f\n", *((float*)scalar));
	// printf(cfg->type == INT ? "%d\n", *((int*)scalar) : "%f\n", *((float*)scalar));
	printf("=\n");

	multiply_on_scalar(left, scalar);
	print(left);
}

void menu_multiply_matrices(config* cfg, matrix* left, matrix* right)
{
	print(left);
	printf("*\n");
	print(right);
	printf("=\n");

	multiply_matrices(left, right);
	print(left);
}

void menu_linear_combination(config* cfg, matrix* left)
{
	int target_line = 0;
	printf("enter target line:");
	scanf("%d", &target_line);

	printf("enter coefficients, with any value on target line\n");

	void* coef = NULL;
	matrix* matr = NULL;
	switch (cfg->type)
	{
	case INT:
		coef = calloc(cfg->size, sizeof(int));
		for (int i = 0; i < cfg->size; i++)
			scanf("%d", (int*)(coef + i*sizeof(int)));
		break;

	case FLOAT:
		coef = calloc(cfg->size, sizeof(float));
		for (int i = 0; i < cfg->size; i++)
			scanf("%f", (float*)(coef + i*sizeof(float)));
		break;
	
	default:
		printf("wrong config! aborting\n");
		exit(-1);
	}

	print(left);
	printf("*\n");
	if (cfg->type == INT)
		printf("%d _ %d\n", *((int*)coef), *((int*)(coef + 2*sizeof(int))));
	else
		printf("%f _ %f\n", *((float*)coef), *((float*)(coef + 2*sizeof(float))));
	printf("=\n");

	linear_combination(left, target_line, coef);
	print(left);	
}

void menu(config* cfg, matrix* left, matrix* right)
{
	int option = 0;
	while (true)
	{
		printf("choose an operation:\n\
		[0] re-enter the config and matrices\n\
		[1] re-enter the matrices\n\
		[2] add the first matrix to the second\n\
		[3] multiply the first matrix on scalar\n\
		[4] multiply the first matrix on the second\n\
		[5] linear combination of the first matrix\n\
		[6] print matrices\n\
		[7] exit\n");

		scanf("%d", &option);
		switch(option)
		{
		case 0:
			cfg = read_config();
		case 1:
			left =  read_matrix(cfg, "enter first matrix\n");
			right = read_matrix(cfg, "enter second matrix\n");
			break;
		case 2:
			menu_add(cfg, left, right);
			break;
		case 3:
			menu_multiply_scalar(cfg, left);
			break;
		case 4:
			menu_multiply_matrices(cfg, left, right);
			break;
		case 5:
			menu_linear_combination(cfg, left);
			break;
		case 6:
			printf("first:\n");
			print(left);
			printf("second:\n");
			print(right);
			break;
		case 7:
			return;
		
		default:
			printf("wrong operation\n");
			continue;
		}
	}
}

int main(int argc, char* argv[])
{
	initial_menu();
	config* cfg = read_config();
	// printf("%d %d\n", cfg->size, cfg->type);

	matrix* matr1 = read_matrix(cfg, "enter first matrix\n");
	matrix* matr2 = read_matrix(cfg, "enter second matrix\n");

	menu(cfg, matr1, matr2);
}