#include"heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int arr[10]={1,5,2,7,9,3,6,12,25,32};


    HeapSort(arr,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
}