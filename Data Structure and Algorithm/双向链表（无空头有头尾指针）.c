#include <stdio.h>
#include <malloc.h>

//! malloc̫��ռ䣬CPUռ���ʻ�����ߣ����³��򿨶٣�����Ҫ��ʱ�ͷſռ�
//! ˫��������Ե�������������ǣ�Ҫ��ɾ�ڵ�ʱ�����ҵ�Ŀ��ڵ��ǰһ���ڵ�,����˭����˭

typedef struct Node
{
    int Data;
    struct Node * pPre;
    struct Node * pNext; 
}LLNode;

LLNode * pHead_A = NULL, * pEnd_A = NULL;
int NodeCount_A = 0;

LLNode * pHead_B = NULL, * pEnd_B = NULL;
int NodeCount_B = 0;

//��
void AddToHead(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Data);//* ͷ���
void AddToEnd(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Data);//* β���
void AddNodeByIndex(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Index, int Count, int Data);//* ��ָ���±�����ָ�������Ľڵ�
void AddNodeBeforeData(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int PosData, int AddData);//* ��Ŀ��ڵ��ǰ�����ӽڵ�

//ɾ
void DeleteNode(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, LLNode * pNode);//* ɾ��ָ����ַ�ڵ�
void DeleteNodeByIndex(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Index);//* ͨ���±�ɾ���ڵ�
void DeleteNodeByData(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Data);//* ͨ������ɾ���ڵ�

//��
void ChangeNodeByIndex(LLNode * pHead, int NodeCount, int Index, int Data);//* �޸�ָ���±�����
void ChangeNodeByData(LLNode * pHead, int PosData, int ChangeData);//* �޸�ָ�����ݽڵ������

//��
LLNode * FindNodeByIndex(LLNode * pHead, int NodeCount, int Index);//* ͨ���±���ҽڵ�
LLNode * FindNodeByData(LLNode * pHead, int Data);//* ͨ�����ݲ��ҽڵ�

//�ϲ���������
void MergeLList(LLNode ** pHead_A, LLNode ** pEnd_A, int * NodeCount_A, LLNode ** pHead_B, LLNode ** pEnd_B,  int * NodeCount_B);//* �ϲ�����B��ȷ�����򣨴�С����,��������A�𣬿�������������

void PrintLList(LLNode * pHead, int NodeCount);//* ��ӡ����
void PrintLList_Z(LLNode * pEnd, int NodeCount);//* �����ӡ����

void FreeLList(LLNode ** pHead, LLNode ** pEnd, int * NodeCount);//* �ͷ�����

int main(void)
{
    //* ��
    AddToEnd(&pHead_A, &pEnd_A, &NodeCount_A, 2);
    AddToEnd(&pHead_A, &pEnd_A, &NodeCount_A, 3);
    AddToEnd(&pHead_A, &pEnd_A, &NodeCount_A, 4);
    AddToHead(&pHead_A, &pEnd_A, &NodeCount_A, 1);
    AddNodeByIndex(&pHead_A, &pEnd_A, &NodeCount_A, 0, 4, 500);
    AddNodeByIndex(&pHead_A, &pEnd_A, &NodeCount_A, NodeCount_A, 1, 600);
    AddNodeByIndex(&pHead_A, &pEnd_A, &NodeCount_A, 5, 3, 700);
    AddNodeBeforeData(&pHead_A, &pEnd_A, &NodeCount_A, 700, 0);
    PrintLList(pHead_A, NodeCount_A);

    //* ɾ
    DeleteNode(&pHead_A, &pEnd_A, &NodeCount_A, pHead_A);
    DeleteNodeByIndex(&pHead_A, &pEnd_A, &NodeCount_A, 0);
    DeleteNodeByData(&pHead_A, &pEnd_A, &NodeCount_A, 700);
    PrintLList(pHead_A, NodeCount_A);

    //* ��
    ChangeNodeByIndex(pHead_A, NodeCount_A, 0, 1);
    ChangeNodeByData(pHead_A, 0, 999);
    PrintLList(pHead_A, NodeCount_A);

    //* ��
    LLNode * pTemp = FindNodeByIndex(pHead_A, NodeCount_A, 3);
    printf("�±�3��������%d\n", pTemp->Data);
    pTemp = FindNodeByData(pHead_A, 3);
    printf("ָ�����ݽڵ����һ���ڵ��������%d\n", pTemp->pNext->Data);

    FreeLList(&pHead_A, &pEnd_A, &NodeCount_A);
    //PrintLList_Z();

    //* A����
    AddToEnd(&pHead_A, &pEnd_A, &NodeCount_A, 20);
    AddToEnd(&pHead_A, &pEnd_A, &NodeCount_A, 0);
    AddToEnd(&pHead_A, &pEnd_A, &NodeCount_A, 17);
    AddToEnd(&pHead_A, &pEnd_A, &NodeCount_A, 5);
    AddToEnd(&pHead_A, &pEnd_A, &NodeCount_A, 9);
    PrintLList(pHead_A, NodeCount_A);
    //* B����
    AddToEnd(&pHead_B, &pEnd_B, &NodeCount_B, 1);
    AddToEnd(&pHead_B, &pEnd_B, &NodeCount_B, 5);
    AddToEnd(&pHead_B, &pEnd_B, &NodeCount_B, 10);
    AddToEnd(&pHead_B, &pEnd_B, &NodeCount_B, 15);
    PrintLList(pHead_B, NodeCount_B);
    //* �ϲ�����
    MergeLList(&pHead_A, &pEnd_A, &NodeCount_A, &pHead_B, &pEnd_B, &NodeCount_B);
    PrintLList(pHead_B, NodeCount_B);
    PrintLList(pHead_A, NodeCount_A);

    FreeLList(&pHead_A, &pEnd_A, &NodeCount_A);
    FreeLList(&pHead_B, &pEnd_B, &NodeCount_B);
    
    return 0;
}

