#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

//! ջ��������ʵ��

//! ջ�ǲ���������Ҫ���Ƚ����������ȳ�
//! ֻҪ��֤�����ɾ������ͬһ�˽��У�����ջ
//! ����дջ����ͷ��ӣ���Ϊ���һ��������������Ҫȫ������Ų��ִ��Ч�ʵͣ����Բ���β���

//! ѹջ��ջ�Ĺ��̺͵ݹ�Ĺ���һ��������ִ�еĺ���������ѹջ��������������ջ��

#define NUM 10

struct Node
{
    int Arr[NUM];
    int Index;//ʵ�ʱ�������
};

//* ջ������һ��ջ��ͷ
struct Node * Stack(void);
//* �ж�ջ�Ƿ�Ϊ��
bool isEmpty(struct Node * pStack);
//* ѹջ����ӽڵ�(β���)
void Push(struct Node * pStack, int Data);
//* ��ȡջ���ڵ�
int Top(struct Node * pStack);
//* ɾ��ջ���ڵ�(β�ڵ�)
void Pop(struct Node * pStack);
//* �ͷ�ջ
void FreeStack(struct Node ** stack);

int main(void)
{
    struct Node * pStack = Stack();
    if(pStack == NULL)
        return 1;   
    int Array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Push(pStack, Array[0]);
    Push(pStack, Array[1]);
    Push(pStack, Array[2]);
    Push(pStack, Array[3]);
    Push(pStack, Array[4]);
    Push(pStack, Array[5]);
    Push(pStack, Array[6]);
    Push(pStack, Array[7]);
    Push(pStack, Array[8]);
    Push(pStack, Array[9]);
    Push(pStack, 11);//���������޷�����

    int a = pStack->Arr[Top(pStack)];
    printf("%d\n", a);

    Pop(pStack);
    a = pStack->Arr[Top(pStack)];
    printf("%d\n", a);

    FreeStack(&pStack);
    return 0;
}

struct Node * Stack(void)
{
    struct Node * pArr = (struct Node *)malloc(sizeof(struct Node));
    if(pArr == NULL)
        return NULL;
    pArr->Index = 0;
    return pArr;
}

bool isEmpty(struct Node * pStack)
{
    if(pStack == NULL || pStack->Index == 0)
        return true;
    return false; 
}

void Push(struct Node * pStack, int Data)
{
    if(pStack == NULL || pStack->Index >= NUM)//�����й̶�������ע�ⲻҪԽ��
        return;
    pStack->Arr[pStack->Index] = Data;
    pStack->Index ++;
}

int Top(struct Node * pStack)
{
    if(isEmpty(pStack))
        return 0;
    return pStack->Index - 1;//����β�����±�
}

void Pop(struct Node * pStack)
{
    if(isEmpty(pStack))
        return;
    pStack->Index --;
}

void FreeStack(struct Node ** pStack)
{
    if(pStack == NULL || *pStack == NULL || (*pStack)->Index == 0)
        return;
    free(*pStack);
    *pStack = NULL;
}
