#include "Sort.h"

void Sort::RadixSort(int* arr, int n) //��ͨ��������
{
	std::sort(arr, arr + n);
}

void Sort::RadixSort(HugeInt* arr, int n) //������������
{
	std::sort(arr, arr + n);
}
