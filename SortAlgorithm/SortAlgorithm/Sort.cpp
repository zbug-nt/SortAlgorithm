#include "Sort.h"

template<typename T>
struct Node
{
	T val;
	Node<T>* next;
};

void Sort::RadixSort(int* arr, int n) //普通基数排序
{
	static const int BASE = 1500;

	int min = arr[0], max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		min = arr[i] < min ? arr[i] : min;
		max = arr[i] > max ? arr[i] : max;
	}
	for (int i = 0; i < n; ++i) arr[i] -= min;
	max -= min;

	auto head = new Node<int>[BASE + 1];
	auto tail = new Node<int>*[BASE + 1];
	auto node = new Node<int>[n + 1];
	for (int i = 1; i < max; i *= BASE)
	{
		memset(head, 0, sizeof(Node<int>) * BASE);
		memset(tail, 0, sizeof(Node<int>*) * BASE);
		for (int j = 0; j < n; ++j)
		{
			int t = arr[j] / i % BASE;
			node[j] = {arr[j], NULL};
			if (head[t].next == NULL) head[t].next = &node[j];
			if (tail[t] != NULL) tail[t]->next = &node[j];
			tail[t] = &node[j];
		}
		int p = 0;
		for (int j = 0; j < BASE; ++j)
		{
			auto t = &head[j];
			while (t = t->next)
			{
				arr[p++] = t->val;
			}
			head[j].next = NULL;
			tail[j] = NULL;
		}
	}
	delete[] head;
	delete[] tail;
	delete[] node;

	for (int i = 0; i < n; ++i) arr[i] += min;
}

void Sort::RadixSort(HugeInt* arr, int n) //大数基数排序
{
	std::sort(arr, arr + n);

	static const int RANGE = HugeInt::BASE << 1;

	auto head = new Node<HugeInt>[RANGE + 1];
	auto tail = new Node<HugeInt>*[RANGE + 1];
	auto node = new Node<HugeInt>[n + 1];
	for (int i = 0; i < HugeInt::ARR_SIZE; ++i)
	{
		memset(head, 0, sizeof(Node<HugeInt>) * RANGE);
		memset(tail, 0, sizeof(Node<HugeInt>*) * RANGE);
		for (int j = 0; j < n; ++j)
		{
			int t = arr[j].getData(i) + HugeInt::BASE;
			*(node + j) = { arr[j], NULL };
			if (head[t].next == NULL) head[t].next = &node[j];
			if (tail[t] != NULL) tail[t]->next = &node[j];
			tail[t] = &node[j];
		}
		int p = 0;
		for (int j = 0; j < RANGE; ++j)
		{
			auto t = &head[j];
			while (t = t->next)
			{
				arr[p++] = t->val;
			}
			head[j].next = NULL;
			tail[j] = NULL;
		}
	}
	delete[] head;
	delete[] tail;
	delete[] node;
}
