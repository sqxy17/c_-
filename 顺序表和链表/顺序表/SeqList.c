#include"SeqList.h"
#include<stdlib.h>
#include<assert.h>
//这里的接口函数适用于顺序表的各种增删改查，其各种函数的声明保存在SeqList中

//初始化顺序表的函数
void SeqListInit(SL* ps)
{
    ps->arr=NULL;//刚创建的顺序表还未保存数据
    ps->size=ps->capicity=0;//这两个值也为0
}




//检查空间               -----前插或者后插之前先进行空间大小的检测，不够要扩容
void SeqListCheckCapicity(SL* ps)
{
    int newcapicity;
    //首先判断传入的size和capicity是否相同,相同的情况就要考虑扩容
    //但是这个相同会有两种情况，一种是刚初始化完，另一种是数据已经插满
    if(ps->size==ps->capicity)
    {
        newcapicity=ps->capicity==0?4:(ps->capicity)*2;   //为空就先创建4个变量，不为空就将原来的空间翻倍       不管前插还是后插
        ps->capicity=newcapicity;  //既然增容成功就不能是原来的大小了
    }
    ps->arr=realloc(ps->arr,sizeof(DataType)*newcapicity);
    if(ps->arr==NULL)
    {
        printf("int newcapicity\n");
        exit(-1);//exit函数会将整个程序退出    参数为0，是正常退出，参数为非0，就是异常退出
    }
}



//尾插顺序表的函数
void SeqListPushBack(SL* ps,DataType x)//接收顺序表的地址，和待插入数据
{
    SeqListCheckCapicity(ps);
    ps->arr[ps->size]=x;  //size刚好为保存的下标
    ps->size++;
}







//输出顺序表里面的元素
void SeqListPrint(SL* ps)
{
    int i=0;
    for(i=0;i<ps->size;i++)
    {
        printf("%d\n",ps->arr[i]);
    }
}




//销毁数据表中的数据
void SeqListDestory(SL* ps)
{
    free(ps->arr);
    ps->arr=NULL;
    ps->size=ps->capicity=0;
}



//尾删数据
void SeqListPopBack(SL* ps)//两种方法，一种断言，一种判断
{

//    assert(ps->size>0)//第一种方法，用的时候要添加断言的头文件
//    ps->size--;
//
    if(ps->size>0)
    {
        ps->size--;
    }
}




//头插数据
void SeqListPushFront(SL* ps,DataType x)
{
    int i=0;//用于循环
    SeqListCheckCapicity(ps);
    int end=ps->size-1;//end是最后一个元素的下标
    for(i=end;i>=0;i--)
    {
        ps->arr[end+1]=ps->arr[end];
    }
    ps->arr[0]=x;
    ps->size++;//增加了一个数据，记得size++
}



//头删数据           -----同样也是两种方法
void SeqListPopFront(SL* ps)
{
    assert(ps->size>0);
    int begin=1;
    while(begin<ps->size)
    {
        ps->arr[begin-1]=ps->arr[begin];
        begin++;
    }
    ps->size--;
}