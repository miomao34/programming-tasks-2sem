#include "tree.hpp"
#include <assert.h>

void TestGetString()
{
	NTree<int> tree = NTree<int>(1, 3);
	tree.AddChild(2, 0);
	tree.AddChild(3, 1);
	tree.AddChild(4, 2);

	tree.GoToChild(0);
	tree.AddChild(5, 0);
	tree.AddChild(6, 2);
	tree.GoUp();

	tree.GoToChild(2);
	tree.AddChild(7, 0);
	tree.AddChild(8, 1);

	assert(tree.GetString() == std::string("1[2[5:x:6]:3:4[7:8:x]]"));

	std::cout << "GetString OK\n";
}

void TestGetSize()
{
	NTree<int> tree = NTree<int>(1, 3);
	tree.AddChild(2, 0);
	tree.AddChild(3, 1);
	tree.AddChild(4, 2);

	tree.GoToChild(0);
	tree.AddChild(5, 0);
	tree.AddChild(6, 2);
	tree.GoUp();

	tree.GoToChild(2);
	tree.AddChild(7, 0);
	tree.AddChild(8, 1);

	assert(tree.GetSize() == 8);

	std::cout << "GetSize OK\n";
}

void TestDeleteSubtree()
{
	NTree<int> tree = NTree<int>(1, 3);
	tree.AddChild(2, 0);
	tree.AddChild(3, 1);
	tree.AddChild(4, 2);

	tree.GoToChild(0);
	tree.AddChild(5, 0);
	tree.AddChild(6, 2);
	tree.GoUp();

	tree.GoToChild(2);
	tree.AddChild(7, 0);
	tree.AddChild(8, 1);

	tree.GoUp();
	tree.GoToChild(0);

	// std::cout << tree.GetCurrent()->GetValue() << '\n';
	tree.DeleteSubTree();

	assert(tree.GetString() == std::string("1[x:3:4[7:8:x]]"));

	std::cout << "DeleteSubtree OK\n";
}

void TestAddTreeToChild()
{
	NTree<int> tree = NTree<int>(1, 3);
	tree.AddChild(2, 0);
	tree.AddChild(3, 1);
	tree.AddChild(4, 2);

	tree.GoToChild(0);
	tree.AddChild(5, 0);
	tree.AddChild(6, 2);
	tree.GoUp();

	tree.GoToChild(2);
	tree.AddChild(7, 0);
	tree.AddChild(8, 1);
	
	tree.GoUp();
	tree.GoToChild(1);

	NTree<int> tree2 = NTree<int>(9, 3);
	tree2.AddChild(10, 1);
	tree2.AddChild(11, 2);

	tree.AddTreeToChild(&tree2, 1);

	assert(tree.GetString() == std::string("1[2[5:x:6]:3[x:9[x:10:11]:x]:4[7:8:x]]"));

	std::cout << "AddTreeLeft OK\n";
}

void TestWalk()
{
	NTree<int> tree = NTree<int>(1, 3);
	tree.AddChild(2, 0);
	tree.AddChild(3, 1);
	tree.AddChild(4, 2);

	tree.GoToChild(0);
	tree.AddChild(5, 0);
	tree.AddChild(6, 2);
	tree.GoUp();

	tree.GoToChild(2);
	tree.AddChild(7, 0);
	tree.AddChild(8, 1);

	int cl[] = {1,2,5,6,3,4,7,8};
	int cr[] = {1,4,8,7,3,2,6,5};
	int lc[] = {5,6,2,3,7,8,4,1};
	int rc[] = {8,7,4,3,6,5,2,1};
	
	int* walked = tree.Walk(CL);
	for (int i = 0; i < tree.GetSize(); i++)
		assert(walked[i] == cl[i]);
	std::cout << "Walk: CL OK\n";
	free(walked);
	
	walked = tree.Walk(CR);
	for (int i = 0; i < tree.GetSize(); i++)
		assert(walked[i] == cr[i]);
	std::cout << "Walk: CR OK\n";
	free(walked);
	
	walked = tree.Walk(LC);
	for (int i = 0; i < tree.GetSize(); i++)
		assert(walked[i] == lc[i]);
	std::cout << "Walk: LC OK\n";
	free(walked);
	
	walked = tree.Walk(RC);
	for (int i = 0; i < tree.GetSize(); i++)
		assert(walked[i] == rc[i]);
	std::cout << "Walk: RC OK\n";
	free(walked);
}

void RunTests()
{
	TestGetString();
	TestGetSize();
	TestDeleteSubtree();
	TestAddTreeToChild();
	TestWalk();
}

int main()
{
	RunTests();
}