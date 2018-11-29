/**********************************
Experience 2-1 2018/10/31
The cpp for showing the function of creation and traversal of BST, geting the number of leaves and print
By ÖÜÑþ  201730685202
***********************************/
#include<iostream>
#include"BST.h"
#define N 10
#define MAX 100
using namespace std;

int main()
{
	Tree T1, T2;    //Declare two binary search trees
	BNode node1 = NULL;   //Declare two BST nodes and initialize it
	BNode node2 = NULL;
	
	for (int i = 0; i < N; i++)//Read in data from the keyboard and create BST1
	{
		int n;
		cin >> n;
		insert(&T1, n);
	}
	for (int i = 0; i < N; i++)//Read in data from the keyboard and create BST2
	{
		int n;
		cin >> n;
		insert(&T2, n);
	}

	node1 = T1.root;
	//Print BST1
	cout << endl << "BST1: ";
	print(node1);
	
	//Three kinds of traversal
	cout << endl << "The result of preorder traversal: ";
	preorder(node1);

	cout << endl << "The result of inorder traversal: ";
	inorder(node1);

	cout << endl << "The result of postorder traversal: ";
	postorder(node1);

	//Get the number of leaves and print leaves of BST1
	cout << endl << "The number of leaves in this BST is " << getNumOfLeaves(node1) << endl;
	getLeaf(node1);

	node2 = T2.root;
	//Print BST2
	cout << endl << "BST2: ";
	print(node2);

	//Three kinds of traversal
	cout << endl << "The result of preorder traversal: ";
	preorder(node2);

	cout << endl << "The result of inorder traversal: ";
	inorder(node2);

	cout << endl << "The result of postorder traversal: ";
	postorder(node2);

	//Get the number of leaves and print leaves of BST2
	cout << endl << "The number of leaves in this BST is " << getNumOfLeaves(node2) << endl;
	getLeaf(node2);

	system("pause");
	return 0;
}