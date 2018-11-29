/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-09
*Description:For test
*********************************/
#include<iostream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
#include"InsertSort.h"
#include"BubbleSort.h"
#include"SelectSort.h"
#include"ShellSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"HeapSort.h"
#include"RadixSort.h"
#define  Max 10010

using namespace std;
int num[Max];
int temp[Max];

int main()
{
	//Read data from the txt
	ifstream input("test10000.txt");
	int n = 0;
	if (!input)
		cout << "NOT FOUND!" << endl;
	while (!input.eof())
	{
		input >> num[n];
		n++;
	}
	
	//Get the random number of certain quantity
	/*int n;
	cin >> n;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		num[i] = rand();
	}*/

	//Get the running time of the function
	clock_t start = clock();
	//inssort(num, n); cout << "The result of insertion sort(" << n << "): ";
	//bubsort(num, n); cout << "The result of bubble sort(" << n << "): ";
	//selsort(num, n); cout << "The result of selection sort(" << n << "): ";
	//shellsort(num, n); cout << "The result of shell sort(" << n << "): ";
	mergesort(num, temp, 0, n - 1); cout << "The result of mergesort(" << n << "): ";
	//qsort(num, 0, n-1); cout << "The result of quicksort(" << n << "): ";
	//heapsort(num, n); cout << "The result of heapsort(" << n << "): ";
	//radix(num, temp, n, 5, 10); cout << "The result of radix sort(" << n << "): ";
	clock_t ends = clock();
	cout << "Running Time: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
	for (int i = 0; i < n; i++)//Print the sorted list
		cout << num[i] << " ";
	system("pause");
	return 0;
}