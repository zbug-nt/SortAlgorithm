#include "Sort.h"

void Sort::RadixSort(int* arr, int n) //普通基数排序
{
	std::sort(arr, arr + n);
}

void Sort::RadixSort(HugeInt* arr, int n) //大数基数排序
{
	std::sort(arr, arr + n);
}
