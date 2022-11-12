#include "HugeIntDataProvider.h"
#include <algorithm>

HugeIntDataProvider* HugeIntDataProvider::Random(int n)
{
	auto pvd = new HugeIntDataProvider(n);
	for (int i = 0; i < n; ++i)
	{
		pvd->arr[i] = HugeInt::Rand();
	}
	return pvd;
}

HugeIntDataProvider* HugeIntDataProvider::Ascending(int n)
{
	auto pvd = HugeIntDataProvider::Random(n);
	std::sort(pvd->arr, pvd->arr + n);
	return pvd;
}

HugeIntDataProvider* HugeIntDataProvider::Descending(int n)
{
	auto pvd = HugeIntDataProvider::Random(n);
	std::sort(pvd->arr, pvd->arr + n, std::greater<HugeInt>());
	return pvd;
}

//ฐฺมห
HugeIntDataProvider* HugeIntDataProvider::FromFile(const char* filename)
{
	int n = 10;
	auto pvd = new HugeIntDataProvider(n);
	return pvd;
}

HugeIntDataProvider::HugeIntDataProvider(int n)
{
	this->n = n;
	arr = new HugeInt[n];
}

HugeIntDataProvider::~HugeIntDataProvider()
{
	delete[] arr;
	arr = NULL;
}

int HugeIntDataProvider::size()
{
	return n;
}

void HugeIntDataProvider::data(HugeInt* buf)
{
	memcpy(buf, arr, n * sizeof(HugeInt));
}
