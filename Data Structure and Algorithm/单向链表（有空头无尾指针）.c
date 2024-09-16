#include <stdio.h>
#include <string.h>
#include <malloc.h>

//! û��βָ�룬�п�ͷ         �п�ͷ �򻯴����߼��������ж�ͷβ�Ĺ���
//! ��ͷ�����ݱ������ڴ洢�ڵ�����, ���̶���������ռ�
//! �ӽڵ��������Ҫע�������仯

//! ʵ�����β�����Ƶ��������Ҫβָ�룬����ÿ��β��Ӷ�Ҫ��ͷ��ѯ��β�ڵ㣬���ִ��Ч��

typedef struct Node
{
    int Data;
    struct Node *pNext;
}LLNode;

//* ��
void AddToHead(LLNode * stHead, int Data);//* ͷ���
void AddToEnd(LLNode * stHead, int Data);//* β���
void AddBehandData(LLNode * stHead, int PosData, int DesData);//* ��Ŀ�����ݺ������ڵ�
void AddNodeByIndex(LLNode * stHead, int Index, int Data);//* ��ָ���±����ڵ�
void AddSomeNodeByIndex(LLNode * stHead, int Index, int Number, int Data);//* ��ָ��λ�ò������ڵ�

//* ɾ
void DeleteNodeByData(LLNode * stHead, int Data);//* ͨ������ɾ���ڵ�
void DeleteNodeByIndex(LLNode * stHead, int Index);//* ͨ���±�ɾ���ڵ�
void DeleteSame(LLNode * stHead);//* ����ȥ��

//* ��
void ChangeNodeByData(LLNode * stHead, int OldData, int NewData);//* ͨ�������޸Ľڵ�
void ChangeAllNodeByData(LLNode * stHead, int OldData, int NewData);//* ͨ�������޸����з���Ҫ��Ľڵ�
void ChangeNodeByIndex(LLNode * stHead, int Index, int Data);//* ͨ���±��޸Ľڵ�

//* ��      ���ҽڵ㲻�漰�޸ģ����Դ���ṹ�屾����ִ��Ч�ʱ��
LLNode * FindNodeByData(LLNode * stHead, int Data);//* ͨ�����ݲ��ҽڵ�
LLNode * FindNodeByIndex(LLNode * stHead, int Index);//* ͨ���±���ҽڵ�


void FreeList(LLNode * stHead);//* �ͷ�����

void PrintList(LLNode stHead);//* ��ӡ����

int main(void)
{
    //����һ����ͷ
    LLNode stHead = {0, NULL};

    //*��
    AddToHead(&stHead, 4);
    AddToEnd(&stHead, 5);
    AddToHead(&stHead, 2);
    AddBehandData(&stHead, 2, 3);
    AddBehandData(&stHead, 2, 2);
    AddNodeByIndex(&stHead, 4, 1);
    AddSomeNodeByIndex(&stHead, 0, 3, 6);
    PrintList(stHead);

    //* ��
    ChangeNodeByData(&stHead, 6, 7);
    ChangeNodeByIndex(&stHead, 7, 8);
    ChangeAllNodeByData(&stHead, 6, 9);
    PrintList(stHead);

    //* ɾ
    DeleteNodeByIndex(&stHead, 7);
    DeleteNodeByData(&stHead, 9);
    PrintList(stHead);
    //ʵ��ȥ��
    AddToEnd(&stHead, 5);
    AddToEnd(&stHead, 4);
    AddToEnd(&stHead, 3);
    AddToEnd(&stHead, 2);
    AddToEnd(&stHead, 2);
    AddToEnd(&stHead, 10);
    PrintList(stHead);   
    DeleteSame(&stHead);
    PrintList(stHead);
    
    //* ��
    if(FindNodeByData(&stHead, 6) == NULL)
        printf("û�ҵ�\n");
    else
        printf("�ҵ���\n");

    FreeList(&stHead);
    
    return 0;
}

void AddToHead(LLNode * stHead, int Data)//* ͷ���
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
        //��������һ
        stHead->Data ++;       
    }
}

void AddToEnd(LLNode * stHead, int Data)//* β���
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
        //��������һ
        stHead->Data ++;       
    }
}

void AddBehandData(LLNode * stHead, int PosData, int DesData)//* ��Ŀ�����ݺ������ڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data < 0)
        return;
    LLNode * pPosData = FindNodeByData(stHead, PosData);
    if(pPosData != NULL)
    {
        AddToHead(pPosData, DesData);
        pPosData->Data --;
        stHead->Data ++;
    }
}

void AddNodeByIndex(LLNode * stHead, int Index, int Data)//* ��ָ���±����ڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data < 0 || Index < 0 || Index > stHead->Data)//* ����β���
        return;
    LLNode * pFormer = FindNodeByIndex(stHead, Index - 1);
    if(pFormer != NULL)
    {
        AddToHead(pFormer, Data);
        pFormer->Data --;
        stHead->Data ++;
    }
}

