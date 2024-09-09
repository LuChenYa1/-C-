#include <stdio.h>
#include <string.h>
#include <malloc.h>

//! û��βָ�룬�п�ͷ

typedef struct Node
{
    char Data[20];
    struct Node *pNext;
}LLNode;

void AddToHead(LLNode * pHead, const char Data[]);
void PrintList(LLNode * pHead);

int main(void)
{
    //����һ����ͷ
    LLNode stHead = {" ", NULL};

    AddToHead(&stHead, "1");
    PrintList(&stHead);

    return 0;
}

void AddToHead(LLNode * pHead, const char Data[])
{
    //�����Ϸ��Լ��
    if(pHead == NULL)
        return;
    //�����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode != NULL)
    {
        //�ڵ��Ա��ֵ
        strcpy(pNewNode->Data, Data);
        //����
        LLNode * pTemp = pHead->pNext;
        pHead->pNext = pNewNode;
        pNewNode->pNext = pTemp;
    }
}

void PrintList(LLNode * pHead)
{
    //�����Ϸ��Լ��
    if(pHead == NULL)
        return;
    LLNode * pCurrent = pHead->pNext;
    while(pCurrent != NULL)
    {
        printf("%s\n", pCurrent->Data);
        pCurrent = pCurrent->pNext;
    }
}
