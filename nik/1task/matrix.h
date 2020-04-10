#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix matrix;
struct matrix {
	unsigned int size;
	void * values;

	unsigned int elem_size;
	void * elem_zero;

	matrix* (*create_instance)(unsigned int size, void* values);
	void* (*add)(void* left, void* right);
	void* (*multiply)(void* left, void* right);
	void  (*print)(void* value);
};

matrix* common_create_instance(
		matrix* this,
		unsigned int size,
		unsigned int elem_size,
		matrix* (*create_instance)(unsigned int size, void* values),
		void* (*add)(void* left, void* right),
		void* (*multiply)(void* left, void* right),
		void  (*print)(void* value),
		void* zero,
		void* values);

matrix* copy(matrix* matr);

void print(matrix* matr);

void* get(matrix* matr, int line, int column);

void* get_as_array(matrix* matr, int i);

void set(matrix* matr, int line, int column, void* value);

void set_as_array(matrix* matr, int index, void* value);

matrix* add(matrix* left, matrix* right);

matrix* multiply_on_scalar(matrix* matr, void* scalar);

matrix* multiply_matrices(matrix* left, matrix* right);

matrix* linear_combination(matrix* matr, int target_line, void* coefficients);

#endif