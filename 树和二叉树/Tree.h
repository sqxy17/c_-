#ifndef C__TREE_H
#define C__TREE_H

#endif C__TREE_H


//首先树的结构是多种多样的，有双亲表示法，孩子表示法，孩子双亲表示法
//但是上面的这些表示方法都是垃圾，最牛逼的还是左孩子右兄弟表示法（简称孩子兄弟表示法）

typedef int DataType;
//struct TreeNode
//{
//    struct TreeNode* first_child;        //指向的本节点的左边的第一个孩子节点，没有就指向空
//    struct TreeNode* brother;          //指向的是本节点的右边的第一个亲兄弟节点，没有就指向空
//    DataType data;
//};



//二叉树的顺序存储结构        -----记住，这种结构只能存储完全二叉树的数据
//二叉树的顺序存储结构本质上还是靠数组进行存储的
//int arr[x];   ----这样就行了


//二叉树的链式存储结构
//二叉链表
struct BinaryTreeNode
{
    DataType data;
    struct BinaryTreeNode* left_brother;
    struct BinaryTreeNode* right_brother;
};


//三叉链表
struct TridentTreeNode
{
    DataType data;
    struct TridentTreeNode* left_brother;
    struct TridentTreeNode* right_brother;
    struct TridentTreeNode* parent;
};