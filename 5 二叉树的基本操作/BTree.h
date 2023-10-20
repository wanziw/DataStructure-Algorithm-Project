#ifndef __BTREE_H__
#define __BTREE_H__

#include "test5_LQueue.h"

// typedef enum
// {
//     false,
//     true
// } bool;
// 二叉树的存储结构
// typedef struct BTreeNode {
//     DataType data;
//     struct BTreeNode *left;
//     struct BTreeNode *right;
// }BTreeNode;

//初始化一个二叉树
BTreeNode *InitBTree()
{
    BTreeNode *BT = (BTreeNode *)malloc(sizeof(BTreeNode));
    BT->left = NULL;
    BT->right = NULL;

    return BT;
}

//根据字符串a所给出的广义表表示的二叉树建立二叉链表存储结构
//利用栈
//传入的BT，作为指向头结点的指针，不需要初始化init，只需要是结构体指针
BTreeNode *BTreeCreate(BTreeNode *BT, char *a)
{
    //指针数组存储双亲结点
    BTreeNode *S[MAXSIZE];
    //用于生成新结点
    BTreeNode *p = NULL;

    BT = NULL;

    int top = 0, k = 0, j = 0;
    char ch;

    ch = a[j];
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            S[top++] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;

        default:
            p = InitBTree();
            p->data = ch;
            //如果是头结点
            if (BT == NULL)
            {
                BT = p;
            }
            else
            {
                //不是头结点
                if (k == 1)
                {
                    S[top - 1]->left = p;
                }
                else
                {
                    S[top - 1]->right = p;
                }
                break;
            }
        }
        ch = a[++j];
    }
    return BT;
}

//检查二叉树BT是否为空，空返回1，否则返回0
bool BTreeIsEmpty(BTreeNode *BT)
{
    if (BT&&BT->left&&BT->right)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//求二叉树BT的深度并返回该值
int BTreeDepth(BTreeNode *BT)
{
    if (BT == NULL)
    {
        return 0;
    }
    else
    {
        int MaxLeft = BTreeDepth(BT->left);
        int MaxRight = BTreeDepth(BT->right);
        int MaxDepth = MaxLeft < MaxRight ? MaxRight : MaxLeft;
        return 1 + MaxDepth; //双亲结点加上最深子树的深度
    }
}

//先序遍历
void BTreePreOrderTraverse(BTreeNode *BT)
{
    if (BT)
    {
        printf("%-5c", BT->data);         //输出双亲结点
        BTreePreOrderTraverse(BT->left);  //遍历左孩子
        BTreePreOrderTraverse(BT->right); //遍历右孩子
    }
}

//中序遍历
void BTreeInOrderTraverse(BTreeNode *BT)
{
    if (BT)
    {
        BTreeInOrderTraverse(BT->left);  //遍历左孩子
        printf("%-5c", BT->data);        //输出双亲结点
        BTreeInOrderTraverse(BT->right); //遍历右孩子
    }
}

//后序遍历
void BTreePostOrderTraverse(BTreeNode *BT)
{
    if (BT)
    {
        BTreePostOrderTraverse(BT->left);  //遍历左孩子
        BTreePostOrderTraverse(BT->right); //遍历右孩子
        printf("%-5c", BT->data);          //输出双亲结点
    }
}

// 层序遍历
// 运用队列来实现非递归，让root节点入队列，然后出队列（将要出队列的节点记为front），打印节点，判断front的两个节点是否为空
// ，若不为空则入队列，重复上述操作直到队列为空。
void BTreeLevelOrderTraverse(BTreeNode *root)
{
    LoopQueue *q;
    q = InitLQueue();

    if (root)
        LQueueInsert(q, root); //？不知道指针可以不可以作为int变量

    while (LQueueGetLenth(q) != 0)
    {
        BTreeNode *front = LQueuePeek(q);
        printf("%-5c", front->data);
        LQueueDelete(q);
        if (front->left)
        {
            LQueueInsert(q, front->left);
        }
        if (front->right)
        {
            LQueueInsert(q, front->right);
        }
    }
    printf("\n");
}

//查找二叉树BT中值为x的结点，若查找成功返回该结点指针，否则返回NULL
//用递归，
BTreeNode *BTreeFind(BTreeNode *BT, DataType x)
{
    //找一个值为x的节点
    if (!BT)
        return NULL;
    if (BT->data == x)
    {
        return BT;
    }
    else
    {
        //难点就跟输出不一样，往左找了之后，没找到不代表没有，可能在右边
        //所以要再用一个指针接收，不改变传入的BT
        BTreeNode *temp;
        //先看下左边找到了没有
        temp = BTreeFind(BT->left, x);
        //没有找到那就看看右边
        if (!temp)
        {
            return BTreeFind(BT->right, x);
        }
        //这个跟输出不一样，得有个指针来接收。
        //temp找到了就返回temp
        return temp;
    }
    return NULL;
}

//销毁二叉树
//递归，只能后序遍历消除，从低到高
void BTreeClear(BTreeNode *BT)
{
    if (BT == NULL)
        return;
    if (BT->left != NULL)
    {
        BTreeClear(BT->left); //往左递归
        BT->left = NULL;      //将左孩子域置空
    }
    if (BT->right != NULL)
    {
        BTreeClear(BT->right); //往右递归
        BT->right = NULL;      //将右孩子域置空
    }
    if (BT != NULL)
    {
        free(BT);
        BT = NULL;
    }
}

//将二叉树中的所有结点的左右子树进行交换
int BTreeExchange(BTreeNode *BT)
{
	BTreeNode *temp;
	if (BT == NULL)									//空树
		return 0;
	else
	{
		temp = BT->left;                
		BT->left= BT->right;		
		BT->right= temp;		

		BTreeExchange(BT->left);			//交换左子树
		BTreeExchange(BT->right);			//交换右子树
	}
	return 1;
}

//统计二叉树中的所有叶子结点数
int BTreeCountLeaves(BTreeNode *BT)
{
	if (BT == NULL)									 //空树
		return 0;
	else if (BT->left ==NULL && BT->right == NULL)		//非空树,但是无孩子
		return 1;													
	else
		return BTreeCountLeaves(BT->left) + BTreeCountLeaves(BT->right);	//有左或右孩子
}

//统计所有结点个数
int BTreeCountNode(BTreeNode *BT)
{
	if (BT == NULL)
		return 0;
	else
		return BTreeCountNode(BT->left) + BTreeCountNode(BT->right) + 1;         //返回第一个结点加上左子树和右子树的结点
}




//复制一棵二叉树，并返回复制得到的二叉树根结点指针

// 用给定的二叉树的根节点root来构造新的二叉树的方法为：
// 首先创建新的结点NewBTree,然后根据root结点来构造NewBTree结点
// ,最后分别用root的左右子树来构造NewBTree的左右子树。
// 根据这个思路可以实现二叉树的复制，使用递归方式实现的代码如下：

BTreeNode *BTreeCopy(BTreeNode *BT)
{
    if (BT==NULL) return NULL;
    BTreeNode *NewBT;
    NewBT = InitBTree();

    NewBT->data = BT->data;
    NewBT->left = BTreeCopy(BT->left);
    NewBT->right = BTreeCopy(BT->right);
    return NewBT;
}



#endif