// SortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <ctime>
#include "SortAlgorithm.h"
#include "IntDataProvider.h"
#include "HugeIntDataProvider.h"

template<typename T>
void multiThreadSort(SortBase* algortihm, T* arr, int n, int thread = 1)
{
    printf("使用 %d 线程 %s 算法进行排序...\n", thread, algortihm->name());
    int t = clock();
    if (thread == 1)
    {
        algortihm->sort(arr, n);
    }
    else
    {
        //多线程
    }
    printf("排序完成，用时%.3lfs，验证正确性...\n", double(clock() - t) / CLOCKS_PER_SEC);
    for (int i = 1; i < n; ++i)
    {
        if (arr[i - 1] > arr[i])
        {
            puts("排序结果错误！");
            return;
        }
    }
    puts("排序结果正确！");
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SortBase* sortAlgorithm[] = { new StdSort, new SelectSort, new MergeSort, new QuickSort, new ShellSort, new RadixSort };
    int n = 10000;
    bool isHuge = false;
    int thread = 1;

    //读取参数
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "-n") == 0)
            n = atoi(argv[++i]);
        else if (strcmp(argv[i], "-h") == 0)
            isHuge = true;
        /*else if (strcmp(argv[i], "-t") == 0)
            thread = atoi(argv[++i]);*/
    }

    if (isHuge)
    {
        auto dataProvider = HugeIntDataProvider::Random(n);
        auto arr = new HugeInt[n];
        for (int i = 0; i < ALGORITHM_COUNT; ++i)
        {
            dataProvider->data(arr);
            multiThreadSort(sortAlgorithm[i], arr, n, thread);
        }
        delete[] arr;
    }
    else
    {
        auto dataProvider = IntDataProvider::Random(n);
        auto arr = new int[n];
        for (int i = 0; i < 3; ++i)
        {
            dataProvider->data(arr);
            multiThreadSort(sortAlgorithm[i], arr, n);
        }
        delete[] arr;
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
