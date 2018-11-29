/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-06
*Description:Header for the implement of selection sort
*********************************/
#pragma once
#ifndef SELECTSORT_H
#define SELECTSORT_H

template<typename E>
void selsort(E *a, int n)   //Selection sort
{
	E temp;
	for (int i = 0; i < n - 1; i++)//Select i'th record
	{
		int min = i;      //Remember its index
		for (int j = n - 1; j > i; j--)//Find the least value
		{
			if (a[j] < a[min])    //Put it in place
				min = j;
			else
				continue;
		}
		//Swap the position of the current and the least value
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

#endif // !SELECTSORT_H
