/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-09
*Description:Header for the implement of shell sort
*********************************/
#pragma once
#ifndef SHELLSORT_H
#define SHELLSORT_H

template<typename E>
void inssort2(E *a, int n, int incr)    //Modified version of Insertion Sort for varying increments
{
	E temp;
	for (int i = incr; i < n; i += incr)
	{
		for (int j = i; j >= incr; j -= incr)   //Compare the elements incr position apart
		{
			if (a[j] < a[j - incr])//Swap the position
			{
				temp = a[j];
				a[j] = a[j - incr];
				a[j - incr] = temp;
			}
			else
				continue;
		}
	}
}
template<typename E>
void shellsort(E *a, int n)
{
	int base = 0;
	for (int i = 2; i <= 5; i++)//Find the base to get the increment
	{
		if (n%i == 0)
		{
			base = i;
			break;
		}
	}
	if (base == 0)//If the total number of the list can't be parted
	{
		cout << "WRONG PARTITION!" << endl;
		exit(1);
	}

	for (int i = n / base; i > base; i /= base)//For each increment
	{
		for (int j = 0; j < i; j++)//Sort each sublist
		{
			inssort2(&a[j], n - j, i);
		}
		inssort2(a, n, 1);//Normal insertion sort
	}
}

#endif // !SHELLSORT_H