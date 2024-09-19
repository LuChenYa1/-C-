#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//! ˫��ѭ�������������������̬��
//! ��������������ͷ�ı�ͷβ�ڵ�ָ�򣬼��ɱ�ɲ�ѭ������
//! �߼��ϲ�ʹ��pPreָ�룬���ɱ�ɵ�������

typedef struct Node
{
    int Data;
    struct Node * pPre;
    struct Node * pNext;
}LLNode;

LLNode * CreateNode(int Data);//* ����һ���ڵ�

void AddToEnd(LLNode * stHead, int * NodeCount, int Data);//* β���
void AddToHead(LLNode * stHead, int * NodeCount, int Data);//* ͷ���
void AddNodeByIndex(LLNode * stHead, int * NodeCount, int Number, int Index, int Data);//* ��ָ���±�λ�����ӽڵ�
void AddNodeBeforeData(LLNode * stHead, int * NodeCount, int DesData, int AddData);//* ��ָ������ǰ�����ӽڵ�

void DeleteNodeByIndex(LLNode * stHead, int * NodeCount, int Index);//* ͨ���±�ɾ���ڵ�
void DeleteNodeBySomeIndex(LLNode * stHead, int * NodeCount, int IndexMin, int IndexMax);//* ͨ���±귶Χɾ���ڵ�
void DeleteNodeByData(LLNode * stHead, int * NodeCount, int Data);//* ɾ��ָ�����ݽڵ�

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
    AddToEnd(&stHead, &NodeCount, 5);
    AddToEnd(&stHead, &NodeCount, 6);
    PrintLList(&stHead, NodeCount);

    //������6������������
    LLNode * pTemp = FindNodeByIndex(&stHead, NodeCount, NodeCount - 1); 
    pTemp->pNext = FindNodeByIndex(&stHead, NodeCount, 2); 
    printf("%d\n", pTemp->Data);
    printf("%d\n", pTemp->pNext->Data);

    //��ɲ�ѭ������
    stHead.pPre->pNext = NULL;
    stHead.pPre  = NULL;

    // FreeLList(&stHead, &NodeCount);
    // PrintLList(&stHead, NodeCount);

    return 0;
}

void CircleJudgment(LLNode * stHead, int NodeCount)
{
    //�����Ϸ��Լ��
    if(stHead == NULL || NodeCount <= 0)
        return;
    LLNode * pFast = stHead, * pSlow = stHead;
   
}

LLNode * CreateNode(int Data)//* ����һ���ڵ�
{
    //����ռ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode == NULL)return NULL;
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

void AddNodeByIndex(LLNode * stHead, int * NodeCount, int Index, int Number, int Data)//* ��ָ���±�λ�����ӽڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || NodeCount == NULL || Index > *NodeCount || Index < 0)
        return;
    //���Һ����޷����β�ڵ��һλ�Ϳ�����������赥���ж�
    if(*NodeCount == 0 || Index == (*NodeCount))
        for(int i = 0; i < Number; i++)
            AddToEnd(stHead, NodeCount, Data);
    else
    {
        //��λ��
        LLNode * pDes = FindNodeByIndex(stHead, *NodeCount, Index);
        if(pDes == NULL)return;
        for(int i = 0; i < Number; i++)
        {
            //�����ڵ�
            LLNode * pNewNode = CreateNode(Data);
            //���� 
            //ǰ�ڵ���½ڵ�����
            pDes->pPre->pNext = pNewNode;
            pNewNode->pPre = pDes->pPre;
            //�½ڵ�ͺ�ڵ�����
            pNewNode->pNext = pDes;
            pDes->pPre = pNewNode;
            //�ڵ�������һ
            (*NodeCount)++;            
        }
    }
}

void AddNodeBeforeData(LLNode * stHead, int * NodeCount, int DesData, int AddData)//* ��ָ������ǰ�����ӽڵ�
{
    //��������
    LLNode * pDes = FindNodeByData(stHead, *NodeCount, DesData);
    if(pDes == NULL)return;
    //�����ڵ�
    LLNode * pNewNode = CreateNode(AddData);
    //���� 
    //ǰ�ڵ���½ڵ�����
    pDes->pPre->pNext = pNewNode;
    pNewNode->pPre = pDes->pPre;
    //�½ڵ�ͺ�ڵ�����
    pNewNode->pNext = pDes;
    pDes->pPre = pNewNode;
    //�ڵ�������һ
    (*NodeCount)++;
}

void DeleteNodeByIndex(LLNode * stHead, int * NodeCount, int Index)//* ͨ���±�ɾ���ڵ�
{
    //��λ��
    LLNode * pDes = FindNodeByIndex(stHead, *NodeCount, Index);
    if(pDes == NULL)return;
    //�޸�ָ��
    pDes->pPre->pNext = pDes->pNext;
    pDes->pNext->pPre = pDes->pPre;
    //�ͷſռ�
    free(pDes);
    //������һ
    (*NodeCount)--;
}

void DeleteNodeBySomeIndex(LLNode * stHead, int * NodeCount, int IndexMin, int IndexMax)//* ͨ���±귶Χɾ���ڵ�
{
    for(int i = IndexMin; i <= IndexMax; i++)
        DeleteNodeByIndex(stHead, NodeCount, IndexMin);
}

void DeleteNodeByData(LLNode * stHead, int * NodeCount, int Data)//* ɾ��ָ�����ݽڵ�
{
    while(1)
    {
        //��������
        LLNode * pDes = FindNodeByData(stHead, *NodeCount, Data);
        if(pDes == NULL)return;
        //�޸�ָ��
        pDes->pPre->pNext = pDes->pNext;
        pDes->pNext->pPre = pDes->pPre;
        //�ͷſռ�
        free(pDes); 
        //������һ
        (*NodeCount)--;
    }
}

LLNode * FindNodeByIndex(LLNode * stHead, int NodeCount, int Index)//* ͨ���±���ҽڵ�
{
    //�����Ϸ��Լ��
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
