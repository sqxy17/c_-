#include "BinaaryTree.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<math.h>
#include"Queue.h"


//创建一个二叉树树节点（创建出来的根，左右子树都有可能）
BTNode* BuyNode(DataType x)
{
    BTNode* node=malloc(sizeof(BTNode));
    assert(node);
    node->data=x;
    node->left=node->right=NULL;
    return node;
}




//创建二叉树
BTNode* CreatBinaaryTree()
{
    BTNode* nodeA=BuyNode('A');
    BTNode* nodeB=BuyNode('B');
    BTNode* nodeC=BuyNode('C');
    BTNode* nodeD=BuyNode('D');
    BTNode* nodeE=BuyNode('E');
    BTNode* nodeF=BuyNode('F');
    BTNode* nodeG=BuyNode('G');

    nodeA->left=nodeB;
    nodeA->right=nodeC;
    nodeB->left=nodeD;
    nodeB->right=nodeG;
    nodeC->left=nodeE;
    nodeC->right=nodeF;

    return nodeA;//返回的是根节点
}



//前序遍历     -----重点之一
BTNode* PreOrder(BTNode* root)   //root  根的意思
{
    if(root==NULL)//请注意这种不能用assert了，因为这个空是递归的停止条件
    {
        printf("NULL ");
        return NULL;
    }
    printf("%c ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}


//中序遍历
BTNode* InOrder(BTNode* root)
{
    if(root==NULL)
    {
        printf("NULL ");
        return NULL;
    }
    InOrder(root->left);
    printf("%c ",root->data);
    InOrder(root->right);
}


//后续遍历
BTNode* PostOrder(BTNode* root)
{
    if(root==NULL)//1.根节点不能为空     2.这是个停止的条件
    {
        printf("NULL ");
        return NULL;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ",root->data);
}



//方法一  计算节点个数                       也就是说这种方法有一定的局限性
//但是这种计数的方法面对多线程的时候就没办法了（多个二叉树同时计算节点个数，但是计数的count只有一个）
void BinaaryTreeSize1(BTNode* root,int* count)//返回二叉树的节点个数    ----计算节点个数有一般有两种方法，一种是传参数计数的方法    另外一种是返回值的那种
{
    if(root==NULL)
    {
        return;
    }
    (*count)++;//只要节点不是空，那就计数
    BinaaryTreeSize1(root->left,count);
    BinaaryTreeSize1(root->right,count);
}




//方法二 计算节点个数            这种方法靠的是递归返回值
int BinaaryTreeSize2(BTNode* root)
{
    if(root!=NULL)
    {
        return BinaaryTreeSize2(root->left)+ BinaaryTreeSize2(root->right)+1;
    }
    else
    {
        return 0;
    }
}




//计算叶子节点个数
int BinaaryTreeLeafSize(BTNode* root)
{

    if(root==NULL)//这个节点首先判断的是根节点，也就是说，根节点如果是空的情况下那就执直接返回了
    {
        //第一个作用是判断是否根节点也是空        另一个作用是用来判断叶子节点的子树是否为空
        return 0;
    }

    //叶子结点怎么找？首先是left right都是NULL
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }

    //如果两种情况都不是的情况下，那就是中间的节点
    return BinaaryTreeLeafSize(root->left)+ BinaaryTreeLeafSize(root->right);
}





//计算第k层的节点个数        总体的方法还是递归
//想要查第四层，还是要当成第一层算
int BinaaryTreeLevelKSize(BTNode* root,int k)  //可以理解为求root这个树的第k层，如果k=1直接就返回了。如果
{
    assert(k>=1);//主要是避免第一次传入的k不符合
    if(root==NULL)//作用1.首次传入的结点为空那就返回0       作用2.后续的递归传入空树的停止条件
    {
        return 0;
    }

    if(k==1)//这就是将后续的第k层，当做第一层的根节点来看
    {
        return 1;
    }

    return BinaaryTreeLevelKSize(root->left,k-1)+BinaaryTreeLevelKSize(root->right,k-1);//根节点的第k层，也就是根节点的左右子树的第k-1层
}





//计算二叉树的高度
int BinaaryTreeDepth(BTNode* root)
{
    if(root==NULL)//递归的时候首先看第一次传入的参数的停止条件能不能被后面调用的继续使用
    {
        return 0;
    }

    int left=BinaaryTreeDepth(root->left);//如果左子树的节点是空，left就会为0
    int right=BinaaryTreeDepth(root->right);
    return fmax(left,right)+1;//+1是因为这个1是当前树的深度        每个节点单独的高度都是1
}




//二叉树查找值为x的节点
BTNode* BinaaryTreeFind(BTNode* root,DataType x)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==x)
    {
        return root;
    }
    BTNode* left= BinaaryTreeFind(root->left,x);
    if(left!=NULL)
        return left;
    BTNode* right= BinaaryTreeFind(root->right,x);
        return right;//不返回left的情况下，说明left肯定是空值。   那就无所谓right是什么值了

}





//二叉树的层序遍历             ----层序遍历需要调用队列的功能才能实现
void LevelOrder(BTNode* root)//传入的是一个根节点
{
    assert(root);
    //层序遍历是根节点出去的同时，将子节点进行保存
    Queue q1;//队列的形式请记住,队列里面存放着两个指针，一个指向队头，一个指向队尾
    QueueInit(&q1);
    QueuePush(&q1,root);//将根节点插入队列，并且根节点出队的时候，顺便将子树插入队列，直至，遇见空则不插入
    while(q1.front)//此处的队列存放的是二叉树节点的地址
    {
        printf("%c ",(q1.front)->data->data);//输出队头节点保存的元素      第一个data是队列存放的队头节点所保存的元素（也就是二叉树节点的地址），再次->data就是指向
        if(q1.front->data->left!=NULL)//根节点的左子树不为空就插入
        {
            QueuePush(&q1,q1.front->data->left);
        }
        if(q1.front->data->right!=NULL)//根节点的右子树不为空就插入
        {
            QueuePush(&q1,q1.front->data->right);
        }
        Queuepop(&q1);//插入完之后就删除根节点
    }
    QueueDestory(&q1);
}





//判断是否为完全二叉树
int BinaaryTreeComplete(BTNode* root)
{
    assert(root);//空节点肯定不是二叉树
    Queue q1;//创建一个队列
    QueueInit(&q1);
    QueuePush(&q1,root);//root是存放在q1.front.data中
    while(q1.front->data)//存放的二叉树的节点不是空才会进行循环
    {
        QueuePush(&q1,q1.front->data->left);
        QueuePush(&q1,q1.front->data->right);
        Queuepop(&q1);
    }

    //在这里是因为全部遍历完还是遍历到了非完全二叉树的NULL谁也不知道，所以此处要判断
   while(q1.front->data==NULL && q1.front!=q1.tail)
   {
       Queuepop(&q1);
   }
   if(q1.front->data!=NULL)
   {
       QueueDestory(&q1);
       return 0;
   }
   else
   {
       QueueDestory(&q1);
       return 1;
   }
}