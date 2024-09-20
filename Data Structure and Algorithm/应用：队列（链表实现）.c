#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

//! ���У��Ƚ��ȳ���������
//! �ö���ϢԴ������Ϣ�ܱ�������eg.Windows����Ϣ������� 

//! ��ӵ�һ�˽ж�β�������ݵ�һ�˽ж�ͷ����ӽ���ӣ������ݽг���

typedef struct Node
{
    int Data;
    struct Node * pPre;
    struct Node * pNext;
}LLNode;

//* ���У�����һ��ջ��ͷ
LLNode * Queue(void);
//* �ж϶����Ƿ�Ϊ��
bool isEmpty(LLNode * pQueue);
//* ��ӣ���ӽڵ�(ͷ���)
void Push(LLNode * pQueue, int Data);
//* ���ӣ�ɾ���ڵ㣨βɾ����
void Pop(LLNode * pQueue);
//* ��ȡ��ͷ
LLNode * Front(LLNode * pQueue);
//* ��ȡ��β
LLNode * Back(LLNode * pQueue);
//* �ͷ�ջ
void FreeQueue(LLNode ** Queue);

int main(void)
{
    LLNode * pQueue = Queue();
    Push(pQueue, 1);
    Push(pQueue, 2);
    Push(pQueue, 3);
    Push(pQueue, 4);

    LLNode * pHead = Front(pQueue);
    printf("%d\n", pHead->Data);
    LLNode * pEnd = Back(pQueue);
    printf("%d\n", pEnd->Data);

    Pop(pQueue);
    printf("%d\n", pQueue->pPre->Data);

    FreeQueue(&pQueue);
    return 0;
}

LLNode * Queue(void)
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

bool isEmpty(LLNode * pQueue)
{
    if(pQueue == NULL || pQueue->pNext == pQueue)
        return true;
    return false;
}

LLNode * Front(LLNode * pQueue)
{
    if(isEmpty(pQueue))
        return NULL; 
    return pQueue->pPre;
}

LLNode * Back(LLNode * pQueue)
{
    if(isEmpty(pQueue))
        return NULL;
    return pQueue->pNext;
}

void Push(LLNode * pQueue, int Data)
{
    //�������
    if(pQueue == NULL)
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
    pNewNode->pPre = pQueue;
    pNewNode->pNext = pQueue->pNext;
    //���
    pQueue->pNext->pPre = pNewNode;
    pQueue->pNext = pNewNode;
}

void Pop(LLNode * pQueue)
{
    if(isEmpty(pQueue))
        return;
    //��������
    LLNode * pEnd = pQueue->pPre;
    pEnd->pPre->pNext = pQueue;
    pQueue->pPre = pEnd->pPre;
    //�ͷ�β�ڵ�
    free(pEnd);
}

void FreeQueue(LLNode ** pQueue)
{
    //�����Ϸ��Լ��
    if(pQueue == NULL || *pQueue == NULL)
        return;
    LLNode * pCurrent = *pQueue;
    do//! �������ôû�뵽������ִ�����ж�
    {
        LLNode * pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pTemp);
    }while(pCurrent != *pQueue);
    *pQueue = NULL;
}