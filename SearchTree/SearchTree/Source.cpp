#include<iostream>
#include"BinarySearchTree.cpp"

int main()
{
	BinarySearchTree<int, 15> test(15);
	test.addValue(5);
	test.addValue(2);
	test.addValue(4);
	test.addValue(11);
	test.addValue(10);
	test.addValue(8);
	test.addValue(6);
	test.addValue(23);
	test.addValue(20);
	test.addValue(25);
	test.addValue(18);
	test.addValue(21);
	test.addValue(17);
	test.addValue(19);
	std::vector<int> sorted = test.sortAsc();
	for (int i = 0; i < sorted.size(); i++)
	{
		std::cout << sorted[i] << std::endl;
	}
}