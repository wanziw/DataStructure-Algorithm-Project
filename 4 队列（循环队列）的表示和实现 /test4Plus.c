#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 100

#include "LQueuePlus.h"

bool partner()
{
    //创建两个队列，分别储存男女两队
    LoopQueue *M = InitLQueue();
    LoopQueue *F = InitLQueue();

    //传入人名
    char str1[5],str2[2];
    printf("请输入跳舞者的姓名和性别(男为M，女为F)（以“# #”结束）:\n");
    scanf("%s%s", str1, str2);
    getchar();
    while (strcmp(str1 ,"#") && strcmp(str2 ,"#"))
    {
        if (!strcmp(str2 ,"M"))
        {
            LQueueInsert(M, str1);
        } 
        else if(!strcmp(str2 ,"F"))
        {
            LQueueInsert(F, str1);
        }
        else
        {
            printf("输入不合法");
            return false;
        }

        //printf("请输入跳舞者的姓名和性别(男为M，女为F)（以“# #”结束）:");
        scanf("%s%s", str1, str2);   
        getchar();     
    }


    //配对
    int num, i;
    printf("配对的舞伴是：\n");
    num = LQueueGetLenth(M)<LQueueGetLenth(F)?LQueueGetLenth(M):LQueueGetLenth(F);
    for (i = 0; i < num; i++)
    {
        printf("%s %s" , LQueueDelete(M), LQueueDelete(F));   
        printf("\n");
    }


    //M剩余或F剩余或都不剩余
    if (LQueueGetLenth(M)) 
    {
        //还有男的
        printf("男队还有人等待下一轮舞曲。\n");
        printf("%s将是下一轮得到舞伴的第一人\n", LQueuePeek(M));
    }
    else if (LQueueGetLenth(F)) 
    {
        //还有女的
        printf("女队还有人等待下一轮舞曲。\n");
        printf("%s将是下一轮得到舞伴的第一人\n", LQueuePeek(F));
    }
    else
        printf("无人剩余，全部匹配成功！\n");
    
    return true;
}


int main()
{
    //舞伴问题
    partner();
    
    return 0;
}
