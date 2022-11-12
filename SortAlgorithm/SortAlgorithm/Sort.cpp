#include "Sort.h"

void Sort::RadixSort(int* arr, int n) //普通基数排序
{
	//std::sort(arr, arr + n);
	
	int num,max ;          	
	int* temp = (int*)malloc(sizeof(int)*n);
	//找出数组中的最大值
	max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max){
			max = arr[i];
		}
	}			
	//从个位开始，循环次数为最大数的位数 
	for(int base=1;max/base >0;base *= 10) 
	{
		int bucket[10] = {0};     //桶初始值附0
		//统计桶编号对应的数据个数 
		for(int i=0;i<n;i++) 
		{
			//取个位十位百位...上的数字,也是桶编号 
			num = arr[i]/base%10;
			bucket[num]++;		
		}	
		//累加,最后桶的值代表数据排第几 
		for(int i=1;i<10;i++){
			bucket[i]=bucket[i-1]+bucket[i];
		}	
		//从后往前放到临时数组
		for(int i=n-1;i>=0;i--)
		{
			int k ;                 
			num = arr[i]/base%10;
			//数据放的位置，即临时数组下标 
			k = bucket[num]-1;        
			temp[k] = arr[i];
			bucket[num]--;	
		} 	
	    //把第一遍排序结果拷贝回原数组 
		for (int i = 0; i < n; i++){
			arr[i] = temp[i];
		}
	}
	free(temp);	
	
}

void Sort::RadixSort(HugeInt* arr, int n) //大数基数排序
{
	std::sort(arr, arr + n);
}
