
typedef enum
{
    false,
    true
} bool;

//二叉树的存储结构
typedef struct BTreeNode {
    DataType data;
    struct BTreeNode *left;   
    struct BTreeNode *right;  
}BTreeNode;

//循环队列结构
typedef struct LoopQueue
{
    BTreeNode *data[MAXSIZE];
    int front; //队头索引，指向队列第一个数据所在位置
    int rear;  //队尾索引，指向队列最后一个数据后一个位置
} LoopQueue;





LoopQueue *InitLQueue()
{
    LoopQueue *Q = (LoopQueue *)malloc(sizeof(LoopQueue));
    Q->front = Q->rear = 0;
    return Q;
}

//返回长度
int LQueueGetLenth(LoopQueue *Q)
{
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

//插入元素
bool LQueueInsert(LoopQueue *Q, BTreeNode *dt)
{
    //这里牺牲掉了一个储存位置，用rear+1来和队头索引相比较以判断是否为满，
    //是为了和队列判空条件相区分

    //判断队列是否 满，如果已满，返回false
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return false;

    Q->data[Q->rear] = dt;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return true;
}

//元素出队，返回其值
BTreeNode *LQueueDelete(LoopQueue *Q)
{
    //判断队列是否为空
    if (Q->rear == Q->front)
        return 0;

    BTreeNode *dt = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return dt;
}

//销毁队列,也是由于该循环队列基于数组，不需要分配内存
//只需重置队头和队尾索引即可
int LQueueDestroy(LoopQueue *Q)
{
    Q->front = Q->rear = 0;
    return true;
}


//取队头元素
BTreeNode *LQueuePeek(LoopQueue *Q)
{
    if (Q->rear == Q->front)
        printf("队列为空\n");
    else
        return Q->data[Q->front];
    return NULL;
}