void MergeLList(LLNode ** pHead_A, LLNode ** pEnd_A, int * NodeCount_A, LLNode ** pHead_B, LLNode ** pEnd_B,  int * NodeCount_B)
{
    if(pHead_A == NULL || pHead_B == NULL || *pHead_A == NULL || *NodeCount_A < 1)
        return;
    LLNode * pCurrent = *pHead_A;
    while(pCurrent != NULL)
    {
        LLNode * pInsertPos = NULL;
        LLNode * pInner = *pHead_B;
        LLNode * pPrevInner = NULL;
        //! ���Ҳ���λ��
        while(pInner != NULL && pCurrent->Data > pInner->Data)
        {
            pPrevInner = pInner;
            pInner = pInner->pNext;
        }
        //! ���pInnerΪNULL��˵��pCurrent������Ӧ�ò��뵽����B��β��
        //! ���pPrevInnerΪNULL��˵��pCurrent������Ӧ�ò��뵽����B��ͷ��
        //! ���򣬲��뵽pPrevInner��pInner֮��
        if(pInner == NULL)//ֵ���β���
        {
            AddToEnd(pHead_B, pEnd_B, NodeCount_B, pCurrent->Data);
        }
        else if(pPrevInner == NULL)//ֵ��С��ͷ���
        {
            AddToHead(pHead_B, pEnd_B, NodeCount_B, pCurrent->Data);
        }
        else//��������С�м�
        {
            // �����½ڵ�
            LLNode *pNewNode = (LLNode *)malloc(sizeof(LLNode));
            if(pNewNode == NULL)
            {
                // ���������Ӵ�������룬�����¼������־
                return;
            }
            pNewNode->Data = pCurrent->Data;
            pNewNode->pPre = pPrevInner;
            pNewNode->pNext = pInner;
            pPrevInner->pNext = pNewNode;
            pInner->pPre = pNewNode;
            (*NodeCount_B)++;
        }
        pCurrent = pCurrent->pNext;
    }
    FreeLList(pHead_A, pEnd_A, NodeCount_A);
}

void AddToHead(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Data)//* ͷ���
{
    //�����Ϸ��Լ��
    if(pHead == NULL || pEnd == NULL)
        return;
    //����ռ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode == NULL)return;
    //�ڵ��Ա��ֵ
    pNewNode->Data = Data;
    pNewNode->pPre = NULL;
    pNewNode->pNext = NULL;
    //����
    if(*pHead == NULL)//������
        *pEnd = pNewNode;//�½ڵ㼴��ͷ��Ҳ��β
    else
    {
        pNewNode->pNext = *pHead;
        (*pHead)->pPre = pNewNode;
    }
    *pHead = pNewNode;
    (*NodeCount) ++;
}

