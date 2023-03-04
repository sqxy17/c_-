#include "ShellSort.h"
//希尔排序就是在插入排序的基础上增加的

//输出数组
void PrintSort(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}


//希尔排序的最常见的一种写法
void ShellSort1(int* arr,int n)
{
    int gap=n;//gap就是分的组数     并且每组的元素都是中间间隔gap-1（或中和说下一个元素的下标是  当前下标+gap）个元素   a b c d e    gap是3的情况下a就和d一组
    while(n>1)
    {
        gap/=2; //还有一种写法是gap=gap/3+1     这个加1是很关键的，因为是需要gap=1的时候进行插排
        for(int j=0;j<gap;j++)//gap是多少就分了几组，也就是下标分别为0-(gap-1)这些元素为组长向后进行分组
        {
            for(int i=j;i<n-gap;i+=gap)//分的gap组的其中一组进行插排
            {
                int end=i;
                int x=arr[end+gap];
                while(end>=0)//这个循环是要将x顺序插入数组
                {
                    if(arr[end]>x)
                    {
                        arr[end+gap]=arr[end];
                        end-=gap;
                    }
                    else
                    {
                        break;
                    }
                }
                arr[end+gap]=x;
            }
        }
    }

}





//希尔排序的另外一种改进的写法             改进的写法主要体现在循环的使用，多组并排
void ShellSort2(int* arr,int n)
{
    int gap=n;
    while(gap>1)
    {
        gap/=2;
        for(int i=0;i<n-gap;i++)//这样的写法就是不进行分组了
        {
            int end=i;
            int x=arr[end+gap];
            while(end>=0)//这个循环是要将x顺序插入数组
            {
                if(arr[end]>x)
                {
                    arr[end+gap]=arr[end];
                    end-=gap;
                }
                else
                {
                    break;
                }
            }
            arr[end+gap]=x;
        }
    }

}


