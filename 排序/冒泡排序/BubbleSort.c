#include "BubbleSort.h"

//冒泡排序两两对比交换，第一趟要进行n-1次。  
void swap2(int* p1,int* p2)
{
    int tmp=0;
    tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}

void BubbleSort1(int* arr,int n)//指定升序还是降序，然后进行排列
{
    int num=n-1;
    while(num)
    {
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap2(&arr[i],&arr[i+1]);
            }
        }
        num--;
    }
}




//冒泡排序优化
void BubbleSort2(int* arr,int n)
{
    int num=n-1;
    while(num)
    {
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                count++;
                swap2(&arr[i],&arr[i+1]);
            }
        }
        if(count==0)//也就是说如果有一趟不发生交换了，那就是已经有序了，可以直接结束这次的排序
        {
            break;
        }
        num--;
    }
}