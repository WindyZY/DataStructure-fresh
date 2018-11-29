/**********************************
Experience 2-2 2018/11/2
Header for creation and encoding of huffman tree
By ÖÜÑþ  201730685202
***********************************/
#pragma once
#ifndef HUFFNODE_H
#define HUFFNODE_H
#include<iostream>
#define MAX 50
using namespace std;

typedef int wgt;   //Define the data type of weight is integer

typedef struct HuffNode    //Define the huffman node
{
	//Constructor for HuffNode to initialize the members
	HuffNode(char c, wgt w, HuffNode* l, HuffNode* r) { ch = c; code = '\0'; weight = w; left = l; right = r; flag = 0; parent = NULL; }

	char ch;    //Character of the node('/'for internal node)
	char code = '\0';  //Code of the node('0' if it is left child, '1' if right),initialize it as '\0'
	wgt weight = 0;    //Weight of the node
	HuffNode* left;    //Left child of the node
	HuffNode* right;    //Right child of the node
	HuffNode* parent;   //Parent of the node
	int flag;    //Judge whether to delete it from the forest
}*Huff;

typedef struct HuffTree    //Define the huffman tree
{
	HuffNode* root;    //Root of the huffman tree
	HuffNode* forest[MAX] = { NULL };   //Forest to store all the nodes
}*tree;

void sortfun(tree T,int size)      //Sort all the nodes accoding to their weight
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if ((T->forest[i]->weight) >= (T->forest[j]->weight)) //Swap the two nodes if weight of the latter is smaller than the former
			{
				Huff tmp;
				tmp = T->forest[i];
				T->forest[i] = T->forest[j];
				T->forest[j] = tmp;
			}
			else
				continue;
		}
	}
}

void creat(tree T, char c[], wgt a[], int size)  //Create a huffman tree
{
	for (int i = 0; i < size; i++)  //Establish the character and its weight as a HuffNode
	{
		Huff h = new HuffNode(c[i], a[i], NULL, NULL);
		T->forest[i] = h;   //Store the node into the HuffTree
	}
	
	for (int i = 0; i < size; i++)  
	{
		sortfun(T, size);//Sort the nodes to find the smallest two nodes
		for (int j = 0;j < size - 1; j++)
		{
			if (T->forest[j]->flag != 1 && T->forest[j + 1]->flag != 1)//Do the instructions if the two nodes exist
			{
				//Combine the two nodes into one and store the new node into forest
				Huff node = new HuffNode('/',T->forest[j]->weight + T->forest[j + 1]->weight, T->forest[j], T->forest[j + 1]);
				T->forest[size] = node;
				size++;

				//Change the code and parent of the two nodes
				T->forest[j]->code = '0';
				T->forest[j + 1]->code = '1';
				T->forest[j]->parent = node;
				T->forest[j + 1]->parent = node;
				//Delete the two nodes by setting their flag to 1
				T->forest[j]->flag = 1;
				T->forest[j + 1]->flag = 1;
				break;
			}
			else
				continue;
		}
	}
	T->root = T->forest[size - 1];   //Define the root of the HuffTree
}

void preorder(Huff &H)   //Preorder traversal of the HuffTree
{
	if (H == NULL)
		return;

	cout << H->ch << H->weight << " ";
	preorder(H->left);
	preorder(H->right);
}

void inorder(Huff &H)    //Inorder traversal of the HuffTree
{
	if (H == NULL)
		return;
	
	inorder(H->left);
	cout << H->ch << H->weight << " ";
	inorder(H->right);
}

void postorder(Huff &H)    //Postorder traversal of the HuffTree
{
	if (H == NULL)
		return;

	postorder(H->left);
	postorder(H->right);
	cout << H->ch << H->weight << " ";
}

/*void destroy(Huff &H)
{
	if (H == NULL)
		return;
	
	destroy(H->left);
	destroy(H->right);
	delete H;
	H = NULL;
}*/

#endif
