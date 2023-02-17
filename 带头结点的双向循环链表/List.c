//#include"List.h"
//#include<stdlib.h>
//#include<assert.h>
//
////链表有8种
////单向    双向
////带头结点    不带头结点
////循环     不循环
////上下三三组合八中
//
//
////初始化双链表
//ListNode* ListInit(ListNode* phead)
//{
//    phead=(ListNode*)malloc(sizeof(ListNode));
//    assert(phead);
//    phead->prev=phead;
//    phead->next=phead;
//    return phead;
//}
//
//
//
//
////输出双链表
//void ListPrint(ListNode* phead)
//{
//    assert(phead);
//    ListNode* cur=phead->next;//带头结点的传过来的空间指定不能是空，所以肯定有phead->next
//    while(cur!=phead)//如果只有一个头结点那就不会进行输出
//    {
//        printf("%d ",cur->data);
//        cur=cur->next;
//    }
//}
//
//
////双链表的尾插
//void ListPushBack(ListNode* phead,DataType x)
//{
//    assert(phead);//带头结点的链表头结点肯定不为空
//    ListNode* NewNode=(ListNode*)malloc(sizeof(ListNode));//创建一个用来保存数据的结点
//    assert(NewNode);
//    ListNode* tail=phead->prev;//用一个结点存放链表的尾结点（也可能是哨兵位）
//    tail->next=NewNode;
//    NewNode->next=phead;
//    NewNode->prev=tail;
//    phead->prev=NewNode;
//    NewNode->data=x;
//}
//
//
//
//
////带头结点的双链表删除尾结点
//void ListPopBack(ListNode* phead)
//{
//    assert(phead && phead->next!=phead);//不能为空，并且不能只有头结点
//    ListNode* tail=phead->prev;
//    phead->prev->prev->next=phead;
//    phead->prev=phead->prev->prev;
//    free(tail);
//}
//
//
//
//
////双链表带头结点前插
//void ListPushFront(ListNode* phead,DataType x)
//{
//    assert(phead);
//    ListNode *NewNode = (ListNode *) malloc(sizeof(ListNode));
//    assert(NewNode);
//    NewNode->data = x;
//    NewNode->next = phead->next;
//    phead->next->prev = NewNode;
//    NewNode->prev = phead;
//    phead->next = NewNode;
//}
//
//
//
//
////带头结点的前删
//void ListPopFront(ListNode* phead)
//{
//    assert(phead && phead->next!=phead);//也就是传过来的链表最少有一个真正的数据
//    ListNode* HNext=phead->next;
//    phead->next->next->prev=phead;
//    phead->next=phead->next->next;
//    free(HNext);
//}
//
//
//
////带头结点的查找          此处写的是pos为地址，并不是第pos个元素
//ListNode* ListFind(ListNode* phead,DataType x)
//{
//    assert(phead && phead->next!=phead);
//    ListNode* pos=phead->next;//cur是第一个元素
//    while(pos!=phead)//
//    {
//        if(pos->data==x)
//        {
//            return pos;
//        }
//    }
//    return NULL;
//}
//
//
//
//
//
////带头结点指定位置的前插
//void ListInsert(ListNode* pos,DataType x)
//{
//    assert(pos && pos->next!=NULL && pos->prev!=NULL);
//    ListNode* NewNode=(ListNode*)malloc(sizeof(ListNode));
//    assert(NewNode);
//    pos->prev->next=NewNode;
//    NewNode->prev=pos->prev;
//    NewNode->next=pos;
//    pos->prev=NewNode;
//}
//
//
//
//
//
//
////删除指定的结点
//void ListErase(ListNode* pos)
//{
//    assert(pos && pos->next!=NULL && pos->prev!=NULL);
//    pos->prev->next=pos->next;
//    pos->next->prev=pos->prev;
//}
//
//
//
////销毁双链表                 -----销毁双链表也要删除头结点
//void ListDestory(ListNode* phead)
//{
//    assert(phead && phead->next!=phead);
//    while(phead->next!=phead)
//    {
//        ListPopFront(phead);
//    }
//    free(phead);//在所有的有效元素的结点释放完毕之后也要释放头结点
//}