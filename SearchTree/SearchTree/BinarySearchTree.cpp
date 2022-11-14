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
	/**
	* Creates a Binary Search Tree starting at a given Node
	* 
	* @constructor
	* @param startingValue: The value to start a tree at
	*/
	BinarySearchTree(T startingValue)
	{
		allData[0] = Node(startingValue, nullptr);
		startingPoint = &allData[0];
		indexOfAllData = 1;
	}
public:
	/**
	* Adds Node to the tree
	*
	* @param val: The value to add to the tree
	* @return None
	*/
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
	/**
	* Adds Nodes to the tree
	* 
	* @param vals: An array of values to add
	* @param howManyValues: The number of values to add
	* 
	* @return None
	*/
	void addValues(T* vals, int howManyValues)
	{
		for (int i = 0; i< howManyValues; i++)
		{
			addValue(vals[i]);
		}
	}

	/**
	* A frontend function to sort the tree in ascending order
	*
	* @return A vector of all values in the tree sorted
	*/
	std::vector<T> sortAsc()
	{
		std::vector<T> test;
		return(sortAsc(startingPoint, test));
	}

	/**
	* A frontend function to search for a given value
	*
	* @param key: The value to look for
	*
	* @return A pointer to the value of the search or nullptr if it is not in the list
	*/
	T* search(T key)
	{
		return search(key, startingPoint);
	}

private:
	/**
	* A backend function to search for a given value
	* 
	* @param key: The value to look for
	* @param currentNode: A pointer to the Node to look from
	* 
	* @return A pointer to the value of the search or nullptr if it is not in the list
	*/
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

	/**
	* A backend function to sort the tree in ascending order
	* 
	* @param startLocation: A pointer to the Node to start from
	* @param allValues: A vector of all values to sort
	* 
	* @return A vector of all values in the tree sorted
	*/
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

	/**
	* Checks if a value is stored in the current array
	* 
	* @param allValues: A vector of all values to search
	* @param value: The value to search for
	* 
	* @return true if the value was found and false if not
	*/
	bool found(std::vector<T>& allValues, T value)
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

	/**
	* Finds the location that a Node belongs
	* 
	* @param val: The value of the Node to find the location of
	* @param startingLocation: A pointer to the Node to look from
	* 
	* @return A pointer to a Node to put the new Node 
	*/
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
			std::cout << "That is already a value" << std::endl;
			return nullptr;
		}
	}
};