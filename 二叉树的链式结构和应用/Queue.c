#include "Queue.h"
#include<assert.h>
#include<stdlib.h>

//队列的初始化
void QueueInit(Queue* pq)
{
    pq->front=NULL;
    pq->tail=NULL;
}



//队列的销毁
void QueueDestory(Queue* pq)
{
    assert(pq);//队列元素不为空的情况下才能销毁
    QueueNode* cur=pq->front;
    while(cur!=NULL)
    {
        QueueNode* Next=cur->next;//保存cur的下一个结点
        free(cur);//先进先出，所以首先释放掉保存在头部的结点
        cur=Next;
    }
    pq->front=NULL;
    pq->tail=NULL;
}




//队列元素的删除          队列的删除是真删除，会将队头的元素释放掉
void Queuepop(Queue* pq)
{
    assert(pq && pq->front!=NULL);//也就是说首元素不能为空
    QueueNode* Next=pq->front->next;
    free(pq->front);
    pq->front=Next;
    if(pq->front==NULL)
    {
        pq->tail=NULL;//pq->front不是空的时候，说明还有结点。如果为NULL的时候，不讲tail置为空，那么就会造成野指针的情况
    }



}



//队列的入队
void QueuePush(Queue* pq,QDataType x)
{
    assert(pq);
    QueueNode* NewNode=(QueueNode*)malloc(sizeof(QueueNode));
    NewNode->next=NULL;//因为队列的特性，新创建的结点都是在最后面的，所以NewNode->next必定指向NULL
    NewNode->data=x;
    assert(NewNode);
    if(pq->front==NULL)
    {
        pq->front=pq->tail=NewNode;
    }
    else
    {
        pq->tail->next=NewNode;
        pq->tail=NewNode;
    }
}



//队尾元素的查看
QDataType QueueBack(Queue* pq)
{
    assert(pq && pq->tail);
    return pq->tail;
}



//队头元素的查看
QDataType QueueFront(Queue* pq)
{
    assert(pq && pq->front);
    return pq->front;
}
