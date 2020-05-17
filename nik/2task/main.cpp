#include "deque.hpp"
#include <iostream>
#include <assert.h>

void test()
{
	Deque<int> deque;

	deque.Prepend(0);
	for(int i = 1; i < 5; i++)
	{
		deque.Prepend(i*-1);
		deque.Append(i);
	}

	deque.Print();

	for(int i = 4; i >= -4; i--)
		assert(deque.PopEnd() == i);

	std::cout << "basic test passed" << std::endl;
}

int main()
{
	int value = 0;

	std::cout << "1. run tests" << std::endl;
	std::cout << "2. manual menu" << std::endl;

	std::cin >> value;

	if (value == 1)
	{
		test();
		exit(0);
	}

	if (value != 2)
	{
		std::cout << "wrong choice" << std::endl;
		exit(1);
	}

	Deque<int> deque;

	while(true)
	{
		std::cout << "1. push to start" << std::endl;
		std::cout << "2. push to end" << std::endl;
		std::cout << "3. pop from start" << std::endl;
		std::cout << "4. pop from end" << std::endl;
		std::cout << "5. peek from start" << std::endl;
		std::cout << "6. peek from end" << std::endl;
		std::cout << "0. exit" << std::endl;

		deque.Print();

		std::cin >> value;

		switch (value)
		{
		case 1:
			std::cin >> value;
			deque.Prepend(value);
			break;
		case 2:
			std::cin >> value;
			deque.Append(value);
			break;
		case 3:
			std::cout << deque.PopStart() << std::endl;
			break;
		case 4:
			std::cout << deque.PopEnd() << std::endl;
			break;
		case 5:
			std::cout << deque.PeekStart() << std::endl;
			break;
		case 6:
			std::cout << deque.PeekEnd() << std::endl;
			break;

		case 0:
			exit(0);
			break;
		
		default:
			std::cout << "wrong choice" << std::endl;
			break;
		}
	}
}