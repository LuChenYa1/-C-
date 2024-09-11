#include <stdio.h>
#include <string.h>
#include <malloc.h>

//! û��βָ�룬�п�ͷ
//! ��ͷ�����ݱ������ڴ洢�ڵ�����, ���̶���������ռ�
//! �ӽڵ������

typedef struct Node
{
    int Data;
    struct Node *pNext;
}LLNode;

void AddToHead(LLNode * stHead, int Data);//* ͷ���
void AddToEnd(LLNode * stHead, int Data);//* β���
void AddBehandData(LLNode * stHead, int PosData, int DesData);//* ��Ŀ�����ݺ������һ���ڵ�

LLNode * FindNodeByData(LLNode * stHead, int Data);//* ͨ�����ݲ��ҽڵ�

void FreeList(LLNode * stHead);//* �ͷ�����

void PrintList(LLNode stHead);//* ��ӡ����

int main(void)
{
    //����һ����ͷ
    LLNode stHead = {0, NULL};

    AddToHead(&stHead, 1);
    AddToEnd(&stHead, 2);
    AddToHead(&stHead, 3);
    AddBehandData(&stHead, 2, 4);

    if(FindNodeByData(&stHead, 4) == NULL)
        printf("û�ҵ�\n");
    else
        printf("�ҵ���\n");

    PrintList(stHead);
    
    FreeList(&stHead);
    
    return 0;
}

void AddToHead(LLNode * stHead, int Data)//ͷ���
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data < 0)
        return;
    //�����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode != NULL)
    {
        //�ڵ��Ա��ֵ
        pNewNode->Data = Data;
        pNewNode->pNext = NULL;
        //����
        LLNode * pTemp = stHead->pNext;
        stHead->pNext = pNewNode;
        pNewNode->pNext = pTemp;
    }
    //��������һ
    stHead->Data ++;
}

void AddToEnd(LLNode * stHead, int Data)//β���
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data < 0)
        return;
    //�����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode != NULL)
    {
        //�ڵ��Ա��ֵ
        pNewNode->Data = Data;
        pNewNode->pNext = NULL;
        //����
        LLNode * pCurrent = stHead;
        while(pCurrent->pNext != NULL)
            pCurrent = pCurrent->pNext;
        pCurrent->pNext = pNewNode;
    }
    //��������һ
    stHead->Data ++;
}

void AddBehandData(LLNode * stHead, int PosData, int DesData)
{
    if(stHead == NULL || stHead->Data < 0)
        return;
    LLNode * pPosData = FindNodeByData(stHead, PosData);
    //�����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode != NULL)
    {
        //�ڵ��Ա��ֵ
        pNewNode->Data = DesData;
        pNewNode->pNext = NULL;
        //����
        pNewNode->pNext = pPosData->pNext;
        pPosData->pNext = pNewNode;
    }
    //��������һ
    stHead->Data ++;
}

LLNode * FindNodeByData(LLNode * stHead, int Data)
{
    if(stHead == NULL || stHead->Data < 0)
        return NULL;
    LLNode * pCurrent = stHead->pNext;//! ע���һ���ڵ��ǿ�ͷ��ֻ���<�ڵ�����>
    while(pCurrent != NULL)
    {
        if(pCurrent->Data == Data)
            return pCurrent;
        pCurrent = pCurrent->pNext;
    }
    return NULL;
}

void FreeList(LLNode * stHead)//�ͷ�����
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data < 0)
        return;
    LLNode * pCurrent = stHead->pNext;
    while(pCurrent != NULL)//����Ҫ�ͷŵĽڵ�
    {
        LLNode * pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pTemp);
    }
    stHead->pNext = NULL;
    stHead->Data = 0;
}

void PrintList(LLNode stHead)//��ӡ����
{
    LLNode * pCurrent = stHead.pNext;
    printf("������%d���ڵ�\n", stHead.Data);
    while(pCurrent != NULL)
    {
        printf("%d ", pCurrent->Data);
        pCurrent = pCurrent->pNext;
    }
    putchar('\n');
}
