#include <stdio.h>
#include <malloc.h>

//! malloc̫��ռ䣬CPUռ���ʻ�����ߣ����³��򿨶٣�����Ҫ��ʱ�ͷſռ�
//! ˫��������Ե�������������ǣ�Ҫ��ɾ�ڵ�ʱ�����ҵ�Ŀ��ڵ��ǰһ���ڵ�

typedef struct Node
{
    int Data;
    struct Node * pPre;
    struct Node * pNext; 
}LLNode;

LLNode * pHead = NULL, * pEnd = NULL;
int NodeCount = 0;

void AddToHead(int Data);//* ͷ���
void AddToEnd(int Data);//* β���
void AddNodeByIndex(int Index, int Count, int Data);//* ��ָ���±�����ָ�������Ľڵ�
void AddNodeBeforeData(int PosData, int AddData);//* ��Ŀ��ڵ��ǰ�����ӽڵ�


void PrintLList(void);//* ��ӡ����
void PrintLList_Z(void);//* �����ӡ����

void FreeLList(void);//* �ͷ�����

int main(void)
{
    AddToEnd(1);
    AddToEnd(2);
    AddToEnd(3);
    AddToHead(4);
    AddNodeByIndex(0, 2, 500);
    AddNodeByIndex(NodeCount, 1, 600);
    AddNodeByIndex(5, 3, 700);
    PrintLList();
    AddNodeBeforeData(700, 0);

    PrintLList();
    //PrintLList_Z();

    FreeLList();
    return 0;
}

void AddToHead(int Data)//* ͷ���
{
    //����ռ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode == NULL)return;
    //�ڵ��Ա��ֵ
    pNewNode->Data = Data;
    pNewNode->pPre = NULL;
    pNewNode->pNext = NULL;
    //����
    if(pHead == NULL)//������
        pEnd = pNewNode;//�½ڵ㼴��ͷ��Ҳ��β
    else
    {
        pNewNode->pNext = pHead;
        pHead->pPre = pNewNode;
    }
    pHead = pNewNode;
    NodeCount ++;
}

void AddToEnd(int Data)//* β���
{
    //����ռ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode == NULL)return;
    //�ڵ��Ա��ֵ
    pNewNode->Data = Data;
    pNewNode->pPre = NULL;
    pNewNode->pNext = NULL;
    //����
    if(pHead == NULL)//������
        pHead = pNewNode;//�½ڵ㼴��ͷ��Ҳ��β
    else
    {
        pEnd->pNext = pNewNode;//�޸ľ�β�ڵ��pNext
        pNewNode->pPre = pEnd;//��¼ǰ�ڵ��ַ
    }
    pEnd = pNewNode;//β��ӱ�����βָ��ָ��β�ڵ�
    //�ڵ�������һ
    NodeCount ++;
}

void AddNodeByIndex(int Index, int Count, int Data)//* ��ָ���±�����ָ�������Ľڵ�
{
    if(Index < 0 || Index > NodeCount || Count < 1)
        return;
    if(Index == 0)
        for(int i = 0; i < Count; i++)
            AddToHead(Data);
    else if(Index == NodeCount)
        for(int i = 0; i < Count; i++)
            AddToEnd(Data);
    else
    {
        //Ѱ��ָ���±�ڵ�
        LLNode * pCurrent = pHead;
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
        NodeCount += Count;
    } 
}

void AddNodeBeforeData(int PosData, int AddData)//* ��Ŀ��ڵ��ǰ�����ӽڵ�
{
    //��������
    if(pHead == NULL)return;
    //ͷ���
    if(pHead->Data == PosData)
    {
        AddToHead(AddData);
        return;
    }
    //����Ŀ��ڵ�
    LLNode * pCurrent = pHead;
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
            NodeCount ++;
        }
        pCurrent = pCurrent->pNext;
    }
}


void FreeLList(void)//�ͷ�����
{
    if(pHead == NULL)return;//�����������ͷţ���������ִ��
    LLNode * pCurrent = pHead;
    while(pCurrent != NULL)
    {
        LLNode * pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pCurrent);
    }
    pHead = NULL;
    pEnd = NULL;
    NodeCount = 0;
}

void PrintLList(void)//��ӡ����
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

void PrintLList_Z(void)//�����ӡ����
{
    if(pHead == NULL)return;
    LLNode * pCurrent = pEnd;
    printf("�����ӡ��������%d���ڵ�\n", NodeCount);
    while (pCurrent != NULL)
    {
        printf("%d ", pCurrent->Data);
        pCurrent = pCurrent->pPre;
    }
    putchar('\n');
}

