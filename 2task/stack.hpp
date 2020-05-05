#pragma once

#include <iostream>
#include <vector>
 
#define DEFAULT_SIZE 10
#define INCREMENT_THRESHOLD_MODIFIER 0.7
#define DECREMENT_THRESHOLD_MODIFIER 0.3

template<typename T>
class Stack
{
private:
	T* data;
	int current;
	uint size;
public:
	Stack();
	~Stack();
	
	void Push(T item);
	T    Pop();
	T    Peek(int i = 0);

	// for values
	template<typename _T>
	friend Stack<_T>& operator>> (Stack<_T>& stack, _T& value); 
	template<typename _T>
	friend Stack<_T>& operator<< (Stack<_T>& stack, _T value); 
	// for stacks
	template<typename _T>
	friend void operator>> (Stack<_T>& left, Stack<_T>& right); 
	template<typename _T>
	friend void operator<< (Stack<_T>& left, Stack<_T>& right); 

	T operator [] (uint i);

	int GetCurrent();
	void Dump();
};