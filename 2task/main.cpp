#include "stack.hpp"
#include "hanoi.hpp"

int main()
{
	Stack<int> stacker;
	for (int i = 0; i < 15; i++)
		stacker.Push(i);
	
	stacker.Dump();

	Hanoi hanoi(5);

	hanoi.Solve();

	// hanoi.Dump();

	// std::cout << stacker.Peek() << ' ' << stacker.Peek() << '\n';

}