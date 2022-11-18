#pragma once

#include <algorithm>
#include "HugeInt.h"

namespace Sort
{
	template<typename T>
	void StdSort(T* arr, int n) //std::sort
	{
		std::sort(arr, arr + n);
	}

	template<typename T>
	void SelectSort(T* arr, int n)                //选择排序入口
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (arr[j] < arr[i])
					std::swap(arr[i], arr[j]);
			}
	    }
	}

	template<typename T>
	void MergeSort(T* arr, int n)                 //归并排序入口
	{
		if (n <= 1) return;
		int mid = n / 2;
		MergeSort(arr, mid); // [0, mid - 1]
		MergeSort(arr + mid, n - mid); // [mid, n - 1]
		T* temp = new T[n + 1];
		int p = 0, q = mid;
		for (int i = 0; i < n; ++i)
		{
			if (p >= mid) temp[i] = arr[q++];
			else if (q >= n) temp[i] = arr[p++];
			else temp[i] = arr[q] < arr[p] ? arr[q++] : arr[p++];
		}
		memcpy(arr, temp, n * sizeof(T));
		delete[] temp;
	}

	template<typename T>
	void QuickSort(T* arr, int n)                 //快速排序入口
	{
		if (n <= 1) return;
		int t = (rand() << 15) | rand();
		t %= n;
		std::swap(arr[0], arr[t]);
		int p = 1, q = n; //pq指向最后一个小于等于arr[0]的后一个
		while (p < q)
		{
			while (p < q && arr[p] <= arr[0]) ++p;
			while (p < q && arr[q] > arr[0]) --q;
			if (p < q) std::swap(arr[p], arr[q]);
		}
		std::swap(arr[0], arr[p - 1]);
		QuickSort(arr, p - 1);
		QuickSort(arr + p, n - p);
	}

	template<typename T>
	void ShellSort(T* arr, int n)                //希尔排序入口
	{
		int gap, i, j, flag;
	    //外循环以不同的gap值对形成的序列进行排序，直到gap=1 
	    for(gap = n / 2; gap >= 1; gap = gap / 2)
		{
			//对各个子序列进行冒泡排序 
			do{
				flag = 0; 
				for(i = 0; i < n - gap; i++)
				{
					j = i + gap;
					if(arr[i] > arr[j])
					{
						std::swap(arr[i], arr[j]);
						flag = 1;
					}	
				}		
			} while (flag);
	    }	
	}

	void RadixSort(int* arr, int n); //普通基数排序

	void RadixSort(HugeInt* arr, int n); //大数基数排序
}
