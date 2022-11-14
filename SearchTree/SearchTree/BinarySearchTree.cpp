#include<iostream>
#include<vector>

template<typename T, int N>
class BinarySearchTree
{
private:
	struct Node
	{
		T value;
		Node* less;
		Node* greater;
		Node* parentNode;
		Node(T val, Node* parent)
		{
			value = val;
			parentNode = parent;
			less = nullptr;
			greater = nullptr;
		}
		Node()
		{
			value = NULL;
			parentNode = nullptr;
			less = nullptr;
			greater = nullptr;
		}
	};
private:
	Node allData[N];
	Node* startingPoint;
	int indexOfAllData;
public:
	BinarySearchTree(T startingValue)
	{
		allData[0] = Node(startingValue, nullptr);
		startingPoint = &allData[0];
		indexOfAllData = 1;
	}
public:
	void addValue(T val)
	{
		if (indexOfAllData >= N)
		{
			std::cout << "Exeeded data limit" << std::endl;
			return;
		}
		Node* parent = findNodeLocation(val, startingPoint);
		if (parent != nullptr)
		{
			Node workingNode(val, parent);
			allData[indexOfAllData] = workingNode;
			if (val < parent->value)
			{
				parent->less = &allData[indexOfAllData];
			}
			else
			{
				parent->greater = &allData[indexOfAllData];
			}
			indexOfAllData++;
		}
	}
	void addValues(T* vals, int howManyValues)
	{
		for (int i = 0; i< howManyValues; i++)
		{
			addValue(vals[i]);
		}
	}
	std::vector<T> sortAsc()
	{
		std::vector<T> test;
		return(sortAsc(startingPoint, test));
	}

	T* search(T key)
	{
		return search(key, startingPoint);
	}

private:

	T* search(T key, Node* currentNode)
	{
		if (key < currentNode->value)
		{
			if (currentNode->less == nullptr)
			{
				return nullptr;
			}
			currentNode = currentNode->less;
			return search(key, currentNode);
		}
		else if (key > currentNode->value)
		{
			if (currentNode->greater == nullptr)
			{
				return nullptr;
			}
			currentNode = currentNode->greater;
			return search(key, currentNode);
		}
		return &currentNode->value;
	}

	std::vector<T> sortAsc(Node* startLocation, std::vector<T>& allValues)
	{
		Node* currentLocation = startLocation;
		while (currentLocation->less != nullptr && !found(allValues, currentLocation->less->value))
		{
			currentLocation = currentLocation->less;
		}
		allValues.push_back(currentLocation->value);
		if (currentLocation->greater != nullptr)
		{
			return sortAsc(currentLocation->greater, allValues);
		}
		else
		{
			while (found(allValues, currentLocation->value))
			{
				if (currentLocation->parentNode == nullptr)
				{
					return allValues;
				}
				currentLocation = currentLocation->parentNode;
			}
			return sortAsc(currentLocation, allValues);
		}
	}

	bool found(std::vector<T> allValues, T value)
	{
		for (int i = 0; i < allValues.size(); i++)
		{
			if (value == allValues[i])
			{
				return true;
			}
		}
		return false;
	}

	Node* findNodeLocation(T val, Node* startLocation)
	{
		if (val < startLocation->value)
		{
			if (startLocation->less == nullptr)
			{
				return startLocation;
			}
			else
			{
				return findNodeLocation(val, startLocation->less);
			}
		}
		else if (val > startLocation->value)
		{
			if (startLocation->greater == nullptr)
			{
				return startLocation;
			}
			else
			{
				return findNodeLocation(val, startLocation->greater);
			}
		}
		else
		{
			//std::cout << "That is already a value" << std::endl;
			return nullptr;
		}
	}
};