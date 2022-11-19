#define _CRT_SECURE_NO_WARNINGS //sprintf_s就是乐色

#include "HugeInt.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>

HugeInt::HugeInt()
{
	sig = 1;
	data = new int[ARR_SIZE];
	memset(data, 0, sizeof(data));
	str = NULL;
}

HugeInt::~HugeInt()
{
}

HugeInt HugeInt::Zero()
{
	HugeInt ret;
	return ret;
}

HugeInt HugeInt::Rand()
{
	HugeInt ret;
	bool isZero = true;
	for (int i = 0; i < ARR_SIZE; ++i)
	{
		ret.data[i] = ((rand() << 15) | rand()) % BASE;
		if (ret.data[i] != 0) isZero = false;
	}
	ret.sig = isZero ? 1 : rand() & 1;
	return ret;
}

bool HugeInt::absEqualTo(const HugeInt& other) const
{
	for (int i = 0; i < ARR_SIZE; ++i)
	{
		if (data[i] != other.data[i]) return false;
	}
	return true;
}

bool HugeInt::absLessThan(const HugeInt& other) const
{
	for (int i = ARR_SIZE - 1; i >= 0; --i)
	{
		if (data[i] < other.data[i]) return true;
		if (data[i] > other.data[i]) return false;
	}
	return false;
}

bool HugeInt::operator==(const HugeInt& other) const
{
	return absEqualTo(other) && sig == other.sig;
}

bool HugeInt::operator!=(const HugeInt& other) const
{
	return !(*this == other);
}

bool HugeInt::operator<(const HugeInt& other) const
{
	if (sig < other.sig) return true;
	if (sig > other.sig) return false;
	if (sig == 1) return absLessThan(other);
	else return other.absLessThan(*this);
}

bool HugeInt::operator<=(const HugeInt& other) const
{
	if (sig < other.sig) return true;
	if (sig > other.sig) return false;
	if (sig == 1) return !other.absLessThan(*this);
	else return !absLessThan(other);
}

bool HugeInt::operator>(const HugeInt& other) const
{
	return other < *this;
}

bool HugeInt::operator>=(const HugeInt& other) const
{
	return other <= *this;
}

int HugeInt::getData(int i) const
{
	return sig == 1 ? data[i] : -data[i];
}

void HugeInt::makeString()
{
	str = new char[ARR_SIZE * 5 + 5];
	char* p = str;
	if (sig == 0)
	{
		*p = '-';
		++p;
	}
	*p = '0';
	*(p + 1) = '\0';
	bool first = true;
	for (int i = ARR_SIZE - 1; i >= 0; --i)
	{
		if (!first)
		{
			int l = sprintf(p, "%05d", data[i]);
			p += l;
		}
		else if (data[i] != 0)
		{
			int l = sprintf(p, "%d", data[i]);
			p += l;
			first = false;
		}
	}
}

const char* HugeInt::toString()
{
	if (str == NULL) makeString();
	return str;
}
