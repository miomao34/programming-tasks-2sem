#include <stdexcept>

#include "queue.hpp"
#include "complex.hpp"

using namespace std;

template <typename T>
Queue<T>::Queue()
{
	this->data = DLList<T>();
}

template <typename T>
void Queue<T>::Push(T value)
{
	this->data.Prepend(value);
}

template <typename T>
T Queue<T>::Pop()
{
	if (this->data.GetLast() == NULL)
		throw runtime_error("Pop: can't pop from empty queue");
	T value = this->data.GetLast()->GetValue();
	this->data.RemoveLast();
	return value;
}

template <typename T>
void Queue<T>::Dump()
{
	cout << "q: ";
	this->data.Dump();
}

// instantiation
template class Queue<int>;
template class Queue<double>;
template class Queue<Complex>;
template class Queue<string>;