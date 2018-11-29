/**********************************
Experience 2-2 2018/11/2
Header for encoding and decoding of characters
By ÖÜÑþ  201730685202
***********************************/
#pragma once
#ifndef HUFFCODE_H
#define HUFFCODE_H

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#define Size 6
#include"HuffNode.h"
using namespace std;

char huffcode[MAX];     //Array to store the code of the characters
int start;   //Recoding the starting position of decoding
Huff tmp;     //Remember the node of the character

void getNode(Huff &H, char c)  //Get the node where the character is
{
	if (H == NULL)   //Exit if the node is NULL
		return;

	if (H->ch == c) {  //Find the node
		tmp = H;
	}
	else {   //Traversal to find the node
		getNode(H->left, c);
		getNode(H->right, c);
	}
}

void encoding(Huff &H)    //Encoding the character according to postorder traversal
{
	if (H == NULL)
		return;

	huffcode[--start] = H->code;   //Get the code of the node and change the value of start
	encoding(H->parent);   //Get the code of its parent
}

void getCode(Huff &H, char c)  //Get the huffman code of the node
{
	start = MAX - 10;   //Set the initial value
	encoding(H);   //Encoding the node
	
	for (int i = 0; i < MAX; i++)  //Print the huffman code of the node
	{
		if (huffcode[i] == '1' || huffcode[i] == '0')
			cout << huffcode[i];
	}

	for (int i = 0; i < MAX; i++)  //Clear the array
	{
		huffcode[i] = '2';
	}
}

#endif