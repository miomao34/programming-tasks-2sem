#include "hanoi.hpp"
#include <math.h>

Hanoi::Hanoi(uint size)
{
	this->size = size;
	for (int i = 0; i < size; i++)
		this->rods[0] << (int)(size - i);
}

Hanoi::~Hanoi()
{
	this->size = -1;
	for (int i = 0; i < 3; i++)
		this->rods[i].~Stack();
}

void Hanoi::Solve()
{
	this->Dump();
	
	for (int i = 1; i < pow(2, this->size); i++)
	{
		std::cout << "from " << (i & i - 1) % 3 + 1 << " to " << ((i | i - 1) + 1) % 3 + 1 << '\n';
		this->Dump();
		this->Move((i & i - 1) % 3, ((i | i - 1) + 1) % 3);
	}
}

void Hanoi::Move(uint from, uint to)
{
	// this->rods[to].Push(this->rods[from].Pop());
	this->rods[from] >> this->rods[to];
}

void Hanoi::Dump()
{;
	int width = this->size * 2 + 1;
	int disc_width = 0;
	int value = 0;
	
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << ' ';
			value = this->rods[j].GetCurrent() + i - this->size + 1;
			
			if (value < 0)
				std::cout << std::string(this->size, ' ') << '|' << std::string(this->size, ' ');
			else
			{
				disc_width = this->rods[j][value] * 2 + 1;
				std::cout << std::string((width - disc_width)/2, ' ') << std::string(disc_width, '#') << std::string((width - disc_width)/2, ' ');
			}
		}
		std::cout << '\n';
	}
}
