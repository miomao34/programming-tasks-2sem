#include <stdexcept>

#include "list.hpp"
#include "complex.hpp"

using namespace std;

template<typename T>
Node<T>::Node(T value)
{
	this->SetValue(value);
}

template<typename T>
Node<T>::~Node()
{
	this->next = NULL;
	this->prev = NULL;
}

template<typename T>
void Node<T>::SetValue(T value)
{
	this->data = value;
}

template<typename T>
T Node<T>::GetValue()
{
	return this->data;
}

template<typename T>
void Node<T>::SetNext(Node<T>* next)
{		
	this->next = next;
}

template<typename T>
void Node<T>::SetPrev(Node<T>* prev)
{
	this->prev = prev;
}

template<typename T>
Node<T>* Node<T>::GetNext()
{
	return this->next;
}

template<typename T>
Node<T>* Node<T>::GetPrev()
{
	return this->prev;
}

template<typename T>
void Node<T>::Dump()
{
	// cout << '[' << this->data << ':' << this->next << ']' << "->";
	// cout << this->data << "->";
	if (this->prev != NULL)
		cout << "<";
	cout << this->data;
	if (this->next != NULL)
		cout << ">";
}


template<typename T>
DLList<T>::DLList()
{
	this->First = NULL;
	this->Last = NULL;
}

template<typename T>
DLList<T>::DLList(T first_value)
{
	this->First = new Node<T>(first_value);
	this->Last = this->First;
}

template<typename T>
Node<T>* DLList<T>::GetFirst()
{	
	return this->First;
}

template<typename T>
Node<T>* DLList<T>::GetLast()
{	
	return this->Last;
}

template<typename T>
Node<T>* DLList<T>::Append(T value)
{
	if (!this->Validate())
		throw runtime_error("Append: validation failed");
	
	if (this->Last == NULL)
	{
		this->Last = this->First = new Node<T>(value);
		return this->First;
	}

	this->Last->SetNext(new Node<T>(value));
	this->Last->GetNext()->SetPrev(this->Last);
	this->Last = this->Last->GetNext();

	return this->Last;
}

template<typename T>
Node<T>* DLList<T>::Prepend(T value)
{
	if (!this->Validate())
		throw runtime_error("Prepend: validation failed");
	
	if (this->First == NULL)
	{
		this->First = this->Last = new Node<T>(value);
		return this->Last;
	}
	this->First->SetPrev(new Node<T>(value));
	this->First->GetPrev()->SetNext(this->First);
	this->First = this->First->GetPrev();

	return this->First;
}

template<typename T>
void DLList<T>::RemoveFirst()
{
	if (!this->Validate())
		throw runtime_error("RemoveFirst: validation failed");

	if (this->First == NULL)
		throw runtime_error("RemoveFirst: removing nodes from empty list");

	if (this->First->GetNext() == NULL)
	{
		this->First->~Node();
		this->First = NULL;
		this->Last = NULL;
		return;
	}

	this->First = this->First->GetNext();
	this->First->GetPrev()->~Node();
	this->First->SetPrev(NULL);
}

template<typename T>
void DLList<T>::RemoveLast()
{
	if (!this->Validate())
		throw runtime_error("RemoveLast: validation failed");

	if (this->Last == NULL)
		throw runtime_error("RemoveLast: removing nodes from empty list");

	if (this->Last->GetPrev() == NULL)
	{
		this->Last->~Node();
		this->Last = NULL;
		this->First = NULL;
		return;
	}

	this->Last = this->Last->GetPrev();
	this->Last->GetNext()->~Node();
	this->Last->SetNext(NULL);
}

template<typename T>
bool DLList<T>::Validate()
{
	if (this->First == NULL && this->Last == NULL)
		return true;

	Node<T>* cursor  = this->First;
	int counter = 0;

	while (cursor != this->Last && counter < MAX_NODES_IN_LIST)
	{
		if (cursor == NULL)
			return false;
		cursor = cursor->GetNext();
		counter++;
	}

	if (cursor != this->Last)
		return false;

	counter = 0;
	while (cursor != this->First && counter < MAX_NODES_IN_LIST)
	{
		if (cursor == NULL)
			return false;
		cursor = cursor->GetPrev();
		counter++;
	}

	if (cursor != this->First)
		return false;

	return true;
}

template<typename T>
void DLList<T>::Dump()
{
	if (!this->Validate())
		throw runtime_error("Dump: validation failed");

	if (this->First == NULL && this->Last == NULL)
	{
		cout << "[NULL]\n";
		return;
	}
	
	Node<T>* curr = this->First;

	while(true)
	{
		// cout << "while in\n";
		curr->Dump();
		// cout << curr->GetValue() << " this: " << curr << " next: " << curr->GetNext() << '\n';
		curr = curr->GetNext();
		if (curr == this->Last || curr == NULL)
			break;
	}
	if (curr != NULL)
		curr->Dump();
	cout << "\n";
}



// instantiation
template class Node<int>;
template class DLList<int>;
template class Node<double>;
template class DLList<double>;
template class Node<Complex>;
template class DLList<Complex>;
template class Node<string>;
template class DLList<string>;