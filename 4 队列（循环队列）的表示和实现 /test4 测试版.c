#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DataType int
#define MAXSIZE 100

#include "LQueue.h"


int main()
{    
    //测试部分
    LoopQueue *Q;

    Q = InitLQueue();
   
    //定义一个选择变量
    int choice;

    //插入元素
    DataType e;

    //出队返回值
    DataType back;
    do
    {
        printf("===========循环队列操作==========\n");
        printf("1.元素入队\n");
        printf("2.元素出队\n");
        printf("3.销毁队列\n");
        printf("4.打印队列\n");
        printf("0.退出\n");
        printf("=====================\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            
            printf("请输入循环队列元素（输入-1结束）:");
            scanf("%d", &e);
            while (e != -1)
            {
                LQueueInsert(Q, e);
                scanf("%d", &e);
            }
            break;
        case 2:

            back = LQueueDelete(Q);
            back ? printf("------------\n 元素: %d 出队，还剩%d个元素\n", back, LQueueGetLenth(Q)) : printf("------------\n队列为空，无法出队！\n");
            free(&back); //回收内存，防止内存泄露
            break;
        case 3:
            LQueueDestroy(Q) ? printf("------------\n队列销毁成功！\n") : printf("------------\n队列销毁失败！\n");
            break;
        case 4:
            LQueuePrint(Q);
            break;
        case 0:
            printf("\n-->> 退出\n");
            exit(0);
            break;
        default:
            break;
        }
    } while (choice);


    return 0;
}
