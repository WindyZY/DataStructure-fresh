#pragma once
#ifndef TREE_H
#define TREE_H

#include<iostream>

using namespace std;

//Define a node for binary tree
typedef struct BNode {
	int key;
	struct BNode *left, *right, *parent;
}Tree, *BTree;

//Create a new binary tree according to preorder traversal
void NewTree(BTree &T, BTree &pa)
{
	int t;
	cin >> t;
	if (t <= 0)//Define empty node
		T = NULL;
	else
	{
		T = (BTree)malloc(sizeof(BNode));//Make room for element in dynamic array
		if (!T)
			cout << "Wrong!" << endl;
		T->parent = pa;   //Record the parent of current node
		T->key = t;    //Assign t to node 

					   //Define the left and right subtree of the node
		NewTree(T->left, T);
		NewTree(T->right, T);
	}
}

#endif