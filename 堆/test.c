#include"heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    srand(time(NULL));
    int* arr=malloc(sizeof(int)*1000);
    int i=0;
    for(i=0;i<1000;i++)
    {
        arr[i]=rand()%10000;
    }
    arr[0]=100001;
    arr[1]=100002;
    arr[2]=100003;
    arr[3]=100004;
    arr[4]=100005;
    PrintTopK(arr,1000,10);//数组  数组内保存了多少数字   找出前10个最大的数
}