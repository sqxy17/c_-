#include"SList.h"
int main(void)
{
    SListNode* list1=NULL;//创建了一个链表，并且这个链表没有头结点,没有头结点一定要置空
    SListPushBack(&list1,5);
    SListPushBack(&list1,6);
    SListPushBack(&list1,7);
    SListPrint(list1);
    printf("\n");

    SListInsert(&list1,list1,10086);

    SListPrint(list1);

}


