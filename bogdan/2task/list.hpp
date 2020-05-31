#pragma once

#include <iostream>

#define MAX_NODES_IN_LIST 1024

template<typename T>
class Node
{
private:
	T data;
	Node* next;
	Node* prev;
public:
	Node(T value);
	~Node();
	
	void SetValue(T item);
	T GetValue();
	void SetNext(Node<T>* next);
	void SetPrev(Node<T>* prev);
	Node<T>* GetNext();
	Node<T>* GetPrev();
	
	void Dump();
};

template<typename T>
class DLList
{
private:
	Node<T>* First;
	Node<T>* Last;
	// Node<T>* Current;
public:
	DLList();
	DLList(T head_value);
	// ~DLList();
	
	bool Validate();
	// Node<T>* GetCurrent();
	Node<T>* GetFirst();
	Node<T>* GetLast();
	Node<T>* Append(T item);
	Node<T>* Prepend(T item);
	// Node<T>* AddAfterCurrent(T item);
	// Node<T>* AddBeforeCurrent(T item);
	// Node<T>* GoNext();
	// Node<T>* GoPrev();
	// void RemoveCurrent();
	void RemoveFirst();
	void RemoveLast();
	
	void Dump();
};