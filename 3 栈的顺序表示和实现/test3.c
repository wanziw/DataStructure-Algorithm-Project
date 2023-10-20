#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DataType int // DataType用这个宏定义来统一代表栈中数据的类型，这里将它定义为整型，根据需要可以定义成其它类型，例如浮点型、字符型、结构体 等等；
#define maxn 1005  // 代表我们定义的栈的最大元素个数

#include "Stack.h"


int IsReverse(char *s)
{
    int mid,len;
    Stack *q = InitStack();

    len = strlen(s);
    mid = strlen(s)/2;

    for (int i = 0; i < mid; i++)
    {
        StackPushStack(q, s[i]);
    }

    for (int i = len%2?mid+1:mid ; i < len; i++)
    {
        if (StackGetTop(q) != s[i])
        {
            return 0;
        }       
        StackPopStack(q);
    }

    return 1;
}

int main()
{  
    char s[15]; 
    scanf("%s",s);
    if(IsReverse(s)) printf("是回文字符串\n");
    else printf("不是回文字符串\n");



    // DataType e;
    // Stack *p = InitStack();
    // printf("请输入栈元素（输入-1结束）:");
    // scanf("%d", &e);
    // while (e != -1)
    // {
    //     StackPushStack(p, e);
    //     //printf("请输入栈元素（输入-1结束）:");
    //     scanf("%d", &e);
    // }
    // PrintStack(p);
    // printf("\n");
    // printf("栈的大小为%d\n", StackGetSize(p));
    
    // printf("出栈测试：\n");
    // StackPopStack(p);
    // PrintStack(p);

    // printf("\n");
    // printf("取栈顶测试：\n");
    // e = StackGetTop(p);
    // printf("取出的栈顶为%d\n", e);

    return 0;
}
