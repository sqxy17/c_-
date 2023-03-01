#ifndef C__BINAARYTREE_H
#define C__BINAARYTREE_H

#endif C__BINAARYTREE_H
#include<stdio.h>
typedef char DataType;
//二叉树的链式结构

typedef struct BinaaryTreeNode
{
    struct BinaaryTreeNode* left;//左子树
    struct BinaaryTreeNode* right;//右子树
    DataType data;//数据
}BTNode;

BTNode* CreatBinaaryTree();

BTNode* BuyNode(DataType x);

BTNode* PreOrder(BTNode* root);

BTNode* InOrder(BTNode* root);

BTNode* PostOrder(BTNode* root);

void BinaaryTreeSize1(BTNode* root,int* count);//返回二叉树的节点个数    ----计算节点个数有一般有两种方法，一种是传参数计数的方法    另外一种是返回值的那种

int BinaaryTreeSize2(BTNode* root);

int BinaaryTreeLeafSize(BTNode* root);

int BinaaryTreeLevelKSize(BTNode* root,int k);

int BinaaryTreeDepth(BTNode* root);

BTNode* BinaaryTreeFind(BTNode* root,DataType x);

void LevelOrder(BTNode* root);//传入的是一个根节点

int BinaaryTreeComplete(BTNode* root);//判断是否为二叉树

