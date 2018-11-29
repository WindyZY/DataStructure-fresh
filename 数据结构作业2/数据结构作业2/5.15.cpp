/****************
*Author:周瑶 (201730685202)
*Date:2018-10-20
*Description:这是能遍历二叉检索树的三个函数(Exercise 5.11)
****************/

#include<iostream>
#include"Tree.h"
using namespace std;

void preorder(BTree &T)    //Preorder traversal using recursive function and print
{
	if (T == NULL)
		return;

	cout << " " << T->key << " ";  //Print the key of current node
	preorder(T->left);  //Traversal the left node of current node 
	preorder(T->right);   //Traversal the right node of current node
}

void inorder(BTree &T)     //Inorder traversal using recursive function and print
{
	if (T == NULL)
		return;

	inorder(T->left);   //Traversal the left of current node
	cout << " " << T->key << " ";    //Print the key of current node
	inorder(T->right);    //Traversal the right of current node
}

void postorder(BTree &T)    //Postorder traversal using recursive function and print
{
	if (T == NULL)
		return;

	postorder(T->left);   //Traversal the left of current node
	postorder(T->right);   //Traversal the right of current node
	cout << " " << T->key << " ";  //Print the key of current node
}

int main()
{
	BTree T = NULL;
	NewTree(T, T);//Create a new tree

	cout << endl << "The outcome of preorder traversal: ";
	preorder(T);
	cout << endl << "The outcome of inorder traversal: ";
	inorder(T);
	cout << endl << "The outcome of postorder traversal: ";
	postorder(T);

	system("pause");
	return 0;
}