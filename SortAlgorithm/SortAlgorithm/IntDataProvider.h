#pragma once

class IntDataProvider
{
public:
	static const int MAX = 1000000;
	static const int MIN = -1000000;

	~IntDataProvider();
	int size();
	void data(int* buf);

	static IntDataProvider* Random(int n);
	static IntDataProvider* Ascending(int n);
	static IntDataProvider* Descending(int n);
	//别用，没写，摆了
	static IntDataProvider* FromFile(const char* filename);

private:
	int n;
	int* arr;

	IntDataProvider(int n);
};

