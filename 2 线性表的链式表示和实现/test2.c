#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

#include "LinkList.h"

int main()
{
    PNODE heada= InitList(),headb= InitList(),headc = InitList();//接受InitList（）的返回值，即head指向了一个头结点

    ElemType x;
    int i = 1;

    printf("输入a：");
    scanf("%d", &x);
    while (x != -1)
    {
        if (ListInsertList(heada, x, i) == 0)
        {
            return 0;
        }
        i++;
        scanf("%d", &x);
    }

    i = 1;  //重置i
    printf("输入b：");
    scanf("%d", &x);
    while (x != -1)
    {
        if (ListInsertList(headb, x, i) == 0)
        {
            return 0;
        }
        i++;
        scanf("%d", &x);
    }
    
    ListMergeListPlus(heada,headb,headc);
    ListPrint(headc);

    // ListPrint(head);
    // printf("%d\n", ListLength(head));

    // printf("第三个元素是：%d\n", ListGetData(head, 3));
    // ListDeleteList(head,3);

    // ListPrint(head);
    // printf("%d\n", ListLength(head));

    return 0;
}


