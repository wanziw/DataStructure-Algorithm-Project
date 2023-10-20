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
{/*����һ���ն���*/
    Q->base=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	assert(Q->base!=NULL);
	Q->front=Q->rear=0;
}

int EmptyQueue(Queue *Q)
{/* �ж϶����Ƿ�Ϊ�գ����շ���1�����򷵻�0*/
	if(Q->rear==Q->front)
		return 1;
	else 
		return 0;
}

int QueueLength(Queue *Q)
{/*���ض��г���*/
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}


Status EnQueue(Queue*Q,ElemType item)
{/*Ԫ��item����*/
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		return ERROR;
	}
	Q->base[Q->rear]=item;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return OK;
}

ElemType  OutQueue(Queue *Q)
{/*��ͷԪ�س����У���������ֵ*/
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
{/*���ض�ͷԪ��*/
	if(Q->rear==Q->front)
	{
		return ERROR;
	}
	return Q->base[Q->front];
}

void ClearQueue(Queue *Q)
{/*��ն���*/
	Q->front=Q->rear=0;
}

void DestoryQueue(Queue *Q)
{/*���ٶ���*/
	if(Q->base)
		free(Q->base);
	Q->base=0;
	Q->front=Q->rear=0;
}





      
   