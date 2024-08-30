#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//! ����Ͷ�̬����һ����ֻ��Ҫһ��ָ������װ��ͷ�ڵ��ַ���ɣ�����Ҫÿ����һ���ڵ㣬����һ���µ�����
//! ��������malloc�����ڴ棬Ȼ��ָ��ָ������ڴ��ַ��������ͷŵ�
//! �����ǣ���̬�������������ڴ�ռ䣬��������ɢ���ڴ�ռ䣬malloc����ռ䷵�صĵ�ַǿת����Ҳ��ͬ������һ���ǽṹ�����ͣ���̬���鰴��ת��
//! �п�ͷ�ڵ㣬��֤ͷ�ڵ�ָ�벻��,���������޿�ͷ��ͷ�ڵ㶼��װ���ݣ�����ֻ���ò����������
//! ��̬��¼βָ�룬�ŵ���ĩβ�����½ڵ�ʱ�����ٴ�ͷ��ѯ�õ�βָ�룬��ߴ���ִ��Ч��
//�����ڸı�ָ����Ҫ����ָ��
//! void�����е�return;���˳���������

//* ����һ��������ڵ�ṹ�� */
typedef struct Node
{
    char Data[10];//! 10�����ü����ַ���������'\0'
    struct Node *pNext;
}LLNode;

void AddToHead(LLNode ** pHead, LLNode ** pEnd, char Data[])//* �ڿ�ͷ�����½ڵ�
{
    //�����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode != NULL)
    {
        //�ڵ��Ա��ֵ
        strcpy(pNewNode->Data, Data);
        pNewNode->pNext = NULL;
        //����
        if(*pHead == NULL)//������
        {
            *pEnd = pNewNode;//�½ڵ㼴��ͷҲ��β
        }
        else 
            pNewNode->pNext = *pHead;//������ͷ�ڵ�;�β�ڵ�
        *pHead = pNewNode;//ͷָ��ָ���½ڵ�
    }
}

void AddToEnd(LLNode ** pHead, LLNode ** pEnd, char Data[])//* ��ĩβ�����½ڵ�
{
    //�����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode != NULL)//��������ռ�ʧ�ܵĿ�����
    {
        //�ڵ��Ա��ֵ
        strcpy(pNewNode->Data, Data);
        pNewNode->pNext = NULL;//����
        //����ȥ
        if(*pHead == NULL)//������
        {
            *pHead = pNewNode;//�½ڵ��Ϊ��һ���ڵ�
        }
        else 
            (*pEnd)->pNext = pNewNode;//���Ӿ�β�ڵ����β�ڵ�
        *pEnd = pNewNode;//βָ��ָ���½ڵ�
    }
}

void AddSomeNodeToEnd(LLNode ** pHead, LLNode ** pEnd, unsigned int Number, char Data[])//* ��β�����Ӷ����ͬ���ݵĽڵ�
{
    for(int i = 0; i < Number; i++)
        AddToEnd(pHead, pEnd, Data);
}

void InsertNodeByIndex(LLNode ** pHead, LLNode ** pEnd, unsigned int Index, char Data[])//* ͨ���±����ڵ�
{
    if(Index < 0)
    {
        printf("�±�С��0���������");
        return;
    }
    else if(Index == 0)
    {
        AddToHead(pHead, pEnd, Data);
    }
    else
    {
        LLNode * pLast = FindNodeByIndex(*pHead, Index - 1);
        if(pLast != NULL)
        {
            //�����ڵ�
            LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
            //�ڵ��Ա��ֵ
            strcpy(pNewNode->Data, Data);
            pNewNode->pNext = NULL;
            //����
            pNewNode->pNext = pLast->pNext;
            pLast->pNext = pNewNode;
        }
        else
            printf("�±�Խ�磬����ǰ�ڵ�ʧ��");
    }
}

void DeleteHead(LLNode ** pHead, LLNode ** pEnd)//* ɾ��ͷ�ڵ�
{
    if(*pHead == NULL)//������
        return;
    if((*pHead)->pNext == NULL)//ֻ��һ���ڵ�
    {
        free(*pHead);
        *pHead = NULL;
        *pEnd = NULL;
    }
    else
    {
        LLNode * pTemp = *pHead;
        *pHead = (*pHead)->pNext;
        free(pTemp);
    }  
}

void DeleteEnd(LLNode ** pHead, LLNode ** pEnd)//* ɾ��β�ڵ�
{
    if(*pHead == NULL)//������
        return;
    if((*pHead)->pNext == NULL)//ֻ��һ���ڵ�
    {
        free(*pHead);
        *pHead = NULL;
        *pEnd = NULL;
    }
    else
    {
        LLNode * pCurrent = *pHead;
        while(pCurrent->pNext->pNext != NULL)
        {
            pCurrent = pCurrent->pNext;
        }
        pCurrent->pNext = NULL;
        free(*pEnd);
        *pEnd = pCurrent;
    }  
}

