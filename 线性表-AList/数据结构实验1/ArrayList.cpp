/**********************************
Experience 1 2018/10/12
Cpp for the implementation of ArrayList
By ÖÜÑþ  201730685202
***********************************/
#include<iostream>
#include"ArrayList.h"

using namespace std;

int main()
{
	Alist<char> L;  //Initial the ArrayList

	char e[] = { 'a','b','c','d','e'};

	//Append "a" "b" "c" "d" "e" and print the ArrayList
	for (int i = 0; i < 5; i++)
	{
		L.append(e[i]);
	}
	L.getArrayList();

	//Get the length of the ArrayList
	cout << "The length is " << L.length() << endl;

	//Know whether the ArrayList is empty
	if (L.isEmpty())
		cout << "The ArrayList is empty" << endl;
	else
		cout << "The ArrayList is not empty" << endl;

	//Get the third element
	cout << "The third element is " << L.getElement(2) << endl;

	//Return the position of "a"
	L.findPos(e[0]);
	cout << endl;

	//Insert "f" at the position of the fourth element
	L.moveToPos(3);
	L.insert('f');

	//Print the ArrayList
	L.getArrayList();

	//Remove the third element and print the ArrayList
	L.moveToPos(2);
	L.remove();
	L.getArrayList();

	system("pause");
	return 0;
}
