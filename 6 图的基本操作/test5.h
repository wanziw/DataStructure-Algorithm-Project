#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InitBiTree(BiTree *T)
{
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = NULL;
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
}

void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == ' ')
		T = NULL;
	else
		*T = (BiTree)malloc(sizeof(BiTNode *));
	if (!T)
		exit(-1);
	(*T)->data = ch;
	CreateBiTree(&(*T)->lchild);
	CreateBiTree(&(*T)->rchild);
}

int EmptyBiTree(BiTree T)
{
	if (T == NULL)
		return 1;
	else
		return 0;
}

int DepthBiTree(BiTree T)
{
	int dep, depl, depr;
	if (!T)
		dep = 0;
	else
	{
		depl = DepthBiTree(T->lchild);
		depr = DepthBiTree(T->rchild);
		if (depl >= depr)
			dep = 1 + depl;
		else
			dep = 1 + depr;
	}
	return dep;
}

/*���Ҷ�������ֵΪx�Ľ�㣬�����ҳɹ�����1�����򷵻�0*/
int FindBiTree(BiTree T, TElemType x)
{
	int i = 0, j = 0;
	if (T->data == x)
	{
		return 1;
	}
	else
	{
		if (T->lchild)
			i = FindBiTree(T->lchild, x);

		if (T->rchild)
			j = FindBiTree(T->rchild, x);
		if (i == 1 || j == 1)
			return 1;
		else
			return 0;
	}
	return 0;
}

void PreOrder(BiTree T)
{
	if (T)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T)
{
	if (T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->data);
	}
}

void LevelOrder(BiTree T)
{
	BiTree q;
	Queue *Q = (Queue *)malloc(sizeof(Queue));
	InitQueue(Q);
	if (T != NULL)
	{
		EnQueue(Q, T->data);
		while (!EmptyQueue(Q))
		{
			q->data = char(Q->base[Q->front + 1]);
			printf("%c
			\t", q->data);
			OutQueue(Q);
			if (q->lchild != NULL)
				EnQueue(Q, int(q->lchild));
			if (q->rchild != NULL)
				EnQueue(Q, int(q->rchild));
		}
	}
}

void PrintBiTree(BiTree T)
{
}

/*�ݹ���ն�����*/
void ClearBiTree(BiTree *T)
{
	if (T)
	{
		if ((*T)->lchild)
			ClearBiTree(&(*T)->lchild);
		if ((*T)->rchild)
			ClearBiTree(&(*T)->rchild);
		free(T);
		T = NULL;
	}
}
