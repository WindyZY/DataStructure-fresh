/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-09
*Description:Header for the implement of insertion sort
*********************************/
#pragma once
#ifndef INSERTSORT_H
#define INSERTSORT_H

template<typename E>
void inssort(E *a, int n)     //Insertion sort
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)//Compare with the front of the element 
		{
			if (a[j] < a[j - 1])   //Swap the two element when the latter is smaller than the former
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

#endif