#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 10

typedef  int  ElemType;
typedef  int  Status;
typedef  struct {
	ElemType *base;
	int front;
	int rear;
}Queue; 

void InitQueue(Queue *Q)
{/*构造一个空队列*/
    Q->base=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	assert(Q->base!=NULL);
	Q->front=Q->rear=0;
}

int EmptyQueue(Queue *Q)
{/* 判断队列是否为空，若空返回1，否则返回0*/
	if(Q->rear==Q->front)
		return 1;
	else 
		return 0;
}

int QueueLength(Queue *Q)
{/*返回队列长度*/
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}


Status EnQueue(Queue*Q,ElemType item)
{/*元素item进队*/
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		return ERROR;
	}
	Q->base[Q->rear]=item;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return OK;
}

ElemType  OutQueue(Queue *Q)
{/*队头元素出队列，并返回其值*/
	ElemType e;
	if(Q->rear==Q->front)
	{
		return ERROR;
	}
	e= Q->base[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return e;
}

ElemType PeekQueue(Queue *Q)
{/*返回对头元素*/
	if(Q->rear==Q->front)
	{
		return ERROR;
	}
	return Q->base[Q->front];
}

void ClearQueue(Queue *Q)
{/*清空队列*/
	Q->front=Q->rear=0;
}

void DestoryQueue(Queue *Q)
{/*销毁队伍*/
	if(Q->base)
		free(Q->base);
	Q->base=0;
	Q->front=Q->rear=0;
}





      
   