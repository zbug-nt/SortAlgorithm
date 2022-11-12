#include "IntDataProvider.h"
#include <algorithm>

IntDataProvider* IntDataProvider::Random(int n)
{
	auto pvd = new IntDataProvider(n);
	int range = MAX - MIN + 1;
	for (int i = 0; i < n; ++i)
	{
		int t = (rand() << 15) | rand();
		pvd->arr[i] = MIN + t % range;
	}
	return pvd;
}

IntDataProvider* IntDataProvider::Ascending(int n)
{
	auto pvd = IntDataProvider::Random(n);
	std::sort(pvd->arr, pvd->arr + n);
	return pvd;
}

IntDataProvider* IntDataProvider::Descending(int n)
{
	auto pvd = IntDataProvider::Random(n);
	std::sort(pvd->arr, pvd->arr + n, std::greater<int>());
	return pvd;
}

//ฐฺมห
IntDataProvider* IntDataProvider::FromFile(const char* filename)
{
	int n = 10;
	auto pvd = new IntDataProvider(n);
	return pvd;
}

IntDataProvider::IntDataProvider(int n)
{
	this->n = n;
	arr = new int[n];
}

IntDataProvider::~IntDataProvider()
{
	delete[] arr;
	arr = NULL;
}

int IntDataProvider::size()
{
	return n;
}

void IntDataProvider::data(int* buf)
{
	memcpy(buf, arr, n * sizeof(int));
}
