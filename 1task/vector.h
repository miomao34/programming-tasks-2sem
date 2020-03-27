#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector vector;
struct vector {
	unsigned int length;
	void * values;

	unsigned int elem_size;
	void * elem_zero;

	vector* (*ctor)(unsigned int len, void* values);
	void    (*dtor)(vector* this);
	void* (*add)(void* left, void* right);
	void* (*multiply)(void* left, void* right);
	void  (*dump)(void* value);
};

vector* common_ctor(
		vector* this,
		unsigned int len,
		unsigned int elem_size,
		vector* (*ctor)(unsigned int len, void* values),
		void* (*add)(void* left, void* right),
		void* (*multiply)(void* left, void* right),
		void (*dump)(void* value),
		void* zero,
		void* values);

void dtor(vector* this);

void print(vector* vect);

void* get(vector* vect, int i);

void set(vector* vect, int index, void* value);

vector* add (vector* left, vector* right);

vector* multiply_on_scalar (vector* vect, void* scalar);


#endif