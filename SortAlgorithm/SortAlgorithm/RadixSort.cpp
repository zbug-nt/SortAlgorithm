#include "RadixSort.h"
#include "Sort.h"

const char* RadixSort::name() const
{
	return "��������";
}

void RadixSort::sort(int* arr, int n) const
{
	Sort::RadixSort(arr, n);
}

void RadixSort::sort(HugeInt* arr, int n) const
{
	Sort::RadixSort(arr, n);
}
