#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MAXSize 10

#include "SeqList.h"

int main(void)
{
    SeqList *myList = (SeqList *)malloc(sizeof(SeqList));
    int i = 1, x, sum = 0, n, min, max;

    InitList(myList);
    printf("请输入顺序表（输入-1结束）:");
    scanf("%d", &x);
    while (x != -1)
    {
        if (InsertList(myList, x, i) == 0)
        {
            printf("错误!\n");
            return 0;
        }
        i++;
        scanf("%d", &x);
    }

    printList(myList);
    printf("\n");

    //附加部分
    min = 3;
    max = 7;
    if (DeleteElem(myList, min, max) == 0)
    {
        printf("错误");
        return 0;
    }

    printList(myList);
    printf("\n");

    // n = LengthList(myList);
    // for (i = 1; i <= n; i++)
    // {
    //     x = GetList(myList, i);
    //     sum += x;
    // }
    // printf("顺序表的和是%d\n", sum);

    // ClearList(myList);

    return 0;
}