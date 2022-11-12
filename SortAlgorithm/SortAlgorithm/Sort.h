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
	void SelectSort(T* arr, int n) //选择排序
	{
		std::sort(arr, arr + n);
	}

	template<typename T>
	void MergeSort(T* arr, int n) //归并排序
	{
		std::sort(arr, arr + n);
	}

	template<typename T>
	void QuickSort(T* arr, int n) //快速排序
	{
		std::sort(arr, arr + n);
	}

	template<typename T>
	void ShellSort(T* arr, int n) //希尔排序
	{
		std::sort(arr, arr + n);
	}

	void RadixSort(int* arr, int n); //普通基数排序

	void RadixSort(HugeInt* arr, int n); //大数基数排序
}
