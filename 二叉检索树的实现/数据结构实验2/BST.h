/**********************************
Experience 2-1 2018/10/31
Header for the implementation of BST
By ÖÜÑþ  201730685202
***********************************/
#pragma once
#ifndef BST_H
#define BST_H

#include<iostream>

using namespace std;
typedef int etype;    //Define the data type of the element

typedef struct BSTNode    //Establish a template for BSTNode
{
	etype key;     //Define the key of the BST node
	struct BSTNode *left, *right;   //Define the left subtree and the right one of the BST node
}Node,*BNode;

typedef struct Tree     //Establish a template for a BST
{
	BSTNode *root = NULL;    //Define the root of the BST and Initial the root
}tree,*BTree;

void insert(BTree T, int val)   //Insert a node in a BST
{
	BNode node = new BSTNode;  //Create a node to store the value
	node->key = val;     //Store the value
	node->left = node->right = NULL;   //Define the left and right subnode as NULL

	if (T->root == NULL)    //If the root of this tree is NULL, define this node as the root
		T->root = node;
	else     
	{  //Do the instruction if the root has been defined
		BNode tmp = T->root;         //Create a traversal pointer
		while (tmp != NULL)         //Find the position to insert
		{
			if (val < tmp->key)      //When value is smaller than tht key of the node
			{
				if (tmp->left == NULL)    //Insert the node if the left subtree is NULL
				{
					tmp->left = node;
					return;
				}
				else tmp = tmp->left;    //Find to the left if the left subtree is not NULL
			}
			else        //When value is bigger than the key of the node
			{
				if (tmp->right == NULL)     //Insert if the right subtree is NULL
				{
					tmp->right = node;
					return;
				}
				else
					tmp = tmp->right;       //Find to the right if the right subtree is not NULL
			}
		}
	}
}

void print(BNode &T)    //Print the BST
{
	if (T == NULL)     //Use "/" to represent the empty node
		cout << "/";
	else
	{
		cout << T->key;   //Print the key if the node is not NULL
		print(T->left);    //Print the left subtree
		print(T->right);   //Print the right subtree
	}
}


void preorder(BNode &T)    //Preorder traversal
{
	if (T == NULL)
		return;

	cout << " " << T->key << " ";
	preorder(T->left);
	preorder(T->right);
}

void inorder(BNode &T)    //Inorder traversal
{
	if (T == NULL)
		return;

	inorder(T->left);
	cout << " " << T->key << " ";
	inorder(T->right);
}

void postorder(BNode &T)    //Postorder traversal
{
	if (T == NULL)
		return;

	postorder(T->left);
	postorder(T->right);
	cout << " " << T->key << " ";
}

int getNumOfLeaves(BNode &T)    //Get the number of leaves
{
	if (T == NULL)
		return 0;
	else if (T->left == NULL&&T->right == NULL)   //If the node is leaf return 1 to count
	{
		return 1;
	}
	else
		return getNumOfLeaves(T->left) + getNumOfLeaves(T->right);   //Get the left and right leaves using recuusive function
}

void getLeaf(BNode &T)     //Get the leaves
{
	if (T == NULL)
		return;
	else if (T->left == NULL&&T->right == NULL)   //Print the node if it is a leaf
		cout << T->key << " ";
	else
	{   //Traversal the left and right subtree
		getLeaf(T->left);
		getLeaf(T->right);
	}
}

#endif