void DeleteNodeByIndex(LLNode ** pHead, LLNode ** pEnd, unsigned int Index)//* ͨ���±�ɾ���ڵ�
{
    if(Index < 0)
        printf("�±�С���㣬�������");
    else if(Index == 0)
        DeleteHead(pHead, pEnd);
    else
    {
        if((*pHead)->pNext != NULL)
        {
            int i = 0;
            LLNode * pCurrent = *pHead;
            while((*pHead)->pNext != NULL)
            {
                if(Index - 1 == i)
                {
                    LLNode * pTemp = pCurrent->pNext;
                    pCurrent->pNext = pCurrent->pNext->pNext;
                    free(pTemp);
                    return;
                }
                i++;
                pCurrent= pCurrent->pNext;
            }
        }
    }
    return; 
}

void ChangeDataByData(LLNode * pHead, char OldData[], char NewData[])//* �޸�ָ����ֵ�Ľڵ����ֵ��ֻ�޸ĵ�һ���ҵ��Ľڵ㣩
{
    LLNode * pDes = FindNodeByData(pHead, OldData);
    if(pDes != NULL)
        strcpy(pDes->Data, NewData);
    else
        printf("���޴˽ڵ�\n");
}

void ChangeAllDataByData(LLNode * pHead, char OldData[], char NewData[])//* �޸�ָ����ֵ�Ľڵ����ֵ��ȫ������Ҫ��Ľڵ㶼�����޸ģ�
{
    while(pHead != NULL)
    {
        if(strcmp(pHead->Data, OldData) == 0)  
            strcpy(pHead->Data, NewData); 
        pHead = pHead->pNext;
    }
    
    /* //����2��ͨ������ֻ�޸�һ�εĺ�������޸�ȫ��
    LLNode * pDes = pHead;
    while(pDes != NULL)
    {
        pDes = FindNodeByData(pHead, OldData);
        if(pDes != NULL)
            strcpy(pDes->Data, NewData);
    } */
}

LLNode * FindNodeByIndex(LLNode * pHead, unsigned int Index)//* ͨ���±���ҽڵ�
{
    //�����Ϸ��Լ��
    if(pHead == NULL || Index < 0)
    {
        printf("ָ��ΪNULL/�±���Ч���������");
        return NULL;
    }
    //ѭ������
    int i = 0;
    while (pHead != NULL)
    {
        if(i == Index)
            return pHead;
        i++;
        pHead = pHead->pNext;
    }
    printf("�±�����������");
    return NULL;
}

LLNode * FindNodeByData(LLNode * pHead, char Data[])//* ͨ����ֵ���ҽڵ�
{
    if(pHead == NULL)
        return NULL;//������
    while (pHead != NULL)
    {
        if(strcmp(pHead->Data, Data) == 0)
            return pHead;//�ҵ���
        pHead = pHead->pNext;
    }
    return NULL;//�����޷���Ҫ��Ľڵ�
}

void FreeList(LLNode ** pHead, LLNode ** pEnd)//* �ͷ�����ռ䣬ͷβָ������
{
    LLNode * pCurrent = *pHead;
    while(pCurrent != NULL)
    {
        LLNode * pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pTemp);
    }
    *pHead = NULL;
    *pEnd = NULL;
}

void ShowList_Data(LLNode *  pHead)//* ��ӡ����
{
    LLNode * pCurrent = pHead;
    while(pCurrent != NULL)
    {
        printf("%s\n", pCurrent->Data);
        pCurrent = pCurrent->pNext;
    }
    printf("\n");
}

int main(void)
{
    LLNode * pHead = NULL;
    LLNode * pEnd = NULL;
    
    //���ӽڵ�
    AddToEnd(&pHead, &pEnd, "FFFFFFFFF");
    AddToHead(&pHead, &pEnd, "This is 0");
    AddToEnd(&pHead, &pEnd, "1");
    AddToEnd(&pHead, &pEnd, "22");
    AddToHead(&pHead, &pEnd, "333");
    //���Ӷ���ڵ�
    AddSomeNodeToEnd(&pHead, &pEnd, 5, "ALL Same");
    //��ָ���±����ڵ�
    InsertNodeByIndex(&pHead, &pEnd, 8, "Hello");
    //! ��ʾ����---��
    ShowList_Data(pHead);
    //ɾ��ָ���±�ڵ�
    DeleteNodeByIndex(&pHead, &pEnd, 3);
    //ɾ��β�ڵ�
    DeleteEnd(&pHead, &pEnd);
    //ɾ��ͷ�ڵ�
    DeleteHead(&pHead, &pEnd);
    //! ��ʾ����---ɾ
    ShowList_Data(pHead);
    //�޸Ľڵ���ֵ
    ChangeDataByData(pHead, "ALL Same", "Not Same");
    //�޸Ľڵ���ֵ��ȫ����
    ChangeAllDataByData(pHead, "ALL Same", "All Diff");
    //! ��ʾ����---��
    ShowList_Data(pHead);
    //�����±���ҽڵ�
    LLNode * pTemp_Index = FindNodeByIndex(pHead, 2);
    if (pTemp_Index == NULL) 
        printf("Node at index 2 not found.\n");
    //������ֵ���ҽڵ�
    LLNode * pTemp_Data = FindNodeByData(pHead, "1");
    if (pTemp_Data == NULL) 
        printf("Node with data '1' not found.\n");
    //! ��ʾ���---��
    
    //�ͷ�����
    FreeList(&pHead, &pEnd);

    return 0;
}
