
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

void AdjustUp(int* arr,int child);//这个是向上调整，也就是大堆的排列方式的调整方法

void HeapPush(Heap* hp,DataType x);

void AdjustDown(DataType* arr,int n,int parent);//向下调整   并且假设调整的是一个小根堆

void HeapPop(Heap* hp);

void HeapPrint(Heap* hp);

void PrintTopK(DataType* arr,int n,int k);//第一个变量是待查找数组的地址   第二个变量是数组里面的元素个数     第三个变量是要查找里面最大的k个变量

void HeapSort(int *arr,int n);//传入的是数组，剩下的方式排列       ---常见的是小根堆排序取顶元素


