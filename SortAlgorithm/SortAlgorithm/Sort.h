#pragma once

#include <algorithm>
#include "HugeInt.h"
#include<stdio.h>
#include<stdlib.h>


namespace Sort
{
	template<typename T>
	void StdSort(T* arr, int n) //std::sort
	{
		std::sort(arr, arr + n);
	}

	template<typename T>
	void SelectSort(T* arr, int n)                //选择排序入口
	{
		//std::sort(arr, arr + n);
		
		int i,j,min,temp;
	        for(i=0;i<n-1;i++)
		{
			//min纪录最小值的位置，先假设为第一个
		        min=i;   
			//遍历，如果后面的值小就更新min的位置
		        for(j=i+1;j<n;j++)
			{
			        if(arr[j]<arr[min])
			        min=j;                 
		        }
			//交换
		        if(min!=i)
			{
		                temp=arr[i];
		                arr[i]=arr[min];
		                arr[min]=temp;        
		        }
	        }
		
	 }

	
	template<typename T>
	void MergeSort(T* arr, int n)                 //归并排序入口
	{
		//std::sort(arr, arr + n);
		int *tempArr = (int *)malloc(n * sizeof(int));   
	        void msort(int *arr,int *tempArr,int left,int right);
	        msort(arr,tempArr,0,n-1);
                free(tempArr);
	}
	//递归 
        void msort(int *arr,int *tempArr,int left,int right)
	{   
		//声明合并函数 
	        void merge (int *arr,int *tempArr,int left, int mid, int right); 
	        if (left<right)                                  
		{
			int mid = (left+right)/2;
			//递归划分左半区和右半区 
		        msort(arr,tempArr,left,mid);
		        msort(arr,tempArr,mid+1,right);
		        //合并左右两个有序序列 
		        merge(arr,tempArr,left,mid,right); 		
	        }
        }

        //合并 
	void merge (int *arr,int *tempArr,int left, int mid, int right) 
	{
		int l_pos = left;                               //标记左半区第一个未排序的元素 
	        int r_pos = mid+1;                              //标记右半区第一个未排序的元素
	        int pos = left;                                 //临时数组元素的下标
	        //比较左右序列第一个元素的大小进行合并
	        while (l_pos<=mid && r_pos<=right) 
		{
			if(arr[l_pos]<arr[r_pos])
		        tempArr[pos++]=arr[l_pos++];            //左半区第一个元素小 就赋值给临时数组 
		        else
		        tempArr[pos++]=arr[r_pos++];
	        }
	
		//合并左半区剩余元素
	        while(l_pos<=mid)
		{
			tempArr[pos++]=arr[l_pos++];
	        }
	 
	        //合并右半区剩余元素
	        while(r_pos<=right)
	        {
	 	        tempArr[pos++]=arr[r_pos++];
	        }
	 
	        // 把临时数组中合并后的元素复制回原来的数组
                while (left <= right)
                {
                        arr[left] = tempArr[left];
                        left++;
			
                }
        }

	

	template<typename T>
	void QuickSort(T* arr, int n)                 //快速排序入口
	{
		//std::sort(arr, arr + n);
		void quicksort(int *arr,int p,int r);
	        quicksort(arr,0,n-1);
	}
	void quicksort(int *arr,int p,int r)
	{   
	        int i,j,x,temp;
	        x = arr[r];  //设置最后一个元素为主元，基准元素
	        i = p-1;

	        //j用来遍历比较大小 
	        //p到i放小于主元的值
	        //i+1到j-1是大于主元的值 	
	        if(p<r)
		{
		        for(j=p;j<r;j++)
			{
		                //如果当前元素小，则需要要交换位置，否则不用 
		                if(arr[j]<=x)
				{
			                i=i+1;
			                //交换arr[i]和arr[j] 
			                temp = arr[i];
			                arr[i] = arr[j];
			                arr[j] = temp; 	
		                }
	                 }   
	                //遍历结束，确定主元的最终位置，交换arr[i+1]与主元
	                temp = arr[i+1];
	                arr[i+1] = arr[r];
	                arr[r] = temp; 	
	        }
	        else{
		        return ;
	            }
	
                //再递归左右两个序列 
	        quicksort(arr,p,i);
	        quicksort(arr,i+2,r);		
        }

	template<typename T>
	void ShellSort(T* arr, int n)                //希尔排序入口
	{
		//std::sort(arr, arr + n);
		int gap,i,j,temp,flag;
	        //外循环以不同的gap值对形成的序列进行排序，直到gap=1 
	        for(gap=n/2;gap>=1;gap=gap/2)
		{
			//对各个子序列进行冒泡排序 
		        do{
			        flag = 0; 
			        for(i=0; i<n-gap; i++)
				{
					j = i+gap;
			                if(arr[i]>arr[j])
					{
				                temp = arr[i];
				                arr[i] = arr[j];
				                arr[j] = temp;
				                flag = 1;
			                }	
		                }		
		           }while(flag);
	         }	
	}

	void RadixSort(int* arr, int n); //普通基数排序

	void RadixSort(HugeInt* arr, int n); //大数基数排序
}
