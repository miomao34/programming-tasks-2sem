#include "stack.hpp"

template<typename T>
Stack<T>::Stack()
{
	this->current = -1;
	this->size = DEFAULT_SIZE;
	this->data = (T*)calloc(DEFAULT_SIZE, sizeof(T));
}

template<typename T>
Stack<T>::~Stack()
{
	this->current = -1;
	this->size = -1;
	free(this->data);
}

template<typename T>
void Stack<T>::Push(T item)
{
	this->current++;
	if (this->current > this->size * INCREMENT_THRESHOLD_MODIFIER)
	{
		this->size = this->size * 2;
		this->data = (T*)realloc((void*)this->data, sizeof(T)*this->size);
	}
	this->data[this->current] = item;
}

template<typename T>
T Stack<T>::Pop()
{
	if (this->current == -1)
		throw "stack is empty!";
		
	return this->data[this->current--];
}

template<typename T>
T Stack<T>::Peek(int i)
{
	if (this->current == -1)
		throw "stack is empty!";

	if (this->current - i < 0 || i < 0)
		throw "trying to access invalid item";
		
	return this->data[this->current - i];
}

template<typename T>
Stack<T>& operator>> (Stack<T>& stack, T& value)
{
	value = stack.Pop();
	return stack;
}

template<typename T>
Stack<T>& operator<< (Stack<T>& stack, T value)
{
	stack.Push(value);
	return stack;
}

template<class _T>
void operator<< (Stack<_T>& left, Stack<_T>& right)
{
	left.Push(right.Pop());
}

template<class _T>
void operator>> (Stack<_T>& left, Stack<_T>& right)
{
	right.Push(left.Pop());
}

template<typename T>
T Stack<T>::operator [] (uint i)
{
	return this->Peek(i);
}

template<typename T>
int Stack<T>::GetCurrent()
{
	return this->current;
}

template<typename T>
void Stack<T>::Dump()
{
	for (int i = 0; i <= this->current; i++)
		std::cout << this->data[i] << ' ';
	std::cout << '\n';
}

// instantiation
template class Stack<int>;
template Stack<int>& operator>> (Stack<int>& stack, int& value);
template Stack<int>& operator<< (Stack<int>& stack, int value);
template void operator<< (Stack<int>& left, Stack<int>& right);
template void operator>> (Stack<int>& left, Stack<int>& right);