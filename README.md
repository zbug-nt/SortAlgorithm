
# SortAlgorithm-程序设计与算法大作业
## 使用说明
1.选择参加排序的算法(默认选择排序不参与)         
&emsp;-a <选择的算法>    &emsp; // 写相应的算法代号：选择排序代号1，归并排序代号2，快速排序代号3，归并排序代号4，基数排序代号5       
&emsp;例如全部算法参与排序：      
![d6310e8f39b2a0e24a53d9294585663](https://user-images.githubusercontent.com/117704533/202892497-d686bfbe-c16f-4dd9-afc3-1f8f01c73572.png)

2.数组操作    
（1）选择数组长度（默认10000）   
&emsp;&emsp;&emsp;-n <数组长度>    &emsp;//n后面写数组长度     
&emsp;例如数组长度为100000：     
![image](https://user-images.githubusercontent.com/117704533/202892647-ac3d1fc4-7a54-4aff-958b-482b7b3315e5.png)

（2）选择初始数组状态（默认乱序）    
&emsp;&emsp;&emsp;-d r   &emsp; //乱序       
&emsp;&emsp;&emsp;-d a   &emsp; //升序      
&emsp;&emsp;&emsp;-d d   &emsp;//降序       
&emsp;例如选数组初始状态为升序：    
![image](https://user-images.githubusercontent.com/117704533/202892706-a117d66c-4b25-4415-a095-26d4357fa08b.png)


3.大数版本   
&emsp;-h   &emsp;  //启用大数    

4.多线程   
&emsp;-t <线程数>      

5.启用输出        
&emsp;-o     

   
<br /><br />
## 常规版本 
### 一、实现这五种排序并分析  
#### 1. 选择排序   
基本思想                              
&emsp;&emsp;每一趟排序待排序序列中选出最小的元素，(先假设第一个元素是最小的，遍历后面的元素，不断记录更小的元素下标，即可得到一趟遍历中最小元素)然后与该未排序序列的第一个元素交换位置，确定该元素的位置，如此重复直到所有元素排序完成。  
       
  时间复杂度     
 &emsp;&emsp; 一趟排序的比较次数是0(n)，重复n-1趟，所以时间复杂度是0(n^2)。

主要代码        
![在这里插入图片描述](https://img-blog.csdnimg.cn/708f1c1ec72b4e289aa35e0775810ce9.png)

<br /><br />


#### 2. 归并排序   
 基本思想        
&emsp;&emsp; 先将最初长度为n的待排序序列从中间划分成两个子序列，再递归划分左右两个子序列，形成 n个长度为1的有序子序列 。再将相邻的两个子序列两两合并，形成有序序列，如此重复最后得到长度为n的有序序列。     
&emsp;&emsp; 一趟合并的过程：借助一个临时数组，比较待合并的左右两个序列的第一个元素大小，将较小的赋值给临时数组，直到两个子序列的元素都完成合并。     
 
 时间复杂度  
&emsp;&emsp; 归并排序的时间复杂度为归并的趟数与每一趟归并的时间的复杂度的乘积。子算法merge合并的时间复杂度为0(n),趟数为log₂n ,故算法复杂度为0(nlogn)。

主要代码       
![在这里插入图片描述](https://img-blog.csdnimg.cn/73476f23fccf474397814540cea9ab4d.png)
<br /><br />


#### 3. 快速排序   
基本思想
&emsp;&emsp;  从当前待排序序列中选择最后一个元素作为主元，把小于等于主元的所有元素移动到主元前边，大于等于基准元素的所有元素都移动到主元后边，确定主元的最终位置，然后分别对前后两个序列递归上述过程，直到所有元素完成排序。

时间复杂度  
&emsp;&emsp; 快排一趟排序确定一个元素的位置，时间复杂度为O(n)，在平均情况下递归趟数为log₂n ，算法复杂度为0(nlogn)。在序列已经有序的情况下，需要重复n-1趟才能确定所有元素的位置，时间复杂度为0(n^2)。


主要代码    
![在这里插入图片描述](https://img-blog.csdnimg.cn/065e73346bc648a7bde94af7a34bed3e.png)

<br /><br />


#### 4. 希尔排序   
基本思想    
&emsp;&emsp;首先确定元素间隔数gap，然后将所有位置相隔gap的元素视为一个子序列，对各个子序列进行排序；然后缩小间隔数，并重新对形成的子序列进行排序，直到gap = 1。
&emsp;&emsp;这里初始gap设为n/2，每次缩小一半。子序列内部采用冒泡排序。

时间复杂度
&emsp;&emsp;希尔排序的排序趟数为log₂n；当子序列分的越多时，子序列内的元素就越少，元素比较交换次数就越少，而当子序列的个数减少时，整个序列接近有序，子序列的元素虽然变多但元素之间的比较交换次数没有随之变多。所以一般情况下，认为希尔排序的时间复杂度在0(nlogn)与0(n^2)之间。

主要代码     
![在这里插入图片描述](https://img-blog.csdnimg.cn/e172c89a0c8f4e7185c6355711631e02.png)
<br /><br />

#### 5. 基数排序   
基本思想       
&emsp;&emsp;把参加排序的序列中的的元素按第1位的值进行排序（最右边一位为第1位)，然后再按第2位的值进行排序......最后按第d位的值进行排序。每一趟排序过程中若有元素的位值相同，则它们之间仍保留前一趟排序的次序。    
&emsp;&emsp;具体实现借助链表 ，假设参加排序的序列是d位r进制，不足d位的元素在前面补上0。       

 时间复杂度          
 &emsp;&emsp;基数排序的趟数是d趟，每趟要把n个元素依次分配到r个分队，再集合到总队，每趟花费的时间为0(n+r）。所以基数排序总的时间复杂度为0(d(n+r))。
     
 主要代码    
 ![](https://img-blog.csdnimg.cn/27ad8a2271fc4b439a09e0e07bd7d2aa.png)

  <br /><br /><br />

  
 
### 二、分析其在不同规模的输入下单机性能变化情况  
#### 1.  实现过程  
 &emsp;&emsp;生成不同长度n=1000,n=10000,n=100000,n=100000的随机数组，计时 ，分别统计这五种排序算法在不同数组长度下随机实验10次的平均运行时间。      
 &emsp;&emsp;
 

#### 2. 结果分析
实验结果  
如下表所示，单位ms
| 输入规模 | n=1000 | n=10000 |n=100000 |n=1000000
 | :----: | :----: | :----: | :----: |:----: |
| 选择排序 | 7 | 757 |77544 | -- |
| 归并排序 |0 | 4 | 36| 353 |
| 快速排序 | 0 | 2 |27| 283 |
| 希尔排序 | 0| 8 | 134 | 2264 |
| 基数排序 | 0 | 0 | 9 | 147 |
<br />

性能分析        
&emsp;&emsp;从实验结果来看，这五种排序耗时从小到大为：基数排序<归并排序和快速排序（一个数量级）<希尔排序<选择排序   
&emsp;&emsp;(1)  快速排序和归并排序在不同输入规模下耗时相近，属于同一个数量级。    
&emsp;&emsp;(2)  希尔排序的耗时 在归并/快排和选择排序之间，但更接近归并/快排，所以时间复杂度更接近0(nlogn)。  
&emsp;&emsp;(3)在输入规模在1000及以下时，五种排序算法用时差别不明显；而输入规模每增大10倍，选择排序耗时增大近似100倍，所以随着输入规模的增大，时间差异越发明显，在输入规模达到百万数量级时，很难运行出结果。
<br /><br />       

总结
| 排序算法 | 平均时间 |稳定性 |备注
 | :----: | :----: | :----: | :----: 
| 选择排序 | O(n^2) | 不稳定 |n小时较好|
| 归并排序 |O(nlogn)  | 稳定 |n大时较好 | 
| 快速排序 | O(nlogn) | 不稳定 | n大、元素较无序时较好 | 
| 希尔排序 |O(nlogn)  | 不稳定 | 更接近O(nlogn)
| 基数排序 | O(d(n+r)) | 稳定 | d 是位数，r是进制 | 

 <br /><br /><br />

## 分布式排序Java版
使用多线程模拟进行分布式排序
单线程处理十五万条数据，分10个线程，共150万条数据
使用CountDownLatch，限定在所有线程执行结束后再进行汇总和写入文件
排序后的结果存储在distributedSort.txt中。
