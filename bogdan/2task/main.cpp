#include "queue.hpp"
#include "complex.hpp"

using namespace std;

int main()
{
	int number = 0;

	Queue<int> queue_i;
	int value_i = 0;
	cout << "int: enter number of nodes:\n";
	cin >> number;
	cout << "enter values:\n";
	for (int i = 0; i < number; i++)
	{
		cin >> value_i;
		queue_i.Push(value_i);
	}

	queue_i.Dump();

	cout << "output:\n";
	for (int i = 0; i < number; i++)
		cout << queue_i.Pop() << '\n';



	Queue<double> queue_d;
	double value_d = 0;
	cout << "double: enter number of nodes:\n";
	cin >> number;
	cout << "enter values:\n";
	for (int i = 0; i < number; i++)
	{
		cin >> value_d;
		queue_d.Push(value_d);
	}

	queue_d.Dump();

	cout << "output:\n";
	for (int i = 0; i < number; i++)
		cout << queue_d.Pop() << '\n';



	Queue<string> queue_s;
	string value_s = "";
	cout << "string: enter number of nodes:\n";
	cin >> number;
	cout << "enter values:\n";
	for (int i = 0; i < number; i++)
	{
		cin >> value_s;
		queue_s.Push(value_s);
	}

	queue_s.Dump();

	cout << "output:\n";
	for (int i = 0; i < number; i++)
		cout << queue_s.Pop() << '\n';



	Queue<Complex> queue_c;
	double value1, value2 = 0;
	cout << "complex: enter number of nodes:\n";
	cin >> number;
	cout << "enter values:\n";
	for (int i = 0; i < number; i++)
	{
		cin >> value1 >> value2;
		queue_c.Push(Complex(value1, value2));
	}

	queue_c.Dump();

	cout << "output:\n";
	for (int i = 0; i < number; i++)
		cout << queue_c.Pop() << '\n';

}

// HERE WE FUCKING GO