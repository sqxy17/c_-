#include "InsertSort.h"
#include<assert.h>
#include<stdio.h>
//传入的数组是乱序的，通过插入的情况进行排序
//函数的基本思想也就是每次进行插入的时候都从后开始比较，然后将待插入数字按照顺序进行比较插入
void InsertSort(int* arr,int n)//传入的数组，n是传入的数组的实际的元素个数
{
    assert(arr && n);
    for(int i=0;i<n-1;i++)//数组就一个元素也就不用排序了
    {
        int end=i;//首先将第一个元素看做一个数组，随后进行插入排序
        int x=arr[end+1];//arr[end+1]请注意i的取值范围，end+1最大也就是n-1，所以不会越界
        while(end>=0)
        {
            if(arr[end]>x)
            {
                arr[end+1]=arr[end];//这一步是因为我们假设这个数组是升序的，既然这个数字要插入那么就说明，当前的arr[end]肯定是要往后挪动一位的
                end--;//现在的end这个下标指向后面的一位
            }
            else
            {
                break;//如果在这里停止，说明x是大于arr[end]的，那就需要放在arr[end+1]的位置
            }
        }
        arr[end+1]=x;//在这里不管是因为x大于中间的数字，还是end下标为0时还小于arr[end]，都要在这里进行赋值
    }

}


