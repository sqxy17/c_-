#pragma  once
#include<stdio.h>
//这个只是队列的每个元素的结点，和之前的链表并不是很一样，链表是创建一个结点类型的指针，指向第一个元素的结点
//队列是创建一个结构体，里面包含了指向链表第一个元素的结点的指针和指向最后一个元素结点的指针
//还有请记住：队尾就是链表尾，因为新增的结点都是上一个结点的next指针指向下一个结点的，也就是说新增的结点一直都在后面
//队头就是链表头，删除的时候都是先删除链表的头部。
//队列是有单链表实现的，所以请记住最后一个结点的next指针是指向NULL的
typedef struct BinaaryTreeNode BTNode;//这就是前置声明，有没有不重要，声明了以后就能使用。       这里因为没有
typedef BTNode* QDataType;//这边是每个节点存的数据类型

typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;//我们要清楚单链表的表尾的next指针是指向next的
}QueueNode;

typedef struct Queue
{
    QueueNode* front;
    QueueNode* tail;
}Queue;



void QueueDestory(Queue* pq);

void QueueInit(Queue* pq);

void QueuePush(Queue* pq,QDataType x);

void Queuepop(Queue* pq);

QDataType QueueBack(Queue* pq);

QDataType QueueFront(Queue* pq);