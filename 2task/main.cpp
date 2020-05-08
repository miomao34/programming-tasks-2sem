#include "stack.hpp"
#include "hanoi.hpp"

int main()
{
	Stack<int> stacker;
	for (int i = 0; i < 15; i++)
		stacker.Push(i);
	
	stacker.Dump();

	Hanoi hanoi(3);

	hanoi.SolveProcedural();

	// hanoi.Dump();

	// std::cout << stacker.Peek() << ' ' << stacker.Peek() << '\n';

}