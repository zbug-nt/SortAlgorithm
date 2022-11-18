#pragma once

class HugeInt
{
public:
	static const int ARR_SIZE = 20;
	static const int BASE = 100000;

	static HugeInt Zero();
	static HugeInt Rand();

	HugeInt();
	//HugeInt(const char* str);
	~HugeInt();

	bool absEqualTo(const HugeInt&) const;
	bool absLessThan(const HugeInt&) const;
	bool operator==(const HugeInt&) const;
	bool operator!=(const HugeInt&) const;
	bool operator<(const HugeInt&) const;
	bool operator<=(const HugeInt&) const;
	bool operator>(const HugeInt&) const;
	bool operator>=(const HugeInt&) const;
	int getData(int i) const;
	const char* toString();

private:
	int sig; //1: 非负数  0: 负数
	int* data;
	char* str;

	void makeString();
};

