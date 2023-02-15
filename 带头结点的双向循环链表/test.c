
#include"List.h"
int main(void)
{
    ListNode* list1;//定义了一个表
    list1=ListInit(list1);
    ListPushBack(list1,1);
    ListPushBack(list1,2);
    ListPushFront(list1,3);
    ListPushFront(list1,4);
    ListPrint(list1);
    printf("\n");

    ListPopFront(list1);
    ListPrint(list1);
    printf("\n");

    ListDestory(list1);
    printf("\n");



}