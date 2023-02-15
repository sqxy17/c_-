//#include"SList.h"
//#include<stdlib.h>
//#include<assert.h>
//
//
////打印链表的函数
//void SListPrint(SListNode* ps)
//{
//    SListNode* cur=ps;//如果这个链表本来就是空的，那么就不会参与循环
//    while(cur!=NULL)
//    {
//        printf("%d ",cur->data);
//        cur=cur->next;
//    }
//}
//
//
//
//
////单链表尾插
//void SListPushBack(SListNode** ps,DataType x)//这里有个小坑，要用二级指针接收链表指针，否则无法变更数据
//{
//    SListNode* NewNode=(SListNode*)malloc(sizeof(DataType));//首先不管传入的指着是否为空，都要进行插入这个操作，那就先创建
//    if(NewNode==NULL)
//    {
//        printf("创建空间失败");
//        exit(-1);
//    }
//    NewNode->next=NULL;
//    NewNode->data=x;
//
//    if(*ps==NULL)
//    {
//        *ps=NewNode;
//    }
//    else
//    {
//        SListNode* cur=*ps;
//        while(cur->next)//下一个结点是空，也就是最后一个元素才会停止
//        {
//            cur=cur->next;
//        }
//        cur->next=NewNode;
//    }
//}
//
//
//
//
////单链表头插
//void SListPushFront(SListNode** ps,DataType x)
//{
//    SListNode* NewNode=(SListNode*)malloc(sizeof(DataType));
//    assert(NewNode);//创建失败就报错
//    NewNode->data=x;
//    NewNode->next=(*ps);//新结点指向表所指向的结点
//    *ps=NewNode;
//}
//
//
//
//
////单链表尾删
//void SListPopBack(SListNode** ps)//尾删有两种办法         第二种就是双指针的办法，一个保存ps->next,一个保存ps->next->next
//{
//    //第一种
//    assert(*ps);
//    if((*ps)->next==NULL)//只有一个结点
//    {
//        free(*ps);
//        *ps=NULL;
//    }
//    else//找到倒数第二个结点
//    {
//        SListNode* end=*ps;
//        while(end->next->next)
//        {
//            end=end->next;
//        }
//        free(end->next);
//        end->next=NULL;
//    }
//}
//
//
//
//
//
////头删的方法
//void SListPopFront(SListNode** ps)
//{
//    assert(*ps);
//    SListNode* Front=*ps;
//    (*ps)=(*ps)->next;//不管是否为空
//    free(Front);
//}
//
//
//
////单链表进行查找
//SListNode* SListFind(SListNode* ps,DataType x)
//{
//    assert(ps);
//    while(ps)
//    {
//        if(ps->data==x)
//        {
//            return ps;
//        }
//        ps=ps->next;
//    }
//    return ps;
//}
//
//
//
//
////单链表进行指定位置前插       ----官方的库函数只有链表指定位置的后面一位插入，并没有在指定位置前面插入的库函数。
////还有一种插入定义的是在第几个元素之后   也就是int pos,pos指的是第几个元素
////此处的函数是在指定位置之前进行插入的
//void SListInsert(SListNode** ps,SListNode* pos,DataType x)
//{
//    assert(*ps && pos);//链表没有元素的时候无法插入，指定的地址不能为空
//    SListNode* NewNode=(SListNode*)malloc(sizeof(DataType));
//    assert(NewNode);
//    SListNode* pre=*ps;
//    while(pre)
//    {
//        if(pre==pos)//要插入第一个结点的前面
//        {
//            NewNode->next=pre;
//            NewNode->data=x;
//            *ps=NewNode;
//        }
//        if(pre->next==pos)
//        {
//            NewNode->data=x;
//            NewNode->next=pos;
//            pre->next=NewNode;
//            return;
//        }
//        pre=pre->next;
//    }
//}
//
//
//
//
//
//
////单链表指定位置后插
//void SListInsertAfter(SListNode* pos,DataType x)
//{
//    assert(pos);
//    SListNode* NewNode=(SListNode*)malloc(sizeof(DataType));
//    assert(NewNode);
//    NewNode->next=pos->next;
//    pos->next=NewNode;
//    NewNode->data=x;
//}
//
//
//
//
////指定位置删除
//void SListErase(SListNode** ps,SListNode* pos)
//{
//    assert(*ps && pos);
//    if(*ps==pos)
//    {
//        *ps=pos->next;
//        free(pos);
//    }
//    SListNode* pre=*ps;
//    while(pre->next)
//    {
//        if(pre->next==pos)
//        {
//            pre->next=pos->next;
//            free(pos);
//        }
//    }
//}
//
//
//
//
//
////指定位置后面的结点删除
//void SListEraseBack(SListNode* pos)//首先我们要清楚传的pos并不是NULL
//{
//    assert(pos);
//    if(pos->next==NULL)
//    {
//        ;
//    }
//    else
//    {
//        SListNode* pre=pos->next;
//        pos->next=pos->next->next;
//        free(pre);
//    }
//}
//

