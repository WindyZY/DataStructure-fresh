/****************
*Author:周瑶 (201730685202)
*Date:2018-10-20
*Description:这是求二叉树高度的递归函数(Exercise 5.8)
****************/

#include<iostream>
#include"Tree.h"
using namespace std;

//Use the recursive function to get the height of this tree
int Height(BTree T)
{
	if (T == NULL)//Empty node
		return 0;
	else
	{//Preorder traversal
		int m = Height(T->left);
		int n = Height(T->right);

		//Get the deepest path(depth) and add 1 to get the height
		return (m > n) ? (m + 1) : (n + 1);
	}
}

int main()
{
	BTree T = NULL;
	//Create a binary tree to test
	NewTree(T, T);
	cout << Height(T) << endl;
	system("pause");
	return 0;
}