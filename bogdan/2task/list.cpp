#include "list.hpp"
#include "complex.hpp"
#include <stdexcept>

template<typename T>
Node<T>::Node(T value)
{
	this->SetValue(value);
}

template<typename T>
Node<T>::~Node()
{
	this->next = NULL;
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
	if (next == NULL)
		throw std::runtime_error("cannot set next: next is NULL");
		
	this->next = next;
}

template<typename T>
Node<T>* Node<T>::GetNext()
{
	// std::cout << "get next for val " << this->data << '\n';
	if (this->next == NULL)
		throw std::runtime_error("cannot get next: next is NULL");
		
	return this->next;
}

template<typename T>
void Node<T>::Dump()
{
	std::cout << this->data << "->";
}


template<typename T>
CircularList<T>::CircularList()
{
	this->Head = NULL;
	this->Current = NULL;
}

template<typename T>
CircularList<T>::CircularList(T head_value)
{
	this->Head = new Node<T>(head_value);
	this->Current = this->Head;
	this->Head->SetNext(this->Head);
}

template<typename T>
bool CircularList<T>::Validate()
{
	if (this->Head == NULL && this->Current == NULL)
		return true;

	if (this->Head->GetNext() == this->Head && this->GetCurrent() == this->Head)
		return true;
	
	Node<T>* test_current = this->Head->GetNext();
	int nodes_left = MAX_NODES_IN_LIST;

	while (true)
	{
		if (test_current == this->Head)
			break;
		if (test_current->GetNext() == NULL || nodes_left <= 0)
			return false;

		nodes_left--;
		test_current = test_current->GetNext()	;
	}
	return true;
}

template<typename T>
T CircularList<T>::GetCurrentValue()
{
	if (!this->Validate())
		throw std::runtime_error("GetCurrentValue: validation failed");
	
	return this->Current->GetValue();
}

template<typename T>
Node<T>* CircularList<T>::GetCurrent()
{	
	return this->Current;
}

template<typename T>
Node<T>* CircularList<T>::Add(T value)
{
	if (this->Current == NULL && this->Head == NULL)
	{
		this->Head = this->Current = new Node<T>(value);
		this->Current->SetNext(this->Current);

		return this->Current;
	}

	if (!this->Validate())
		throw std::runtime_error("Add: validation failed");
	
	Node<T>* next = this->GetCurrent()->GetNext();
	Node<T>* node = new Node<T>(value);
	node->SetNext(next);
	this->GetCurrent()->SetNext(node);
	this->GoNext();

	return node;
}

template<typename T>
Node<T>* CircularList<T>::GoNext()
{
	if (!this->Validate())
		throw std::runtime_error("GoNext: validation failed");

	this->Current = this->Current->GetNext();
}

template<typename T>
void CircularList<T>::RemoveNext()
{
	if (!this->Validate())
		throw std::runtime_error("RemoveNext: validation failed");

	if(this->Head == this->Current && this->Head->GetNext() == this->Head)
	{
		this->Head->~Node();
		this->Head = this->Current = NULL;
		return;
	}
	
	Node<T>* new_next1 = this->Current->GetNext();
	Node<T>* new_next2 = new_next1->GetNext();
	this->Current->GetNext()->~Node();
	this->Current->SetNext(new_next2);
}

template<typename T>
void CircularList<T>::Dump()
{
	if (this->Head == NULL && this->Current == NULL)
	{
		std::cout << "[NULL]\n";
		return;
	}

	if (!this->Validate())
		throw std::runtime_error("Dump: validation failed");
	
	Node<T>* curr = this->Head;

	while(true)
	{
		// std::cout << "while in\n";
		curr->Dump();
		// std::cout << curr->GetValue() << " this: " << curr << " next: " << curr->GetNext() << '\n';
		curr = curr->GetNext();
		if (curr == this->Head)
			break;
	}
	std::cout << "[head]\n";
}



// instantiation
template class Node<int>;
template class CircularList<int>;
template class Node<double>;
template class CircularList<double>;
template class Node<Complex>;
template class CircularList<Complex>;
template class Node<std::string>;
template class CircularList<std::string>;