/****************************************
Author:ÖÜÑþ201730685202
Date:2018-12-03
Description:Test for Hashdict.h
*****************************************/
#include"ADT.h"
#include"Hashdict.h"
#include<iostream>

using namespace std;
typedef int Key;
typedef char E;

int main()
{
	int M;
	cout << "Enter the number of slots:";
	cin >> M;
	hashdict<Key,E> *h = new hashdict<Key,E>(M,-1);

	//Test insertion function
	Key k;
	E e;
	cout << "Enter the records need inserting,-1 to quit!" << endl;
	while (cin >> k)
	{
		if (k == -1)
			break;
		cin >> e;
		h->insert(k, e);
	}
	cout << "Insertion finished! *******************************" << endl << endl;

	//Test print function
	h->print();
	cout << endl;

	//Test removing function
	cout << "Enter the key of the record you want to remove:";
	Key k1;
	cin >> k1;
	cout << h->remove(k1) << endl;
	cout <<"Remove the first record:";
	cout << h->removeAny() << endl;
	cout << "Remove finished! ***********************************" << endl << endl;

	//Test search function
	cout << "Enter the key of the record you want to find:";
	Key k2;
	cin >> k2;
	cout << "The record of the key is " << h->find(k2) << endl;
	cout << "Searching finished! *********************************" << endl << endl;

	//Test print function
	h->print();

	system("pause");
	return 0;
}