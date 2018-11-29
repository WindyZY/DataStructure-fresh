/**********************************
Experience 2-2 2018/11/2
The cpp for showing the function of creation, encoding and decoding of huffman
By ÖÜÑþ  201730685202
***********************************/
#include<iostream>
#include<fstream>
#include"HuffNode.h"
#include"HuffCode.h"
#define Size 6    //Define the number of characters
using namespace std;

int main()
{
	HuffTree huff;//Define a huffman tree
	Huff node = NULL;//Define a node of huffman tree and initialize it

	char c[Size];  //Array of characters used
	int a[Size];   //Array of weight of characters

	for (int i = 0; i < Size; i++)   //Enter the characters and their weight
	{
		cin >> c[i] >> a[i];
	}
	
	creat(&huff, c, a, Size);   //Create a huffman tree for encoding and decoding

	node = huff.root;
	//Three kinds of traversal
	cout << endl << "Preorder traversal: ";
	preorder(node);
	cout << endl << "Inorder traversal: ";
	inorder(node);
	cout << endl << "Postorder traversal: ";
	postorder(node);
	cout << endl;
	
	//Get the node where every character is and get the huffman code of the characters
	Huff h[Size];
	for (int i = 0; i < Size; i++)
	{
		getNode(node, c[i]);
		h[i] = tmp;
		cout << c[i] << ": ";
		getCode(h[i], c[i]);
		cout << endl;
	}

	//Read message from the file
	ifstream fin("message.txt");
	if (!fin)   //If file isn't exist
	{
		cout << "NOT FOUND!" << endl;
		return 0;
	}

	//Read message word by word
	char s;
	while (fin>>s)
	{
		for (int i = 0; i < Size; i++)
		{
			if (s == c[i]) {
				getCode(h[i], c[i]);   //Get the code of the character
				//cout << "/";    //Just for checking
				break;
			}
		}
	}

	system("pause");
	return 0;
}