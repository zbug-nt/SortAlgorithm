#pragma once

#include "HugeInt.h"

class HugeIntDataProvider
{
public:
	~HugeIntDataProvider();
	int size();
	void data(HugeInt* buf);

	static HugeIntDataProvider* Random(int n);
	static HugeIntDataProvider* Ascending(int n);
	static HugeIntDataProvider* Descending(int n);
	//���ã�ûд������
	static HugeIntDataProvider* FromFile(const char* filename);

private:
	int n;
	HugeInt* arr;

	HugeIntDataProvider(int n);
};

