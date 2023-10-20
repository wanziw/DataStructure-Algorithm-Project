#include <stdlib.h>
#include <stdio.h>
typedef char DataType;
#define MAXSIZE 200

using namespace std;
typedef struct BiTnode
{
    DataType data;
    struct BiTnode *lchild, *rchild;
} * BiTree, BitNode;
int CreateBiTree(BiTree *T, DataType *str);
void DispBTNode(BiTree T);
int CreateBiTree(BiTree *T, DataType *str)
{
    BiTree S[MAXSIZE], p = NULL;
    int top = 0, k = 0, j = 0;
    char ch;
    *T = NULL;
    ch = str[j];
    while (ch != '@')
    {
        switch (ch)
        {
        case '(':
            S[top++] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;

        default:
            p = (BiTree)malloc(sizeof(BitNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (*T == NULL)
            {
                *T = p;
            }
            else
            {
                switch (k)
                {
                case 1:
                    S[top - 1]->lchild = p;
                    break;
                case 2:
                    S[top - 1]->rchild = p;
                    break;
                }
            }
            break;
        }
        ch = str[++j];
    }

    return 1;
}

void main()
{
    int n, len = 0;
    char ch, str[MAXSIZE];
    BiTree T;
    cout << "请输入广义表，以‘@’结束：" << endl;

    while ((ch = getchar()) != '\n')
    {
        str[len++] = ch;
    }

    n = CreateBiTree(&T, str);
    if (n == 1)
    {
        cout << "创建成功！" << endl;
    }
    else
    {
        cout << "创建失败！" << endl;
    }

    DispBTNode(T);

    system("pause");
}

void DispBTNode(BiTree T)
{
    BitNode *qu[MAXSIZE];
    BitNode *p;
    int front, rear, n;
    n = 0;
    front = rear = 0;
    qu[rear++] = NULL;
    p = T;
    if (p != NULL)
    {
        qu[rear++] = p;
    }
    do
    {
        p = qu[front++];
        if (p == NULL)
        {
            qu[rear++] = NULL;
            n++;
            printf("\n");
        }
        else
        {
            cout << "第" << n << "层：" << p->data << endl;
            if (p->lchild != NULL)
            {
                qu[rear++] = p->lchild;
            }
            if (p->rchild != NULL)
            {
                qu[rear++] = p->rchild;
            }
        }
    } while (front != rear - 1);
}