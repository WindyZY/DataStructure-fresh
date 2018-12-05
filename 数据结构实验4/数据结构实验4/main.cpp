#include"ADT.h"
#include"Hashdict.h"
#include<iostream>

using namespace std;
typedef int Key;
typedef int E;

int main()
{
	int M;
	cin >> M;
	hashdict<Key,E> *h = new hashdict<Key,E>(M,-1);
	system("pause");
	return 0;
}