/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-09
*Description:Header for the implement of bubble sort
*********************************/
#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template<typename E>
void bubsort(E *a, int n)   //Bubble sort
{
	E temp;
	for (int i = 0; i < n - 1; i++)    //Bubble up i'th record
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])//Swap the position
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
			else
				continue;
		}
	}
}

#endif // !BUBBLESORT_H
