// SortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <ctime>
#include <thread>
#include "SortAlgorithm.h"
#include "IntDataProvider.h"
#include "HugeIntDataProvider.h"

#define DATA_RAND 0
#define DATA_ASC 1
#define DATA_DESC 2

template<typename T>
void multiThreadSort(SortBase* algorithm, T* arr, int n, int threadCount = 1)
{
    printf("使用 %d 线程 %s 算法进行排序...\n", threadCount, algorithm->name());
    int t = clock();
    if (threadCount == 1)
    {
        algorithm->sort(arr, n);
    }
    else
    {
        //多线程
        auto work = new std::thread[threadCount + 1];
        int _n = n / threadCount;
        for (int i = 0; i < threadCount; ++i)
        {
            *(work + i) = std::thread([=]() { algorithm->sort(arr + i * _n, i == threadCount - 1 ? _n + n % _n : _n); });
        }
        T* temp = new T[n + 1];
        T** curr = new T * [threadCount + 1];
        T** end = new T * [threadCount + 1];
        for (int i = 0; i < threadCount; ++i)
        {
            work[i].join();
            printf("线程 %d 完成，已经过 %dms\n", i, (clock() - t) * 1000 / CLOCKS_PER_SEC);
            curr[i] = arr + i * _n;
            end[i] = curr[i] + (i == threadCount - 1 ? _n + n % _n : _n);
        }
        delete[] work;
        //归并
        for (int i = 0; i < n; ++i)
        {
            int min = -1;
            for (int j = 0; j < threadCount; ++j)
            {
                if (curr[j] < end[j] && (min == -1 || *curr[j] < *curr[min]))
                    min = j;
            }
            *(temp + i) = *curr[min];
        }
        memcpy(arr, temp, n * sizeof(T));
    }
    printf("排序完成，用时 %dms ，验证正确性...\n", (clock() - t) * 1000 / CLOCKS_PER_SEC);
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
    int data = DATA_RAND;
    bool output = false;
    const char* algoIndex = "02345";

    //读取参数
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc)
            n = atoi(argv[++i]);
        else if (strcmp(argv[i], "-h") == 0)
            isHuge = true;
        else if (strcmp(argv[i], "-t") == 0 && i + 1 < argc)
            thread = atoi(argv[++i]);
        else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc)
        {
            ++i;
            if (strcmp(argv[i], "r") == 0 || strcmp(argv[i], "rand") == 0 || strcmp(argv[i], "random") == 0)
                data = DATA_RAND;
            else if (strcmp(argv[i], "a") == 0 || strcmp(argv[i], "asc") == 0 || strcmp(argv[i], "ascending") == 0)
                data = DATA_ASC;
            else if (strcmp(argv[i], "d") == 0 || strcmp(argv[i], "desc") == 0 || strcmp(argv[i], "descending") == 0)
                data = DATA_DESC;
        }
        else if (strcmp(argv[i], "-o") == 0)
            output = true;
        else if (strcmp(argv[i], "-a") == 0 && i + 1 < argc)
            algoIndex = argv[++i];
    }

    if (isHuge)
    {
        HugeIntDataProvider* dataProvider = NULL;
        switch (data)
        {
        case DATA_ASC:
            printf("正在生成长度为 %d 的 升序 大数 数组...\n", n);
            dataProvider = HugeIntDataProvider::Ascending(n);
            puts("生成成功！");
            break;
        case DATA_DESC:
            printf("正在生成长度为 %d 的 降序 大数 数组...\n", n);
            dataProvider = HugeIntDataProvider::Descending(n);
            puts("生成成功！");
            break;
        case DATA_RAND:
        default:
            printf("正在生成长度为 %d 的 乱序 大数 数组...\n", n);
            dataProvider = HugeIntDataProvider::Random(n);
            puts("生成成功！");
            break;
        }
        puts("");
        auto arr = new HugeInt[n + 1];
        int len = strlen(algoIndex);
        for (int i = 0; i < len; ++i)
        {
            int index = algoIndex[i] - (int)'0';
            if (index < 0 || index >= ALGORITHM_COUNT) continue;
            dataProvider->data(arr);
            multiThreadSort(sortAlgorithm[index], arr, n, thread);
            if (output)
            {
                char filename[50] = {""};
                sprintf(filename, "%s.txt", sortAlgorithm[index]->name());
                printf("正在输出到文件\"%s\"...\n", filename);
                FILE* file = fopen(filename, "w");
                if (!file)
                {
                    puts("打开文件失败！");
                    continue;
                }
                for (int j = 0; j < n; ++j) fprintf(file, "%s\n", arr[j].toString());
                fclose(file);
                puts("输出完成！");
            }
            puts("");
        }
        delete[] arr;
    }
    else
    {
        IntDataProvider* dataProvider = NULL;
        switch (data)
        {
        case DATA_ASC:
            printf("正在生成长度为 %d 的 升序 int 数组...\n", n);
            dataProvider = IntDataProvider::Ascending(n);
            puts("生成成功！");
            break;
        case DATA_DESC:
            printf("正在生成长度为 %d 的 降序 int 数组...\n", n);
            dataProvider = IntDataProvider::Descending(n);
            puts("生成成功！");
            break;
        case DATA_RAND:
        default:
            printf("正在生成长度为 %d 的 乱序 int 数组...\n", n);
            dataProvider = IntDataProvider::Random(n);
            puts("生成成功！");
            break;
        }
        puts("");
        auto arr = new int[n + 1];
        int len = strlen(algoIndex);
        for (int i = 0; i < len; ++i)
        {
            int index = algoIndex[i] - (int)'0';
            if (index < 0 || index >= ALGORITHM_COUNT) continue;
            dataProvider->data(arr);
            multiThreadSort(sortAlgorithm[index], arr, n, thread);
            if (output)
            {
                char filename[50] = { "" };
                sprintf(filename, "%s.txt", sortAlgorithm[index]->name());
                printf("正在输出到文件\"%s\"...\n", filename);
                FILE* file = fopen(filename, "w");
                if (!file)
                {
                    puts("打开文件失败！");
                    continue;
                }
                for (int j = 0; j < n; ++j) fprintf(file, "%d\n", arr[j]);
                fclose(file);
                puts("输出完成！");
            }
            puts("");
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
