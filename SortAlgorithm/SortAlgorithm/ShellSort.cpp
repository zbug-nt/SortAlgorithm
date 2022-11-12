#include "ShellSort.h"
#include "Sort.h"

const char* ShellSort::name() const
{
	return "ϣ������";
}

void ShellSort::sort(int* arr, int n) const
{
	Sort::ShellSort(arr, n);
}

void ShellSort::sort(HugeInt* arr, int n) const
{
	Sort::ShellSort(arr, n);
}
