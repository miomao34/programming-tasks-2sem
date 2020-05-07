#pragma once

#include <iostream>

#define MAX_NODES_IN_LIST 1024

template<typename T>
class Node
{
private:
	T data;
	Node* next;
public:
	Node(T value);
	~Node();
	
	void SetValue(T item);
	T GetValue();
	void SetNext(Node<T>* node);
	Node<T>* GetNext();
	
	void Dump();
};

template<typename T>
class CircularList
{
private:
	Node<T>* Head;
	Node<T>* Current;
public:
	CircularList();
	CircularList(T head_value);
	// ~CircularList();
	
	bool Validate();
	T	GetCurrentValue();
	Node<T>* GetCurrent();
	Node<T>* Add(T item);
	Node<T>* GoNext();
	void RemoveNext();
	
	void Dump();
};