#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

enum MODES
{
	CL,
	CR,
	LC,
	RC
};

template<typename T>
class Node
{
private:
	T data;

	Node* parent;
	Node** children;
public:
	Node(T value, int num_of_children);
	~Node();
	
	void SetValue(T item);
	T GetValue();

	void SetParent(Node<T>* parent);
	void SetChild(Node<T>* node, int id);

	Node<T>* GetParent();
	Node<T>* GetChild(int id);

	Node<T>* AddChild(T value, int id, int number_of_children);
	
	void Dump();
};

template<typename T>
Node<T>::Node(T value, int num_of_children)
{
	this->parent = NULL;
	this->children = (Node<T>**)calloc(num_of_children, sizeof(Node<T>*));
	this->SetValue(value);
}

template<typename T>
Node<T>::~Node()
{
	this->parent = NULL;
	free(this->children);
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
void Node<T>::SetParent(Node<T>* parent)
{
	this->parent = parent;
}

template<typename T>
void Node<T>::SetChild(Node<T>* node, int id)
{
	this->children[id] = node;
}

template<typename T>
Node<T>* Node<T>::GetParent()
{
	return this->parent;
}

template<typename T>
Node<T>* Node<T>::GetChild(int id)
{
	return this->children[id];
}

template<typename T>
Node<T>* Node<T>::AddChild(T value, int id, int number_of_children)
{
	if (this->children[id] != NULL)
		throw std::runtime_error(std::string("AddChild: child is not NULL: ").append(std::to_string(id)));
	
	this->children[id] = new Node<T>(value, number_of_children);
	this->children[id]->parent = this;

	return this->children[id];
}

template<typename T>
class NTree
{
private:
	Node<T>* root;
	Node<T>* current;
	int n;

	void deleteSubTree(Node<T>* node);
	int getSize(Node<T>* node);
	std::string getString(Node<T>* node);
	T* walk(T* values, int* i, int mode, Node<T>* node);
	Node<T>* copyNodes();
	Node<T>* copyNodesRecursive(Node<T>* node);

public:
	NTree(T rootvalue, int n);
	~NTree();
	void DeleteSubTree();

	// bool OK();
	
	Node<T>* GetCurrent();
	Node<T>* GetRoot();
	Node<T>* SetCurrent(Node<T>* node);
	Node<T>* GoUp();
	Node<T>* GoToChild(int id);
	Node<T>* AddChild(T value, int id);

	int GetSize();

	T* Walk(int mode);

	Node<T>* AddTreeToChild(NTree<T>* tree, int id);

	std::string GetString();
	void Print();	
};

template<typename T>
NTree<T>::NTree(T rootvalue, int n)
{
	this->n = n;
	this->root = this->current = new Node<T>(rootvalue, n);
}

template<typename T>
NTree<T>::~NTree()
{
	this->SetCurrent(this->root);
	DeleteSubTree();
	this->root = this->current = NULL;
}

template<typename T>
void NTree<T>::deleteSubTree(Node<T>* node)
{
	if (node->GetParent() != NULL)
	{
		bool ok = false;
		for (int i=0; i < this->n; i++)
			if(node->GetParent()->GetChild(i) == node)
			{
				ok = true;
				node->GetParent()->SetChild(NULL, i);
			}
		if (!ok)
			throw std::runtime_error("DeleteSubTree: node's parent doesn't have node as a child");
	}


	for (int i=0; i < this->n; i++)
		if(node->GetChild(i) != NULL)
			this->deleteSubTree(node->GetChild(i));

	node->~Node();
}

template<typename T>
void NTree<T>::DeleteSubTree()
{
	// if (this->current->GetParent() == NULL)
	// 	throw std::runtime_error("DeleteSubTree: parent is NULL");

	Node<T>* parent = this->current->GetParent();
	this->deleteSubTree(this->current);
	this->current = parent;
}

template<typename T>
Node<T>* NTree<T>::GetCurrent()
{
	return this->current;
}

template<typename T>
Node<T>* NTree<T>::GetRoot()
{
	return this->root;
}

template<typename T>
Node<T>* NTree<T>::SetCurrent(Node<T>* node)
{
	this->current = node;
	return node;
}

template<typename T>
Node<T>* NTree<T>::GoUp()
{
	if (this->current->GetParent() == NULL)
		throw std::runtime_error("GoUp: parent is NULL");
	this->current = this->current->GetParent();
	return this->current;
}

template<typename T>
Node<T>* NTree<T>::GoToChild(int id)
{
	if (this->current->GetChild(id) == NULL)
		throw std::runtime_error(std::string("GoToChild: child is NULL: ").append(std::to_string(id)));
	this->current = this->current->GetChild(id);
	return this->current;
} 

template<typename T>
Node<T>* NTree<T>::AddChild(T value, int id)
{
	if (this->current->GetChild(id) != NULL)
		throw std::runtime_error(std::string("AddChild: child is not NULL: ").append(std::to_string(id)));
	this->current->AddChild(value, id, this->n);
	// this->current = this->current->GetLeft();
	return this->current;
}

template<typename T>
int NTree<T>::getSize(Node<T>* node)
{
	int num = 1;

	for (int i = 0; i < this->n; i++)
		if (node->GetChild(i) != NULL)
			num += this->getSize(node->GetChild(i));
	
	return num;
}

template<typename T>
int NTree<T>::GetSize()
{
	return this->getSize(this->root);
}

template<typename T>
T* NTree<T>::walk(T* values, int* j, int mode, Node<T>* node)
{
	switch (mode)
	{
	case CL:
		values[*j] = node->GetValue();
		*j = *j + 1;
		for (int i = 0; i < this->n; i++)
			if (node->GetChild(i) != NULL)
				this->walk(values, j, mode, node->GetChild(i));
		break;
	case CR:
		values[*j] = node->GetValue();
		*j = *j + 1;
		for (int i = this->n - 1; i >= 0; i--)
			if (node->GetChild(i) != NULL)
				this->walk(values, j, mode, node->GetChild(i));
		break;
	case LC:
		for (int i = 0; i < this->n; i++)
			if (node->GetChild(i) != NULL)
				this->walk(values, j, mode, node->GetChild(i));
		values[*j] = node->GetValue();
		*j = *j + 1;
		break;
	case RC:
		for (int i = this->n - 1; i >= 0; i--)
			if (node->GetChild(i) != NULL)
				this->walk(values, j, mode, node->GetChild(i));
		values[*j] = node->GetValue();
		*j = *j + 1;
		break;
	
	default:
		throw std::runtime_error("Walk: invalid mode");
		break;
	}

	return values;
}

template<typename T>
T* NTree<T>::Walk(int mode)
{
	T* values = (T*)calloc(this->GetSize(), sizeof(T));
	int i = 0;

	return this->walk(values, &i, mode, this->root);
}

template<typename T>
Node<T>* NTree<T>::copyNodesRecursive(Node<T>* node)
{
	Node<T>* newNode = new Node<T>(node->GetValue(), this->n);
	
	for (int i = 0; i < this->n; i++)
		if (node->GetChild(i) != NULL)
			newNode->SetChild(this->copyNodesRecursive(node->GetChild(i)), i);

	return newNode;
}

template<typename T>
Node<T>* NTree<T>::copyNodes()
{
	return copyNodesRecursive(this->GetRoot());
}

template<typename T>
Node<T>* NTree<T>::AddTreeToChild(NTree<T>* tree, int i)
{
	if (this->current->GetChild(i) != NULL)
		throw std::runtime_error(std::string("AddTreeToChild: child is not NULL: ").append(std::to_string(i)));
	
	Node<T>* node = tree->copyNodes();
	node->SetParent(this->current);
	current->SetChild(node, i);
	return node;
}

template<typename T>
std::string NTree<T>::getString(Node<T>* node)
{
	std::string result = "";
	result.append(std::to_string(node->GetValue()));
	
	bool empty = true;
	for (int i = 0; i < this->n; i++)
		if (node->GetChild(i) != NULL)
			empty = false;
	if (empty)
		return result;

	result.append("[");

	for (int i = 0; i < this->n; i++)
	{
		if (node->GetChild(i) != NULL)
			result.append(this->getString(node->GetChild(i)));
		else
			result.append("x");

		if (i != this->n - 1)
			result.append(":");
	}	

	result.append("]");

	return result;
}

template<typename T>
std::string NTree<T>::GetString()
{
	return(this->getString(this->root));
}

template<typename T>
void NTree<T>::Print()
{
	std::cout << this->GetString() << '\n';
}