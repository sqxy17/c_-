#include"BinaaryTree.h"
#include"Queue.h"
int main(void)
{
    BTNode* root=CreatBinaaryTree();
    printf("TrueAndFalse:%d ", BinaaryTreeComplete(root));
    printf("\n");

}


