#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
class Node
{
	int* keys;
	int t;
	Node** C;
	int n;
	bool l;
public:
	friend class BTree;
	Node(int value, bool l);
	Node* search(int value);
	void insert(int value);
	void split(int i, Node* y);
	void traverse();
};
class BTree
{
	Node* root;
	int t;
public:
	BTree(int value)
	{
		root = NULL;
		t = value;
	}
	Node* search(int value)
	{
		return (root == NULL) ? NULL : root->search(value);
	}
	void insert(int value);
	void traverse()
	{
		if (root != NULL) root->traverse();
	}
};
