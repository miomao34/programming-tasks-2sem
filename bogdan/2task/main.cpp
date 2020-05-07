#include "list.hpp"
#include "complex.hpp"

int main()
{
	CircularList<int> list = CircularList<int>();

	list.Add(0);
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Dump();

	list.GoNext();
	list.RemoveNext();

	list.Dump();

	CircularList<Complex> list2 = CircularList<Complex>();

	list2.Add(Complex(1,2));
	list2.Add(Complex(3,2));
	list2.Add(Complex(4,2));
	list2.Add(Complex(5,2));

	list2.Dump();

	list2.GoNext();
	list2.RemoveNext();
	
	list2.Dump();

	CircularList<std::string> list3 = CircularList<std::string>();

	list3.Add(std::string("hello"));
	list3.Add(std::string("there"));
	list3.Add(std::string("general"));
	list3.Add(std::string("kenobi"));

	list3.Dump();

	list3.GoNext();
	list3.RemoveNext();
	
	list3.Dump();
}