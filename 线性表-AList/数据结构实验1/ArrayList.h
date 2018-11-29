/**********************************
Experience 1 2018/10/12
Header for the implementation of ArrayList
By ÖÜÑþ  201730685202
***********************************/

#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include<iostream>
#include"List.h"
#define defaultSize 100

using namespace std;

template <typename E>
class Alist
{
private:
	int maxSize;         //Maximum size of list
	int listSize;        //Number of list items now
	int curr;            //Position of current element
	E* listArray;        //Array holding list elements

public:
	Alist(int size=defaultSize) {//Constructor
		maxSize = size;
		listSize = curr = 0;
		listArray = new E[maxSize];
	}

	~Alist() { delete[] listArray; }//Destructor

	void clear() {                   //Reinitaialize the list
		delete[] listArray;          //Remove the array
		listSize = curr = 0;         //Reset the size
		listArray = new E[maxSize];  //Recreate the array
	}

	void insert(const E& it) {             //Insert "it" at current position
		if (listSize >= maxSize)
			cout << "List capacity exceeded" << endl;
		for (int i = listSize; i > curr; i--) {    //Shift the elements up to make room
			listArray[i] = listArray[i - 1];
		}
		listArray[curr] = it;
		listSize++;               //Increment list size
	}

	void append(const E& it) {        //Append "it"
		if (listSize >= maxSize)
			cout << "List capacity exceeded" << endl;
		listArray[listSize++] = it;
	}

	void remove() {              //Remove and return the current element
		if ((curr < 0) || (curr >= listSize))
			cout << "No element" << endl;
		for (int i = curr; i < listSize - 1; i++) {   //Shift the elements down
			listArray[i] = listArray[i + 1];
		}
		listSize--;
	}

	int length() const { return listSize; }   //Return list size

	void moveToPos(int pos) {                 //Set current position to "pos"
		if (pos<0 || pos>listSize)
			cout << "Pos out of range" << endl;
		//Assert((pos >= 0) && (pos <= listSize), "Pos out of range");
		curr = pos;
	}

	const E& getElement(int pos) {            //Get the element at the special position
		if (pos < 0 || pos >= listSize)
			cout << "Pos out of range" << endl;
		else
			return listArray[pos];
	}

	void findPos(E& a) {                //Find the position of element
		for (int i = 0; i < listSize - 1; i++) {
			if (listArray[i] == a)
				cout << "Pos of " << a << " is " << i;
		}
	}

	bool isEmpty() {              //Judge the ArrayList is empty or not
		return(listSize == 0);
	}

	void getArrayList() const {        //Print the ArrayList
		for (int i = 0; i <= listSize - 1; i++) {
			if (i == listSize - 1)
				cout << listArray[i] << endl;
			else
				cout << listArray[i] << " ";
		}
	}
};

#endif
