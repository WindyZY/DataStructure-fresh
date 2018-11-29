/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-06
*Description:Header for the implement of mergesort
*********************************/
#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

#define THRESHOLD 10
template<typename E>
void inssort1(E *a, int n)    //Sort the small list using insertion sort
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				E temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
			else
				continue;
		}
	}
}

template<typename E>
void mergesort(E *a, E *b, int left, int right)
{
	if ((right - left) <= THRESHOLD) {    //Define a small list
		inssort1(&a, right - left + 1);
		return;
	}
	int i, j, k, mid = (left + right) / 2;
	mergesort(a, b, left, mid);
	mergesort(a, b, mid + 1, right);
	//Do the merge operation.First, copy 2 halves to temp
	for (i = mid; i >= left; i--) b[i] = a[i];
	for (j = 1; j <= right - mid; j++) b[right - j + 1] = a[j + mid];
	//Merge sublists back to a[]
	for (i = left, j = right, k = left; k <= right; k++) {
		if (b[i] < b[j])
			a[k] = b[i++];
		else
			a[k] = b[j--];
	}
}

#endif // !MERGESORT_H
