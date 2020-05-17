#include "deque.hpp"

#include <iostream>
#include <stdexcept>
#include <string.h>

template <typename T>
Deque<T>::Deque()
{
	// ???
	this->size = DEFAULT_SIZE;
	this->nextCurrentStart = this->size;
	this->nextCurrentEnd = this->size;
	this->data = (T*)calloc(DEFAULT_SIZE*2+1, sizeof(T));
}

template <typename T>
Deque<T>::~Deque()
{
	this->nextCurrentStart = -1;
	this->nextCurrentEnd = -1;
	this->size = -1;
	free(this->data);
}

template <typename T>
void Deque<T>::expand()
{
	T* newbuffer = (T*)calloc(1 + this->size * 2 + EXPAND_SIZE * 2, sizeof(T));
	memcpy(newbuffer+EXPAND_SIZE, this->data, sizeof(T)*(this->size*2+1));
	free(this->data);

	this->nextCurrentEnd += EXPAND_SIZE;
	this->nextCurrentStart += EXPAND_SIZE;
	this->data = newbuffer;
	this->size += EXPAND_SIZE;
}

template <typename T>
void Deque<T>::Prepend(T value)
{
	if (this->IsEmpty())
	{
		this->data[this->size] = value;
		this->nextCurrentEnd++;
		this->nextCurrentStart--;
		return;
	}
	
	// expansion
	if ((this->size - this->nextCurrentStart) >= this->size * EXPAND_RATIO)
		this->expand();

	this->data[this->nextCurrentStart] = value;
	this->nextCurrentStart--;
}

template <typename T>
void Deque<T>::Append(T value)
{
	if (this->IsEmpty())
	{
		this->data[this->size] = value;
		this->nextCurrentEnd++;
		this->nextCurrentStart--;
		return;
	}
	
	// expansion
	if ((this->nextCurrentStart - this->size) >= this->size * EXPAND_RATIO)
		this->expand();

	this->data[this->nextCurrentEnd] = value;
	this->nextCurrentEnd++;
}

template <typename T>
T Deque<T>::PopStart()
{
	if (this->IsEmpty())
		throw std::runtime_error("deque is empty!");

	if(this->nextCurrentEnd - this->nextCurrentStart == 2)
	{
		T value = this->data[nextCurrentStart+1];
		this->nextCurrentStart = this->nextCurrentEnd = this->size;
		return value;
	}

	this->nextCurrentStart++;
	return this->data[this->nextCurrentStart];
}

template <typename T>
T Deque<T>::PopEnd()
{
	if (this->IsEmpty())
		throw std::runtime_error("deque is empty!");

	if(this->nextCurrentEnd - this->nextCurrentStart == 2)
	{
		T value = this->data[nextCurrentEnd-1];
		this->nextCurrentStart = this->nextCurrentEnd = this->size;
		return value;
	}

	this->nextCurrentEnd--;
	return this->data[this->nextCurrentEnd];
}

template <typename T>
T Deque<T>::PeekStart()
{
	if (this->IsEmpty())
		throw std::runtime_error("deque is empty!");

	return this->data[this->nextCurrentStart+1];
}

template <typename T>
T Deque<T>::PeekEnd()
{
	if (this->IsEmpty())
		throw std::runtime_error("deque is empty!");

	return this->data[this->nextCurrentEnd-1];
}

template <typename T>
bool Deque<T>::IsEmpty()
{
	return (this->nextCurrentEnd == this->nextCurrentStart);
}

template <typename T>
int Deque<T>::GetSize()
{
	return this->size;
}

template <typename T>
void Deque<T>::Print()
{
	if(this->IsEmpty())
	{
		std::cout << "[empty]" << std::endl;
		return;
	}

	for(int i = this->nextCurrentStart+1; i < this->nextCurrentEnd; i++)
		std::cout << this->data[i] << ' ';

	std::cout << std::endl;
}

template class Deque<int>;