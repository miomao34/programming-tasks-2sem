#pragma once

#include "list.hpp"

template<typename T>
class Queue
{
private:
	DLList<T> data;
public:
	Queue();
	// ~Queue();
	
	void Push(T value);
	T Pop();
	
	void Dump();
};