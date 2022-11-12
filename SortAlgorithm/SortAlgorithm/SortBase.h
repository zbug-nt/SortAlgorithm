#pragma once

#include "HugeInt.h"

class SortBase
{
public:
	virtual const char* name() const;
	virtual void sort(int* arr, int n) const = 0;
	virtual void sort(HugeInt* arr, int n) const = 0;
};
