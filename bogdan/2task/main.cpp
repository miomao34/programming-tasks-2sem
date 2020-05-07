#include "list.hpp"
#include "complex.hpp"

using namespace std;

int main()
{
	double value, value2 = 0;
	string str = "";
	int number_of_nodes = 0;

	CircularList<int> list = CircularList<int>();

	cout << "int tests:\nenter number of nodes:\n";
	cin >> number_of_nodes;
	cout << "enter nodes:\n";
	for (int i = 0; i < number_of_nodes; i++)
	{
		cin >> value;
		list.Add(value);
	}

	list.Dump();
	list.GoNext();

	cout << "enter number of nodes to delete after head:\n";
	cin >> number_of_nodes;
	for (int i = 0; i < number_of_nodes; i++)
		list.RemoveNext();

	list.Dump();

	CircularList<Complex> list2 = CircularList<Complex>();

	cout << "complex tests:\nenter number of nodes:\n";
	cin >> number_of_nodes;
	cout << "enter nodes(2 numbers - 1 node):\n";
	for (int i = 0; i < number_of_nodes; i++)
	{
		cin >> value >> value2;
		list2.Add(Complex(value, value2));
	}

	list2.Dump();
	list2.GoNext();

	cout << "enter number of nodes to delete after head:\n";
	cin >> number_of_nodes;
	for (int i = 0; i < number_of_nodes; i++)
		list2.RemoveNext();

	list2.Dump();

	CircularList<std::string> list3 = CircularList<std::string>();

	cout << "string tests:\nenter number of nodes:\n";
	cin >> number_of_nodes;
	cout << "enter nodes:\n";
	for (int i = 0; i < number_of_nodes; i++)
	{
		cin >> str;
		list3.Add(str);
	}

	list3.Dump();

	list3.GoNext();

	cout << "enter number of nodes to delete after head:\n";
	cin >> number_of_nodes;
	for (int i = 0; i < number_of_nodes; i++)
		list3.RemoveNext();
	
	list3.Dump();
}