void AddSomeNodeByIndex(LLNode * stHead, int Index, int Number, int Data)//* ��ָ��λ�ò������ڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data < 0 || Index < 0 || Index > stHead->Data)//* ����β���
        return;
    LLNode * pFormer = FindNodeByIndex(stHead, Index - 1);
    if(pFormer != NULL)
    {
        for(int i = 0; i < Number; i++)
        {
            AddToHead(pFormer, Data);
            pFormer->Data --;
            stHead->Data ++;
        }    
    }
}

void DeleteSame(LLNode * stHead)//* ����ȥ��
{
    if(stHead == NULL || stHead->Data <= 1)
        return;
    //ѭ������
    LLNode * pCurrent = stHead->pNext;//Ҫ���ȶ����ݵĽڵ㣬�����ǿ�ͷ
    while(pCurrent->pNext != NULL)//β�ڵ㲻���ٱȽϣ�û�п��ԱȽϵĽڵ��ˣ���Ҳ����д��pCurrent != NULL
    {
        LLNode * pInner = pCurrent;//ʼ�մ���Ҫ��ɾ���ڵ��ǰһ���ڵ㣬�����ᱻɾ��
        while(pInner->pNext != NULL)
        {
            if(pInner->pNext->Data == pCurrent->Data)
            {
                LLNode * pTemp = pInner->pNext;
                pInner->pNext = pTemp->pNext;
                free(pTemp);
                stHead->Data--;
            }
            else pInner = pInner->pNext;//��ֹ��©�������Ľڵ�
        }
        pCurrent = pCurrent->pNext;
    }
}

void DeleteNodeByData(LLNode * stHead, int Data)//* ͨ������ɾ���ڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data <= 0)
        return;
    LLNode * pCurrent = stHead;
    while(pCurrent->pNext != NULL)//* �ڵ㲻����β�ڵ� 
    {
        if(pCurrent->pNext->Data == Data)//�ڵ����һ���ڵ����Ҫ��
        {
            //�ͷš�����
            LLNode * pTemp = pCurrent->pNext;
            pCurrent->pNext = pTemp->pNext;
            free(pTemp);
            //������һ
            stHead->Data --;
        }
        else
            pCurrent = pCurrent->pNext;
    }
}

void DeleteNodeByIndex(LLNode * stHead, int Index)//* ͨ���±�ɾ���ڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data <= 0 || Index < 0 || Index + 1 > stHead->Data)
        return;
    //ѭ���ҵ�ָ���ڵ��ǰһ���ڵ�
    LLNode * pCurrent = stHead;
    for(int i = 0; i < Index; i++)
        pCurrent = pCurrent->pNext;
    //�ͷŽڵ㣬�������� 
    LLNode * pTemp = pCurrent->pNext;
    pCurrent->pNext = pTemp->pNext;
    free(pTemp);
    //�ڵ�������һ
    stHead->Data --;
}

void ChangeNodeByData(LLNode * stHead, int OldData, int NewData)//* ͨ�������޸Ľڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data <= 0)
        return;
    LLNode * pTemp = FindNodeByData(stHead, OldData);
    if(pTemp == NULL)return;
    pTemp->Data = NewData;
}

void ChangeAllNodeByData(LLNode * stHead, int OldData, int NewData)//* ͨ�������޸����з���Ҫ��Ľڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data <= 0)
        return;
    LLNode * pCurrent = stHead->pNext;//! ע���һ���ڵ��ǿ�ͷ��ֻ���<�ڵ�����>
    while(pCurrent != NULL)
    {
        if(pCurrent->Data == OldData)
            pCurrent->Data = NewData;
        pCurrent = pCurrent->pNext;  
    }
}

void ChangeNodeByIndex(LLNode * stHead, int Index, int Data)//* ͨ���±��޸Ľڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data <= 0 || Index < -1 || Index + 1 > stHead->Data)
        return;
    LLNode * pTemp = FindNodeByIndex(stHead, Index);
    if(pTemp == NULL)return;
    pTemp->Data = Data;
}  

LLNode * FindNodeByData(LLNode * stHead, int Data)//* ͨ�����ݲ��ҽڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data <= 0)
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

LLNode * FindNodeByIndex(LLNode * stHead, int Index)//* ͨ���±���ҽڵ�
{
    //�����Ϸ��Լ��
    if(stHead == NULL || stHead->Data <= 0 || Index < -1 || Index + 1 > stHead->Data)//�����Ѿ����ڵĽڵ�
        return NULL;
    if(Index == -1)
        return stHead;
    LLNode * pCurrent = stHead->pNext;//! ע���һ���ڵ��ǿ�ͷ��ֻ���<�ڵ�����>
    for(int i = 0; i < Index; i++)//! �Ѿ����ýڵ������ų��±����Ŀ����ԣ�����һ�����ҵ��ڵ㣬������forѭ��
        pCurrent = pCurrent->pNext;
    return pCurrent;
}

void FreeList(LLNode * stHead)//* �ͷ�����
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

void PrintList(LLNode stHead)//* ��ӡ����
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
