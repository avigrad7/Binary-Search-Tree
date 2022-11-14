#include<iostream>
#include<vector>

template<typename T>
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
	};
private:
	std::vector<Node> allData;
	Node* startingPoint;
public:
	BinarySearchTree(T startingValue)
	{
		allData.push_back(Node(startingValue, nullptr));
		startingPoint = &allData[0];
	}
};