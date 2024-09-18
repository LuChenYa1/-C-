#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//! ����ʱ������漰��ͷ���������ͷ�������ֹ�޷�����ԭ���Ľڵ� ����ͷ���������������ַ��Կ�ף�
typedef struct Node
{
    int Data;
    struct Node * pPre;
    struct Node * pNext;
}LLNode;

LLNode * CreateNode(int Data);//* ����һ���ڵ�

void AddToEnd(LLNode * stHead, int * NodeCount, int Data);//* β���
void AddToHead(LLNode * stHead, int * NodeCount, int Data);//* ͷ���

LLNode * FindNodeByIndex(LLNode * stHead, int NodeCount, int Index);//* ͨ���±���ҽڵ�
LLNode * FindNodeByData(LLNode * stHead, int NodeCount, int Data);//* ͨ�����ݲ��ҽڵ�

void FreeLList(LLNode * stHead, int * NodeCount);//* �ͷ�����

void PrintLList(LLNode * stHead, int NodeCount);//* ��ӡ����


int main(void)
{
    //��ͷ
    LLNode stHead = {0, &stHead, &stHead};
    int NodeCount = 0;

    AddToEnd(&stHead, &NodeCount, 1);
    AddToEnd(&stHead, &NodeCount, 2);
    AddToEnd(&stHead, &NodeCount, 3);
    AddToEnd(&stHead, &NodeCount, 4);
    AddToHead(&stHead, &NodeCount, 5);

    PrintLList(&stHead, NodeCount);

    LLNode * pTemp = FindNodeByData(&stHead, NodeCount, 6); 
    if(pTemp != NULL)
        printf("�ҵ���\n");
    else
        printf("û�ҵ�\n");

    pTemp = FindNodeByIndex(&stHead, NodeCount, 4); 
    if(pTemp != NULL)
        printf("�ҵ���\n");
    else
        printf("û�ҵ�\n");

    FreeLList(&stHead, &NodeCount);
    PrintLList(&stHead, NodeCount);

    return 0;
}

LLNode * CreateNode(int Data)//* ����һ���ڵ�
{
    //����ռ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    //�ڵ��Ա��ֵ
    pNewNode->Data = Data;
    pNewNode->pPre = NULL;
    pNewNode->pNext = NULL;
    //���ؽڵ�
    return pNewNode;
}

void AddToEnd(LLNode * stHead, int * NodeCount, int Data)//* β���
{
    //�����½ڵ�
    LLNode * pNewNode = CreateNode(Data);
    //����
    //β�ڵ���½ڵ�����
    stHead->pPre->pNext = pNewNode;
    pNewNode->pPre = stHead->pPre;
    //�½ڵ�Ϳ�ͷ����
    pNewNode->pNext = stHead;
    stHead->pPre = pNewNode;
    //�ڵ�������һ
    (*NodeCount)++;
}

void AddToHead(LLNode * stHead, int * NodeCount, int Data)//* ͷ���
{
    //�����½ڵ�
    LLNode * pNewNode = CreateNode(Data);
    //����
    //�½ڵ�ͺ�ڵ�����
    pNewNode->pNext = stHead->pNext;
    stHead->pNext->pPre = pNewNode;
    //��ͷ���½ڵ�����
    stHead->pNext = pNewNode;
    pNewNode->pPre = stHead;
    //�ڵ�������һ
    (*NodeCount)++;
}

LLNode * FindNodeByIndex(LLNode * stHead, int NodeCount, int Index)//* ͨ���±���ҽڵ�
{
    if(stHead == NULL || Index + 1 > NodeCount || Index < 0 || NodeCount <= 0)
        return NULL;
    LLNode * pCurrent = stHead->pNext;
    for(int i = 0; i < Index; i++)
        pCurrent = pCurrent->pNext;
    return pCurrent;
}

LLNode * FindNodeByData(LLNode * stHead, int NodeCount, int Data)//* ͨ�����ݲ��ҽڵ�
{
    if(stHead == NULL || NodeCount <= 0)
        return NULL;
    LLNode * pCurrent = stHead->pNext;
    while(pCurrent != stHead)
    {
        if(pCurrent->Data == Data)
            return pCurrent;
        pCurrent = pCurrent->pNext;
    }
    return NULL;
}

void FreeLList(LLNode * stHead, int * NodeCount)//* �ͷ�����
{
    if(*NodeCount == 0)
        return;
    LLNode * pCurrent = stHead->pNext;
    //�ͷſ�ͷ��������нڵ�
    while(pCurrent != stHead)
    {
        LLNode * pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pTemp);
    }
    //�����ͷ 
    stHead->pNext = stHead;
    stHead->pPre = NULL;
    *NodeCount = 0;
}

void PrintLList(LLNode * stHead, int NodeCount)//* ��ӡ����
{
    printf("����ڵ�������%d \n", NodeCount);
    if(NodeCount == 0) 
        return;
    LLNode * pCurrent = stHead->pNext;
    while(pCurrent != stHead)
    {
        printf("%d ", pCurrent->Data);
        pCurrent = pCurrent->pNext;
    }
    printf("\n");
}
