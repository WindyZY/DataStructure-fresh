/****************
*Author:���� (201730685202)
*Date:2018-10-20
*Description:�����ܱ�������������ӡ��������ӽ��5���Ľ��ĺ���(Exercise 5.11)
****************/

#include<iostream>
#include"Tree.h"
using namespace std;

void print(BTree &T)    //Print the key of nodes that meet the requirement
{
	if (T == NULL)   //Judge whether the node is empty
		return;

	if (T != T->parent)   //Do when the node is not the root
	{
		if (T->key * 5 == T->parent->parent->key)    //When meeting the requirement print the key
			cout << T->key << " ";
	}

	print(T->left);   //Test the left of current node
	print(T->right);  //Test the right of current node
}

int main()
{
	BTree T = NULL;
	NewTree(T, T);

	print(T);
	system("pause");
	return 0;
}