#pragma once
#include "SortBase.h"
class QuickSort :
    public SortBase
{
public:
	virtual const char* name() const;
	virtual void sort(int* arr, int n) const;
	virtual void sort(HugeInt* arr, int n) const;
};

