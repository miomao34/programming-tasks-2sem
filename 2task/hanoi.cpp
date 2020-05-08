#include "hanoi.hpp"
#include <math.h>
#include <stdexcept>

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

void Hanoi::SolveProcedural()
{
	this->Dump();

	int from = 0;
	int to = 0;
	
	for (int i = 1; i < pow(2, this->size); i++)
	{
		from = (i & i - 1) % 3;
		to = ((i | i - 1) + 1) % 3;
		if (this->size % 2 == 0)
		{
			from = (from == 1) ? 2 : (from == 2) ? 1 : from;
			to = (to == 1) ? 2 : (to == 2) ? 1 : to;
		}

		std::cout << "from " << from + 1 << " to " << to + 1 << '\n';
		this->Move(from, to);
		this->Dump();
	}
}

// For an even number of disks:

// make the legal move between pegs A and B (in either direction),
// make the legal move between pegs A and C (in either direction),
// make the legal move between pegs B and C (in either direction),
// repeat until complete.
// For an odd number of disks:

// make the legal move between pegs A and C (in either direction),
// make the legal move between pegs A and B (in either direction),
// make the legal move between pegs B and C (in either direction),
// repeat until complete.

/*void Hanoi::SolveDetermined()
{
	this->Dump();
	if (this->size % 2 == 0)
		for (int i = 1; i < pow(2, this->size) / 3; i++)
		{
			if (this->rods[1].GetCurrent() == -1 || (this->rods[0].GetCurrent() != -1 && this->rods[0].Peek() < this->rods[1].Peek()))
				this->Move(0, 1);
			else
				this->Move(1, 0);
			
			if (this->rods[2].GetCurrent() == -1 || (this->rods[0].GetCurrent() != -1 && this->rods[0].Peek() < this->rods[2].Peek()))
				this->Move(0, 2);
			else
				this->Move(2, 0);

			if (this->rods[2].GetCurrent() == -1 || (this->rods[1].GetCurrent() != -1 && this->rods[1].Peek() < this->rods[2].Peek()))
				this->Move(1, 2);
			else
				this->Move(2, 1);
		}
	else
		for (int i = 1; i < pow(2, this->size) / 3; i++)
		{
			if (this->rods[2].GetCurrent() == -1 || this->rods[0].Peek() < this->rods[2].Peek())
				this->Move(0, 2);
			else
				this->Move(2, 0);

			if (this->rods[1].GetCurrent() == -1 || this->rods[0].Peek() < this->rods[1].Peek())
				this->Move(0, 1);
			else
				this->Move(1, 0);

			if (this->rods[2].GetCurrent() == -1 || this->rods[1].Peek() < this->rods[2].Peek())
				this->Move(1, 2);
			else
				this->Move(2, 1);
		}
}*/

void Hanoi::Move(uint from, uint to)
{
	if(this->rods[from].GetCurrent() > -1 && this->rods[to].GetCurrent() > -1 && this->rods[from].Peek() >= this->rods[to].Peek())
		throw std::runtime_error("hanoi: invalid move!");
	// this->rods[to].Push(this->rods[from].Pop());
	this->rods[from] >> this->rods[to];
}

void Hanoi::Dump()
{;
	// cannot use discs' dumps as each disc hase to use hanoi's size
	int width = this->size * 2 + 1;
	int disc_width = 0;
	int disc_id = 0;
	
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << ' ';
			disc_id = this->rods[j].GetCurrent() + i - this->size + 1;
			
			if (disc_id < 0)
				std::cout << std::string(this->size, ' ') << '|' << std::string(this->size, ' ');
			else
			{
				disc_width = this->rods[j][disc_id] * 2 + 1;
				std::cout << std::string((width - disc_width)/2, ' ') << std::string(disc_width, '#') << std::string((width - disc_width)/2, ' ');
			}
		}
		std::cout << '\n';
	}
}
