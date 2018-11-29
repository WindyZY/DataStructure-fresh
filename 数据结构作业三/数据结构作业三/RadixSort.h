/*********************************
*Author:ÖÜÑþ (201730685202)
*Date:2018-11-06
*Description:Header for the implement of radix sort
*********************************/
#pragma once
#ifndef RADIXSORT_H
#define RADIXSORT_H

template<typename E>
void radix(E *a, E *b, int n, int k, int r)
{
	int cnt[100] = { 0 };
	//cnt[i]stores number of records in bin[i]
	int j;
	for (int i = 0, rtoi = 1; i < k; i++, rtoi *= r)//For k digits
	{
		for (j = 0; j < r; j++)  //Initialize cnt
			cnt[j] = 0;
		for (j = 0; j < n; j++)    //Count the number of records for each bin
			cnt[(a[j] / rtoi) % r]++;
		for (j = 1; j < r; j++)    //Count the number of elements in each bin
			cnt[j] = cnt[j - 1] + cnt[j];
		for (j = n - 1; j >= 0; j--)  //Put records into bins
			b[--cnt[(a[j] / rtoi) % r]] = a[j];
		for (j = 0; j < n; j++)   //Copy b back to a
			a[j] = b[j];
	}
}

#endif // !RADIXSORT_H