void AddToEnd(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Data)//* β���
{
    //�����Ϸ��Լ��
    if(pHead == NULL || pEnd == NULL)
        return;
    //����ռ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode == NULL)return;
    //�ڵ��Ա��ֵ
    pNewNode->Data = Data;
    pNewNode->pPre = NULL;
    pNewNode->pNext = NULL;
    //����
    if(*pHead == NULL)//������
        *pHead = pNewNode;//�½ڵ㼴��ͷ��Ҳ��β
    else
    {
        (*pEnd)->pNext = pNewNode;//�޸ľ�β�ڵ��pNext
        pNewNode->pPre = *pEnd;//��¼ǰ�ڵ��ַ
    }
    (*pEnd) = pNewNode;//β��ӱ�����βָ��ָ��β�ڵ�
    //�ڵ�������һ
    (*NodeCount) ++;//! ����++�����ȼ���*�ߣ�����Ҫ������
}

void AddNodeByIndex(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Index, int Count, int Data)//* ��ָ���±�����ָ�������Ľڵ�
{
    if(pHead == NULL || pEnd == NULL || Index < 0 || Index > NodeCount_A || Count < 1)
        return;
    if(Index == 0)
        for(int i = 0; i < Count; i++)
            AddToHead(pHead, pEnd, NodeCount, Data);
    else if(Index == NodeCount_A)
        for(int i = 0; i < Count; i++)
            AddToEnd(pHead, pEnd, NodeCount, Data);
    else
    {
        //Ѱ��ָ���±�ڵ�
        LLNode * pCurrent = *pHead;
        for(int i = 0; i < Index; i++)
            pCurrent = pCurrent->pNext;
        for(int i = 0; i < Count; i++)
        {
            //����ռ�
            LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
            if(pNewNode == NULL)return;
            //�ڵ��Ա��ֵ
            pNewNode->Data = Data;
            pNewNode->pPre = NULL;
            pNewNode->pNext = NULL;
            //����
            //�½ڵ��ǰ�ڵ�����
            pCurrent->pPre->pNext = pNewNode;
            pNewNode->pPre = pCurrent->pPre;
            //�½ڵ�ͺ�ڵ�����
            pNewNode->pNext = pCurrent;
            pCurrent->pPre = pNewNode;
        }
        (*NodeCount) += Count;
    } 
}

void AddNodeBeforeData(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int PosData, int AddData)//* ��Ŀ��ڵ��ǰ�����ӽڵ�
{
    //�����Ϸ��Լ��
    if(pHead == NULL || pEnd == NULL || NodeCount == 0)
        return;
    //ͷ���
    if((*pHead)->Data == PosData)
    {
        AddToHead(pHead, pEnd, NodeCount, AddData);
        return;
    }
    //����Ŀ��ڵ�
    LLNode * pCurrent = *pHead;
    while(pCurrent != NULL)
    {
        if(pCurrent->Data == PosData)
        {
            //����ռ�
            LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
            if(pNewNode == NULL)return;
            //�ڵ��Ա��ֵ
            pNewNode->Data = AddData;
            pNewNode->pPre = NULL;
            pNewNode->pNext = NULL;
            //����
            //�½ڵ��ǰ�ڵ�����
            pCurrent->pPre->pNext = pNewNode;
            pNewNode->pPre = pCurrent->pPre;
            //�½ڵ�ͺ�ڵ�����
            pNewNode->pNext = pCurrent;
            pCurrent->pPre = pNewNode; 
            //�ڵ�������һ
            (*NodeCount) ++;
        }
        pCurrent = pCurrent->pNext;
    }
}

void DeleteNode(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, LLNode * pNode)//* ɾ��ָ����ַ�ڵ�
{
    //�����Ϸ��Լ��
    if(pHead == NULL || pEnd == NULL ||(*pHead) == NULL || (*pEnd) == NULL || (*NodeCount) == 0)
        return;
    if((*NodeCount) != 1)
    {
        //�޸�ָ��
        if(pNode == (*pHead))//ͷɾ��
        {
            pNode->pNext->pPre = NULL;
            *pHead = pNode->pNext;
        }
        else if(pNode == (*pEnd))//βɾ��
        {
            pNode->pPre->pNext = NULL;
            *pEnd = pNode->pPre;
        }
        else 
        {
            pNode->pPre->pNext = pNode->pNext;
            pNode->pNext->pPre = pNode->pPre;
        }
    }
    else
        *pHead = *pEnd = NULL;
    free(pNode);
    (*NodeCount) --;
}

