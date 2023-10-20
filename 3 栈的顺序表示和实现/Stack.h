typedef enum
{
    false,
    true
} bool;

typedef struct Stack
{                        // 栈结构体
    DataType data[maxn]; // 作为栈元素的存储方式，数据类型为DataType
    int top;             // top即栈顶指针，data[top-1]表示栈顶元素，top==0代表空栈
    int base;            // base即栈底指针
} Stack;                 //构建一个名字是stack类型的结构体，包含三个部分



//初始化一个栈
Stack *InitStack()
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    if (p == NULL)
        return NULL;         //分配失败返回空指针
    p->base = p->top = 0; //栈底等于栈顶 即建立一个空栈
    return p;
}

//入栈
bool StackPushStack(Stack *p, DataType dt)
{
    if (p->top - p->base == maxn)
        return false;
    p->data[p->top] = dt; // dt存入栈中
    p->top++;             // 栈顶指针+1
    return true;
}

//出栈
bool StackPopStack(Stack *p)
{
    if (p->base == p->top)
        return false;
    --p->top;
    return true;
}

//清空栈
void StackClear(Stack *p)
{
    p->top = 0; // 栈顶指针指向栈底
}

// 只读接口，获取栈顶元素，获取栈大小，栈的判空, 打印栈
DataType StackGetTop(Stack *p)
{
    return p->data[p->top - 1]; //  数组中栈元素从 0 开始计数，所以实际获取元素时，下标为 栈顶元素下标 减一；
}
int StackGetSize(Stack *p)
{
    return p->top; //  因为只有在入栈的时候，栈顶指针才会加一，所以它 正好代表了 栈元素个数；
}
bool StackIsEmpty(Stack *p)
{
    return !StackGetSize(p); //判断是否为空栈
}
void PrintStack(Stack *p)
{
    if (StackIsEmpty(p))
    {
        printf("栈为空\n");
    }
    else
    {
        printf("从栈顶开始:\t");
        for (int i = 1; i <= StackGetSize(p); i++)
        {
            printf("%d\t", p->data[p->top - i]);
        }
    }
}