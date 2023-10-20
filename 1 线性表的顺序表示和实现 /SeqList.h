typedef struct List
{
    ElemType *list; //存储空间基地址
    int size;      //当前长度
    int MaxSize;   //当前分配的存储容量
} SeqList;

typedef enum
{
    false,
    true
} bool;


void InitList(SeqList *sq)
{ //初始化线性表
    sq->list = (ElemType *)malloc(MAXSize*sizeof(ElemType));
    sq->size = 0;
    sq->MaxSize = MAXSize;
}

void ClearList(SeqList *sq)
{ //清除线性表
    sq->size = 0;   
}

int LengthList(SeqList *sq)
{ //求线性表长度
    return sq->size;
}

bool InsertList(SeqList *sq, ElemType item, int pos)
{//按给定条件pos向线性表插入一个元素
    int i;
    if (sq->size == MAXSize)
    {
        return false; //  当元素个数已满时，返回0代表插入失败
    }

    for (i = sq->size; i > pos-1; --i)
    {
        sq->list[i] = sq->list[i - 1]; //  从第pos个数开始，每个数往后移动一个位置，注意必须逆序
    }
    sq->list[pos-1] = item; // 第pos个数变成item
    sq->size++;    // 插入一个数，长度加1
    return true;        // 插入成功返回1
}

ElemType GetList(SeqList *sq, int pos)
{ //在线性表L中求序号为pos的元素，该元素作为函数值返回
    return sq->list[pos-1];
}


bool DeleteElem(SeqList *sq, int min, int max)
{
    if(min>=max)
    {
        printf("min>=max error");
        return false;
    }

    for (int i = 0; i < sq->size; i++)
    {
        if (sq->list[i]>=min && sq->list[i]<=max)
        {
            for (int m = i; m < sq->size; m++)  //后面元素全部前进一个，注意是正序
            {
                sq->list[m] = sq->list[m+1];
            }
            sq->size--;
            i--;
        }
            
    }    
    return true;    
}


void printList(SeqList *sq)
{
    for (int i = 0; i < sq->size; i++)
    {
        printf("%d\t", sq->list[i]);
    }
    
}