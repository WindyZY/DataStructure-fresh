/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-06
*Description:Header for the implement of quicksort
*********************************/
#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H

template<typename E>
int findpivot(E *a, int i, int j)  //Get the pivot
{
	return (i + j) / 2;
}

template<typename E>
void swap(E *a, int i, int j)  //Swap the two elements
{
	E tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

template<typename E>
int partition(E *a, int l, int r, E& pivot)//Part the elements
{
	do {//Move the bound inward until they meet
		while (a[++l] < pivot);  //Move l right
		while ((l < r) && pivot < a[--r]);//Move r left
		swap(a, l, r);    //Swap out-of-place values
	} while (l < r);   //Stop when they cross
	return l;   //Return first position in right partition
}

template<typename E>
void qsort(E *a, int i, int j)//Quicksort
{
	if (i >= j)    //Don't sort 0 or 1 element
		return;
	int pivotindex = findpivot(a, i, j);
	swap(a, pivotindex, j);     //Put the pivot at end
	int k = partition(a, i - 1, j, a[j]);
	swap(a, k, j);      //Put the pivot in place
	qsort(a, i, k - 1);
	qsort(a, k + 1, j);
}

#endif // !QUICKSORT_H
