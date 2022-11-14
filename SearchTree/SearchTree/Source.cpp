#include<iostream>
#include"BinarySearchTree.cpp"
#include"Timer.h"
#include<random>

int main()
{
	BinarySearchTree<int, 601> test(600);
	int values[600];
	for (int i = 599; i >= 0; i--)
	{
		values[i] = std::rand();
	}
	test.addValues(values, 600);
	std::cin.get();
	std::vector<int> sorted;
	{
		Timer time;
		sorted = test.sortAsc();
	}
	//std::cin.get();
	//for (int i = 0; i < sorted.size(); i++)
	//{
	//	std::cout << sorted[i] << std::endl;
	//}

	std::cout << std::endl;
	std::cin.get();
	{
		Timer t;
		int count = 0;
		int temp;
		int whatIsChecking;
		for (int i = 0; i < 599; i++) {
			whatIsChecking = values[i];
			for (int u = i + 1; u < 600; u++) {
				count++;
				if (whatIsChecking > values[u]) {
					temp = values[u];
					whatIsChecking = values[u];
					values[u] = values[i];
					values[i] = temp;
				}
			}
		}
			
		
	}
	//for (int val : values)
	//{
	//	std::cout << val << std::endl;
	//}
}

















