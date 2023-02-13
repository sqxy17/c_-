//
// Created by 17 on 2023/2/12.
//
#include<stdio.h>
#ifndef C__SEQLIST_H
#define C__SEQLIST_H

#endif C__SEQLIST_H

//静态顺序表
//#define N 100       //用于静态顺序表创建数组的容量                 我们一般不去使用静态数组，我们使用的都是动态数组
//#define DataType int      //用于静态数据表创建数据类型
//
//typedef struct SeqList    //现在创建的是静态顺序表
//{
//    DataType arr[N];   //静态数组用来存放数据的数组
//    size_t size;     //静态数组的实际存放的元素个数
//}SL;



//动态顺序表
typedef int DataType;     //这样定义的好处就是,在创建动态顺序表的时候，可以在这里直接更改保存元素的数据类型

typedef struct SeqList
{
    DataType* arr;     //指向动态函数开辟的空间
    size_t size;          //空间中实际保存的元素的个数
    size_t capicity;      //指向的空间能够保存元素的最大个数
}SL;


void SeqListInit(SL* ps);//初始化顺序表函数的声明

void SeqListPushBack(SL* ps,DataType x);//尾插函数的声明

void SeqListPrint(SL* ps);//输出函数的声明

void SeqListDestory(SL* ps);//销毁数据表

void SeqListPopBack(SL* ps);//删除尾部的第一个数据

void SeqListPushFront(SL* ps,DataType x);//头插数据的声明

void SeqListPopFront(SL* ps);//头删数据的声明

int SeqListFind(SL* ps,DataType x);//查找某个元素的值是否在顺序表中

void SeqListErase(SL* ps,size_t pos);//



