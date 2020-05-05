#pragma once

#include "stack.hpp"

class Hanoi
{
private:
	Stack<int> rods [3];
	uint size;
public:
	Hanoi(uint size);
	~Hanoi();

	void Solve();
	void Move(uint from, uint to);
	void Validate();
	void Dump();
};