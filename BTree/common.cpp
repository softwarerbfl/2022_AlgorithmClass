#include<iostream>
#include "common.h"
using namespace std;
Node::Node(int T, bool leaf)
{
	t = T;
	l = leaf;
	keys = new int[2 * t - 1];
	C = new Node * [2 * t];
	n = 0;
}
void Node::traverse()
{
	int i;
	for (i = 0; i < n; i++){
		if (l == false)
			C[i]->traverse();
		cout << keys[i] <<" " ;
	}
	if (l == false)
		C[i]->traverse();
}
//value를 Btree에서 찾는다. 
Node* Node::search(int value){
	int i = 0;
	while (i < n && value > keys[i])
		i++;
	if (l == true)
		return NULL;
	if (keys[i] == value)
		return this;
	return C[i]->search(value);
}
//value를 Btree에 삽입한다.
void BTree::insert(int k)
{	//root가 비어있는 경우 
	if (root == NULL){
		root = new Node(t, true);
		root->keys[0] = k;
		root->n = 1;
	}
	else {
		//root가 꽉 차 있는 경우 
		if (root->n == 2 * t - 1){
			Node* s = new Node(t, false);

			s->C[0] = root;

			s->split(0, root);

			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->C[i]->insert(k);

			root = s;
		}
		//root가 꽉 차있지도 비어있지도 않은 경우 
		else 
			root->insert(k);
	}
}
void Node::insert(int k){
	int i = n - 1;
	if (l == true){
		while (i >= 0 && keys[i] > k){
			keys[i + 1] = keys[i];
			i--;
		}
		keys[i + 1] = k;
		n = n + 1;
	}
	else{
		while (i >= 0 && keys[i] > k)
			i--;
		if (C[i + 1]->n == 2 * t - 1){
			split(i + 1, C[i + 1]);
			if (keys[i + 1] < k) i++;
		}
		C[i + 1]->insert(k);
	}
}
void Node::split(int i, Node* y){
	Node* z = new Node(y->t, y->l);
	z->n = t - 1;
	for (int j = 0; j < t - 1; j++)
		z->keys[j] = y->keys[j + t];
	if (y->l == false){
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j + t];
	}
	y->n = t - 1;
	for (int j = n; j >= i + 1; j--)
		C[j + 1] = C[j];
	C[i + 1] = z;
	for (int j = n - 1; j >= i; j--)
		keys[j + 1] = keys[j];
	keys[i] = y->keys[t - 1];
	n = n + 1;
}
