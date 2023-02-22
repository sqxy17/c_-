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


void swap(DataType* num1,DataType* num2)
{
    DataType tmp=*num1;

    *num1=*num2;
    *num2=tmp;
}

//向上调整
//向上调整是用于堆的插入，将最后的插入的数字大堆或者小堆的顺序向上调整
void AdjustUp(int* arr,int child)
//arr是待调整的数组                child是刚才插入的数据的下标
{
    assert(arr);

    //设计一个孩子和父亲节点比较的循环
    int parent=(child-1)/2;//除了第一个插入的节点，后面插入的结点全都是上一个节点的孩子节点
    while(parent>=0)
    {
        if(arr[child]<arr[parent])//这里面的大于号小于号根据大小堆进行调整
        {
            swap(&arr[child],&arr[parent]);
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

void HeapPush(Heap* hp,DataType x)//插入是在堆的末尾进行插入的
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
        AdjustUp(hp->arr,hp->size-1);//第一个参数是数组   第二个参数是数组已经存放的元素的个数
}



void AdjustDown(DataType* arr,int n)//向下调整   并且假设调整的是一个小根堆
{
    int parent=0;//删除根元素，就是要从头开始调整         -----child,parent均代表下标元素
    int child=parent*2+1;

    while(child<n)//大根堆的话>就得换成<了,    -----不满足这个条件就证明parent目前已经是叶节点了
    {
        if(child+1<n && arr[child+1]<arr[child])//如果右子树存在就是小于的情况
        {
            child++;
        }
        if(arr[parent]>arr[child])
        {
            swap(&arr[parent],&arr[child]);
            parent=child;
        }
        else
        {
            break;
        }
        child=child*2+1;
    }
}


//堆元素的删除           ----堆的元素删除都是从栈顶开始的
void HeapPop(Heap* hp)//删除元素删除的是堆顶的元素
{
    assert(hp && hp->arr);
    if(hp->size==1)//只有一个堆顶元素那就不用删除了，直接置空就行，起码得有俩元素
    {
        free(hp->arr);
        hp->arr=NULL;
        hp->size--;
    }
    swap(&hp->arr[0],&hp->arr[hp->size-1]);//不管是不是
    hp->size--;

    AdjustDown(hp->arr,hp->size);//将这个数组和数组的实际元素传过去,这个实际元素已经将交换的末尾元素减去了
}




//堆元素的输出
void HeapPrint(Heap* hp)
{
    assert(hp && hp->arr);
    for(int i=0;i<(hp->size);i++)
    {
        printf("%d ",hp->arr[i]);
    }
    printf("\n");
}




//堆的TOPK问题             -----这种问题一般数据的总量是远大于k的
void PrintTopK(DataType* num_arr,int n,int k)//第一个变量是待查找数组的地址   第二个变量是数组里面的元素个数     第三个变量是要查找里面最大的k个变量
{
    int i=0;
    Heap h1;
    HeapInit(&h1);
    for(i=0;i<k;i++)//创建k个元素的小根堆
    {
        HeapPush(&h1,num_arr[i]);
    }
    //从这里开始，剩下n-k个数字，下标从k开始用
    for(i=k;i<n;i++)
    {
        if(num_arr[i]>h1.arr[0])
        {
            HeapPop(&h1);
            HeapPush(&h1,num_arr[i]);
        }
    }
    HeapPrint(&h1);
}


void HeapSort(int *arr,int n)//传入的是数组，剩下的方式排列       ---常见的是小根堆排序取顶元素
{

}