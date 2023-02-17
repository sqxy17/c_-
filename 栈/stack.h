//#include<stdio.h>
//
//#ifndef C__STACK_H
//#define C__STACK_H
//
//#endif C__STACK_H
//
//
//typedef int DataType;//老规矩
//
////#define N 100
////struct Stack   //这就是静态的栈，实际上很少用到
////{
////    DataType arr[N];
////    int top;//栈顶（-1和0看你怎么去设置）
////};
//
//
//
//
//typedef struct stack//这个栈是动态的实现的，静态的数组很少用只需要创建一个固定的数组和栈顶元素就行
//{
//    DataType *arr;//指向一个开辟的数组空间
//    int top;//栈顶的意思，并且这里的top代表着下标的意思
//    int capacity;//上面的arr数组实际元素的个数
//} ST;
//
//
//void StackInit(ST *st);
//
//void StackPush(ST *st, DataType x);//st就表示一个栈
//
//void StackDestory(ST *st);
//
//int StackEmpty(ST *st);
//
//int StackSize(ST *st);
//
//DataType StackTop(ST *st);
//
//void StackPop(ST *st);
