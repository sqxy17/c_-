#include "heap.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
//堆得初始化
void HeapInit(Heap* hp)
{
    assert(hp);
    hp->arr=NULL;
    hp->size=hp->capacity=0;
}


////这个是向上调整，也就是大堆的排列方式的调整方法
void AdjustUp(int* arr,int n,int child)
//arr是待调整的数组        n是这个数组存放了多少个数据了          child是刚才插入的数据的下标
{
    assert(arr);

    //设计一个孩子和父亲节点比较的循环
    int parent=(child-1)/2;//除了第一个插入的节点，后面插入的结点全都是上一个节点的孩子节点
    while(parent>=0)
    {
        if(arr[child]>arr[parent])
        {
            DataType tmp=arr[child];
            arr[child]=arr[parent];
            arr[parent]=tmp;

            child=parent;
            if(child==0)
                break;
            parent=(child-1)/2;
        }
        else
        {
            break;
        }
    }
}

void HeapPush(Heap* hp,DataType x)
{
    assert(hp);//创建的堆和顺序表在在结构上是十分相似的
    if(hp->size==hp->capacity)
    {
        hp->capacity=(hp->capacity)==0?1:(hp->capacity)*2;//
    }
    hp->arr=(DataType*)realloc(hp->arr,sizeof(DataType)*(hp->capacity));
    assert(hp->arr);
    hp->arr[hp->size]=x;
    hp->size++;

    //在插入数据之后，我们还是要按照堆的排序，所以要对这个数据进行调整

    if(hp->capacity>1)//最大容量只有一个节点的情况下就不用进行调整了
        AdjustUp(hp->arr,hp->size,hp->size-1);//第一个参数是数组   第二个参数是数组已经存放的元素的个数    第三个参数是刚才插入的元素的下标
}
