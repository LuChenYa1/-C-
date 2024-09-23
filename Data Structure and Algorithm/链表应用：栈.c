#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

//! ջ�ǲ���������Ҫ���Ƚ����������ȳ����ö�̬������������������ݽṹʵ�ֶ�����
//! ֻҪ��֤�����ɾ������ͬһ�˽��У�����ջ


typedef struct Node
{
    int Data;
    struct Node * pPre;
    struct Node * pNext;
}LLNode;

//* ջ������һ��ջ��ͷ
LLNode * Stack(void);
//* �ж�ջ�Ƿ�Ϊ��
bool isEmpty(LLNode * pStack);
//* ѹջ����ӽڵ�(β���)
void Push(LLNode * pStack, int Data);
//* ��ȡջ���ڵ�
LLNode * Top(LLNode * pStack);
//* ɾ��ջ���ڵ�(β�ڵ�)
void Pop(LLNode * pStack);
//* �ͷ�ջ
void FreeStack(LLNode ** stack);

int main(void)
{
    LLNode * pStack = Stack();
    Push(pStack, 1);
    Push(pStack, 2);
    Push(pStack, 3);
    Push(pStack, 4);
    printf("%d\n", pStack->pPre->Data);

    LLNode * pEnd = Top(pStack);
    printf("%d\n", pEnd->Data);

    Pop(pStack);
    printf("%d\n", pStack->pPre->Data);

    FreeStack(&pStack);
    return 0;
}

LLNode * Stack(void)
{
    //����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode == NULL)
        return NULL;
    //�ڵ��Ա��ֵ
    pNewNode->Data = -1;
    pNewNode->pPre = pNewNode;
    pNewNode->pNext = pNewNode;
    //���ؽڵ�
    return pNewNode;
}

bool isEmpty(LLNode * pStack)
{
    if(pStack == NULL || pStack->pNext == pStack)
        return true;
    return false;
}

void Push(LLNode * pStack, int Data)
{
    //�������
    if(pStack == NULL)
        return;
    //����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode == NULL)
        return;
    //�ڵ��Ա��ֵ
    pNewNode->Data = Data;
    pNewNode->pPre = NULL;
    pNewNode->pNext = NULL;
    //����
    //����
    pNewNode->pPre = pStack->pPre;
    pNewNode->pNext = pStack;
    //���
    pStack->pPre->pNext = pNewNode;
    pStack->pPre = pNewNode;
}

LLNode * Top(LLNode * pStack)
{
    if(isEmpty(pStack))
        return NULL;
    return pStack->pPre;
}

void Pop(LLNode * pStack)
{
    if(isEmpty(pStack))
        return;
    //��������
    LLNode * pEnd = pStack->pPre;
    pEnd->pPre->pNext = pStack;
    pStack->pPre = pEnd->pPre;
    //�ͷ�β�ڵ�
    free(pEnd);
}

void FreeStack(LLNode ** pStack)
{
    //�����Ϸ��Լ��
    if(pStack == NULL || *pStack == NULL)
        return;
    LLNode * pCurrent = *pStack;
    do//! �������ôû�뵽������ִ�����ж�
    {
        LLNode * pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pTemp);
    }while(pCurrent != *pStack);
    *pStack = NULL;
}
