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
	void SelectSort(T* arr, int n) //ѡ������
	{
		std::sort(arr, arr + n);
	}

	template<typename T>
	void MergeSort(T* arr, int n) //�鲢����
	{
		std::sort(arr, arr + n);
	}

	template<typename T>
	void QuickSort(T* arr, int n) //��������
	{
		std::sort(arr, arr + n);
	}

	template<typename T>
	void ShellSort(T* arr, int n) //ϣ������
	{
		std::sort(arr, arr + n);
	}

	void RadixSort(int* arr, int n); //��ͨ��������

	void RadixSort(HugeInt* arr, int n); //������������
}
