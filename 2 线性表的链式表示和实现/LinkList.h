typedef enum
{
    false,
    true
} bool;

typedef struct node //typedef 用于取别名
{
    ElemType data;
    struct node *next;
} * PNODE, NODE; //PNODE 就是 struct node *，NODE就是struct node

//初始化单链表
PNODE InitList()
{
    PNODE temp;                         //定义一个结构体指针
    temp = (PNODE)malloc(sizeof(NODE)); //定义一个头节点
    temp->next = NULL;                  //头结点不储存数据，头结点的指针域暂时为空
    return temp;
}

//清除单链表
void ListClear(PNODE head)
{
    PNODE p = head, temp;
    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
}

//求单链表长度
int ListLength(PNODE head)
{
    int i = 0;
    PNODE p = head->next;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

//判断单链表是否为空表
bool ListIsEmpty(PNODE head)
{
    return !ListLength(head);
}

//取单链表第pos位置上的元素
ElemType ListGetData(PNODE head, int pos)
{
    PNODE p = head;

    //pos超过长度时报错
    if (ListLength(head) < pos)
    {
        printf("pos超过最大长度\n");
        return p->next->data;
    }

    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }

    return p->data;
}

//打印单链表(遍历)
void ListPrint(PNODE head)
{
    printf("链表：");

    PNODE p = head->next; //定义p指向首元节点（不是头结点）
    while (p != NULL)     //直到p==NULL，遍历完了才结束
    {
        printf("%d->", p->data); //打印节点里的数据
        p = p->next;             //指针移动指向下一个节点
    }
    printf("NULL\n");
}

//向单链表插入一个元素
bool ListInsertList(PNODE head, ElemType item, int pos)
{

    if (ListLength(head) + 1 < pos)
    {
        printf("pos超过最大长度+1\n");
        return false;
    }

    //开辟一小块内存用于存放数据
    PNODE temp, p = head;
    temp = (PNODE)malloc(sizeof(NODE));
    temp->data = item;

    //找到第(pos-1)个结点,让p指向它
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }

    //插入
    temp->next = p->next;
    p->next = temp;

    return true;
}

bool ListDeleteList(PNODE head, int pos)
{
    PNODE p = head;

    if (ListLength(head) + 1 < pos)
    {
        printf("pos超过最大长度+1\n");
        return false;
    }

    //找到第(pos-1)个结点,让p指向它
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }

    //让pos-1个结点直接指向pos+1个结点
    p->next = p->next->next;

    free(p->next);
    return true;
}

void ListMergeList(PNODE La, PNODE Lb, PNODE Lc)
{
    //让pa指向La最后一个结点
    PNODE pa = La->next;
    PNODE pb = Lb->next;
    PNODE pc = Lc;

    if (pa->data < pb->data)
    {
        pc->next = pa;
        pa = pa->next;
        pc = pc->next;
    }
    else
    {
        pc->next = pb;
        pb = pb->next;
        pc = pc->next;
    }

    //pa pb至少有一个存在就能继续
    while (pa!=NULL || pb!=NULL)
    {
        //只有一个存在
        if ((pa!= NULL && pb== NULL)||(pa== NULL && pb!= NULL) )
        {
            //如果pa存在
            if (pa!= NULL)
            {
                pc->next = pa;
                pa = pa->next;
                pc = pc->next;
            }
            else
            {
                pc->next = pb;
                pb = pb->next;
                pc = pc->next;
            }
        }
        else
        {
            if (pa->data < pb->data)
            {
                pc->next = pa;
                pa = pa->next;
                pc = pc->next;
            }
            else
            {
                pc->next = pb;
                pb = pb->next;
                pc = pc->next;
            }
        }

        ListClear(La);
        ListClear(Lb);
    }
}


void ListMergeListPlus(PNODE La, PNODE Lb, PNODE Lc)
{
    //让pa指向La最后一个结点
    PNODE pa = La->next;
    PNODE pb = Lb->next;
    PNODE pc = Lc;

    //pa pb两个都存在就能继续
    while (pa && pb)
    {
        if (pa->data < pb->data)
        {
            pc->next = pa;
            pa = pa->next;
            pc = pc->next;
        }
        else
        {
            pc->next = pb;
            pb = pb->next;
            pc = pc->next;
        }   
    }

    if(pa)
    {
        pc->next = pa;
    }
    if(pb)
    {
        pc->next = pb;
    }

}