//#include "stack.h"
//#include<stdlib.h>
//#include<assert.h>
////栈的初始化
//void StackInit(ST* st)
//{
//    assert(st);
//    st->arr=NULL;
//    st->top=st->capacity=0;//注意这里的top设置成0就得先存数据再++，要是设置成-1就得先++再存。
//    //此处的top=0，代表着top为实际元素的个数
//    //所以说栈顶元素的下标是top-1
//}
//
//
////栈的数据插入
//void StackPush(ST* st,DataType x)//st就表示一个栈
//{
//    assert(st);
//    if(st->top==st->capacity)//新的元素始终保存在下标为top处
//    {
//        int NewCapacity=st->capacity=0?4:st->capacity*2;//是0就先给4个空间，不是0就把该空间进行乘2
//        st->arr=realloc(st->arr,sizeof(DataType)*NewCapacity);
//        assert(st->arr);
//        st->capacity=NewCapacity;
//    }
//    st->arr[st->top]=x;
//    st->top++;
//}
//
//
//
////栈的销毁
//void StackDestory(ST* st)
//{
//    assert(st);
//    free(st->arr);
//    st->arr=NULL;
//    st->top=st->capacity=0;
//}
//
//
//
////栈顶元素的删除
//void StackPop(ST* st)
//{
//    assert(st);
//    assert(st->top>0);
//    st->top--;
//}
//
//
//
////获取栈顶元素
//DataType StackTop(ST* st)
//{
//    assert(st && st->top>0);
//    return st->arr[st->top-1];
//}
//
//
//
////获取栈中有效元素的个数
//int StackSize(ST* st)
//{
//    assert(st && st->top>0);
//    return st->top;
//}
//
//
//
////检查栈是否为空，为空返回非0，不为空返回0
//int StackEmpty(ST* st)
//{
//    assert(st);
//    if(st->top>0)
//        return 0;
//    else
//        return 1;
//}