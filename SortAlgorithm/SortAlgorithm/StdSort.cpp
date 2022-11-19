#include "StdSort.h"
#include "Sort.h"

const char* StdSort::name() const
{
	return "std;;sort";
}

void StdSort::sort(int* arr, int n) const
{
	Sort::StdSort(arr, n);
}

void StdSort::sort(HugeInt* arr, int n) const
{
	Sort::StdSort(arr, n);
}
