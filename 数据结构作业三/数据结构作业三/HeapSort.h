/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-06
*Description:Header for the implement of heapsort
*********************************/
#pragma once
#ifndef HEAPSORT_H
#define HEAPSORT_H

template<typename E>
void siftdown(E *a, int i, int n)//Sift down the element
{
	int temp;
	while ((i + 1) * 2 - 1 < n)
	{
		if ((i + 1) * 2 == n)//When only rightchild
		{
			if (a[i] < a[(i + 1) * 2 - 1])//If parent is smaller than child, Swap the two elements
			{
				temp = a[i];
				a[i] = a[(i + 1) * 2 - 1];
				a[(i + 1) * 2 - 1] = temp;
				i = (i + 1) * 2 - 1;
			}
			else break;
		}
		else if (a[i] >= a[(i + 1) * 2 - 1] && a[i] >= a[(i + 1) * 2])//Don't need siftdown
		{
			break;
		}
		else if (a[(i + 1) * 2 - 1] > a[(i + 1) * 2])
		{
			temp = a[i];
			a[i] = a[(i + 1) * 2 - 1];
			a[(i + 1) * 2 - 1] = temp;
			i = (i + 1) * 2 - 1;
		}
		else
		{ 
			temp = a[i];
			a[i] = a[(i + 1) * 2];
			a[(i + 1) * 2] = temp;
			i = (i + 1) * 2;
		}
	}
}
template<typename E>
void buildheap(E *a, int i, int n)//Build a heap
{
	if (i >= n)
		return;
	
	buildheap(a, (i + 1) * 2, n);
	buildheap(a, (i + 1) * 2 - 1, n);
	siftdown(a, i, n);
}
template<typename E>
void pop(E *a, int n)//Pop the top element
{
	int temp = a[0];
	a[0] = a[n - 1];
	a[n - 1] = temp;
	siftdown(a, 0, n - 1);
}
template<typename E>
void heapsort(E *a, int n)
{
	buildheap(a, 0, n);

	while (n)
	{
		pop(a, n);
		n--;
	}
}

#endif // !HEAPSORT_H
