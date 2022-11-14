#include<iostream>
#include"BinarySearchTree.cpp"
#include"Timer.h"
#include<random>

int main()
{
	srand(time(0));
	BinarySearchTree<int, 5001> test(5000);
	int* allData = new int[5000];
	for (int i = 0; i < 5000; i++)
	{
		allData[i] = i;
	}
	int what = 0;
	int flip = 0;
	int randNum = 0;
	for (int i = 0; i < 5000; i++)
	{
		randNum = rand() % 5000;
		what = allData[i];
		flip = allData[randNum];
		allData[i] = flip;
		allData[randNum] = what;
	}
	test.addValues(allData, 5000);
	{
		Timer t;
		test.sortAsc();
	}

	std::cin.get();

	{
		Timer t;
		int count = 0;
		int temp;
		int whatIsChecking;
		for (int i = 0; i < 5000; i++) {
			whatIsChecking = allData[i];
			for (int u = i + 1; u < 5000; u++) {
				count++;
				if (whatIsChecking > allData[u]) {
					temp = allData[u];
					whatIsChecking = allData[u];
					allData[u] = allData[i];
					allData[i] = temp;
				}
			}
		}


	}
}

















