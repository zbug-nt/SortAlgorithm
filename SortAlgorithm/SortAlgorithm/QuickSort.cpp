#include "QuickSort.h"
#include "Sort.h"

const char* QuickSort::name() const
{
	return "��������";
}

void QuickSort::sort(int* arr, int n) const
{
	Sort::QuickSort(arr, n);
}

void QuickSort::sort(HugeInt* arr, int n) const
{
	Sort::QuickSort(arr, n);
}
