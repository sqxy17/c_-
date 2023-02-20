
#ifndef C__HEAP_H
#define C__HEAP_H

#endif C__HEAP_H

typedef int DataType;

typedef struct Heap
{
    DataType* arr;
    int size;
    int capacity;
}Heap;


void HeapInit(Heap* hp);

void AdjustUp(int* arr,int n,int child);//这个是向上调整，也就是大堆的排列方式的调整方法

void HeapPush(Heap* hp,DataType x);