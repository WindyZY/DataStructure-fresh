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
	cin >> M;
	hashdict<Key,E> *h = new hashdict<Key,E>(M,-1);

	system("pause");
	return 0;
}