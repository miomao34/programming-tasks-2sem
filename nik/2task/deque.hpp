#pragma once

#ifndef DEFAULT_SIZE
	#define DEFAULT_SIZE 10
#endif

#ifndef EXPAND_SIZE
	#define EXPAND_SIZE 10
#endif

#ifndef EXPAND_RATIO
	#define EXPAND_RATIO 0.8
#endif

template <typename T>
class Deque
{
private:
	T* data;
	int size;
	int nextCurrentStart;
	int nextCurrentEnd;

	void expand();
public:
	Deque();
	~Deque();

	void Prepend(T value);
	void Append(T value);

	T PopStart();
	T PopEnd();
	T PeekStart();
	T PeekEnd();

	int GetSize();

	bool IsEmpty();
	void Print();
};