void DeleteNodeByIndex(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Index)//* ͨ���±�ɾ���ڵ�
{
    //û�в�����⣬��Ϊ���ҽڵ㺯���Ѿ�����
    //���ҽڵ�
    LLNode * pTemp = FindNodeByIndex(*pHead, *NodeCount, Index);
    if(pTemp == NULL)return;
    DeleteNode(pHead, pEnd, NodeCount, pTemp);
}

void DeleteNodeByData(LLNode ** pHead, LLNode ** pEnd, int * NodeCount, int Data)//* ͨ������ɾ���ڵ�
{
    // while(1)
    // {
    //     LLNode * pTemp = FindNodeByData(Data);
    //     if(pTemp == NULL)return;
    //     DeleteNode(pTemp);
    // }
    LLNode * pTemp; 
    while ((pTemp = FindNodeByData(*pHead, Data)) != NULL)
        DeleteNode(pHead, pEnd, NodeCount, pTemp);
}

void ChangeNodeByIndex(LLNode * pHead, int NodeCount, int Index, int Data)//* �޸�ָ���±�����
{
    LLNode * pTemp = FindNodeByIndex(pHead, NodeCount, Index);
    if(pTemp == NULL)return;
    pTemp->Data = Data;
}

void ChangeNodeByData(LLNode * pHead, int PosData, int ChangeData)//* �޸�ָ�����ݽڵ������
{
    //�����Ϸ��Լ��
    if(pHead == NULL)
        return;
    LLNode * pCurrent = pHead;
    while(pCurrent != NULL)
    {
        if(pCurrent->Data == PosData)
            pCurrent->Data = ChangeData;
        pCurrent = pCurrent->pNext;
    }
}

LLNode * FindNodeByIndex(LLNode * pHead, int NodeCount, int Index)//* ͨ���±���ҽڵ�
{
    //�����Ϸ��Լ��
    if(pHead == NULL || Index < 0 || Index + 1 > NodeCount)
        return NULL;
    LLNode * pCurrent = pHead;
    for(int i = 0; i < Index; i++)
        pCurrent = pCurrent->pNext;
    return pCurrent;
}

LLNode * FindNodeByData(LLNode * pHead, int Data)//* ͨ�����ݲ��ҽڵ�
{
    //�����Ϸ��Լ��
    if(pHead == NULL)
        return NULL;
    LLNode * pCurrent = pHead;
    while(pCurrent != NULL)
    {
        if(pCurrent->Data == Data)
            return pCurrent;
        pCurrent = pCurrent->pNext;
    }
    return NULL;
}

void FreeLList(LLNode ** pHead, LLNode ** pEnd, int * NodeCount)//�ͷ�����
{
    if(*pHead == NULL)return;//�����������ͷţ���������ִ��
    LLNode * pCurrent = *pHead;
    while(pCurrent != NULL)
    {
        LLNode * pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pCurrent);
    }
    *pHead = NULL;
    *pEnd = NULL;
    *NodeCount = 0;
}

void PrintLList(LLNode * pHead, int NodeCount)//��ӡ����
{
    if(pHead == NULL)return;//�����������ͷţ���������ִ��
    LLNode * pCurrent = pHead;
    printf("������%d���ڵ�\n", NodeCount);
    while (pCurrent != NULL)
    {
        printf("%d ", pCurrent->Data);
        pCurrent = pCurrent->pNext;
    }
    putchar('\n');
}

void PrintLList_Z(LLNode * pEnd, int NodeCount)//�����ӡ����
{
    if(pEnd == NULL)return;
    LLNode * pCurrent = pEnd;
    printf("�����ӡ��������%d���ڵ�\n", NodeCount);
    while (pCurrent != NULL)
    {
        printf("%d ", pCurrent->Data);
        pCurrent = pCurrent->pPre;
    }
    putchar('\n');
}
