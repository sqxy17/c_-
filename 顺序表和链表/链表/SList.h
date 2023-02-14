#include<stdio.h>

#ifndef C__SLIST_H
#define C__SLIST_H

#endif C__SLIST_H


typedef int DataType;    //放在这里还是存放不同的数据的时候，能够快速的更改


typedef struct SList
{
    DataType data;
    struct SList* next;
}SListNode;


void SListPrint(SListNode* ps);

void SListPushBack(SListNode** ps,DataType x);

void SListPopBack(SListNode** ps);

void SListPushFront(SListNode** ps,DataType x);

void SListPopFront(SListNode** ps);

void SListInsert(SListNode** ps,SListNode* pos,DataType x);

void SListInsertAfter(SListNode* pos,DataType x);
