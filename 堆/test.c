#include"heap.h"
#include<stdio.h>
int main(void)
{
    Heap h1;
    HeapInit(&h1);

    HeapPush(&h1,1);
    HeapPush(&h1,2);
    HeapPush(&h1,3);
    HeapPush(&h1,4);
    HeapPush(&h1,5);
    HeapPush(&h1,6);
    HeapPush(&h1,7);
    HeapPush(&h1,8);
    HeapPush(&h1,9);

    for(int i=0;i<(h1.size);i++)
    {
        printf("%d ",h1.arr[i]);
    }
    return 0;
}