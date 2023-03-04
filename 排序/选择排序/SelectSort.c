#include "SelectSort.h"

//选择排序可以说是各方面都是最差的排序
//其基本思想就是每次都选出在当次规定下标内的最大值（最小值）放在末尾或者开头
//先选出最大值后在进行交换


void swap1(int* p1,int* p2)
{
    int tmp=0;
    tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}



//输出数组
void PrintSort1(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}




//当前的这种写法是每次只选一个          ---此处按照升序的排列设计
void SelectSort1(int* arr,int n)
{
    for(int begin=0;begin<n-1;begin++)//每次选出的最小的插入的位置,倒数第二个元素插入之后就不用管倒数第一个了
    {
        for(int i=begin;i<n-1;i++)
        {
            if(arr[i]<arr[begin])
            {
                swap1(&arr[i],&arr[begin]);
            }
        }
    }
}




//稍微快一点的选择排序       优化后的选择排序：直接设置两个大小

void SelectSort2(int* arr,int n)
{
    int begin=0;
    int end=n-1;
    while(begin<end)
    {
        int mini=begin;//首先最小值的默认下标是当前数组的第一个元素
        int maxi=begin;//默认最大值的下标是当前数组的第一个元素
        for(int i=begin;i<=end;i++)
        {
            if(arr[i]<arr[mini])
            {
                mini=i;//
            }

            if(arr[i]>arr[maxi])
            {
                maxi=i;
            }
        }
        //从这里出来之后，maxi和mini肯定不会相同
        swap1(&arr[maxi],&arr[end]);//在这里我们要考虑一种情况 如果maxi是beging、  或者mini是end
        if(mini==end)//也就是说mini刚好指向的是end的位置，但是上一个交换已经把最小的数字换在
        {
            mini=maxi;
        }
        swap1(&arr[mini],&arr[begin]);
        end--;
        begin++;
    }
}