#include <stdio.h>
#include <stdlib.h>

#define DataType int
#define MAXSIZE 1005

#include "BTree.h"

int main()
{
    char str[20];
    BTreeNode *BT;
    //BT = InitBTree();  //不需要

    //(A(B(C,D),E(,F)))
    printf("请输入广义表：");
    scanf("%s", str);
    BT = BTreeCreate(BT, str);

    //四种遍历测试
    printf("\n-----------遍历测试-----------\n");
    printf("先序遍历结果:");
    BTreePreOrderTraverse(BT);
    printf("\n");

    printf("中序遍历结果:");
    BTreeInOrderTraverse(BT);
    printf("\n");

    printf("后序遍历结果:");
    BTreePostOrderTraverse(BT);
    printf("\n");

    printf("层序遍历结果:");
    BTreeLevelOrderTraverse(BT);
    printf("\n");

    //深度测试
    printf("\n-----------深度测试-----------\n");
    printf("树的深度是%d\n", BTreeDepth(BT));

    //查找测试
    printf("\n-----------查找测试-----------\n");
    getchar(); //吸收前面一个回车
    char *m1, *m2, *m3;
    char n;
    printf("请输入查找值:");
    scanf("%c", &n);

    if (BTreeFind(BT, n))
        m1 = "查找成功";
    else
        m1 = "查找失败";
    printf("%s\n", m1);


    //交换子树测试
    printf("\n-------交换左右子树测试-------\n");
    BTreeLevelOrderTraverse(BT);
    BTreeExchange(BT);
    BTreeLevelOrderTraverse(BT);

    //求结点测试
    printf("\n---------结点个数测试---------\n");
    printf("叶子结点有%d个\n",BTreeCountLeaves(BT));
    printf("总结点有%d个\n",BTreeCountNode(BT));
    
    //复制测试
    printf("\n-----------复制测试-----------\n");
    printf("复制前:\n");
    BTreeLevelOrderTraverse(BT);
    BTreeNode *NewBT = BTreeCopy(BT);
    printf("复制后:\n");
    BTreeLevelOrderTraverse(NewBT);

    //清空测试
    printf("\n-----------清空测试-----------\n");

    printf("清空前:\n");
    //printf("%d\n", BT->left->data);
    m2 = BTreeIsEmpty(BT)?"树为空":"树不为空";
    printf("%s\n", m2);

    BTreeClear(BT);
    printf("清空后:\n");

    //printf("%p\n", BT->left);
    m3 = BTreeIsEmpty(BT) ? "树为空" : "树不为空";
    printf("%s\n", m3);


    return 0;
}

// 关于清除
// malloc 申请的内存空间被释放后, 内部存有的值依旧保留. 
// 如果这片内存没有被其他 malloc 获取并存值(操作系统和其他应用也有可能访存这片"无主"的内存), 其内含的值就不会变化.
// 原则上, 不应该访问已经被 free 的内存, 因为那里已经不归你管了, 其存储的值不可预测.
// 因为BT是头指针，是二叉树第一个结点的地址。清空函数不会改变它依然是地址的事实，
// 经过测试，BT存在,BT->data存在，BT->left/right是NULL。
// 所以判断是否清空不能只看BT是否存在，还要看BT->left/right