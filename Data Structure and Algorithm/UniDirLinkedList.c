#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//! ����Ͷ�̬����һ����ֻ��Ҫһ��ָ������װ��ͷ�ڵ��ַ���ɣ�����Ҫÿ����һ���ڵ㣬����һ���µ�����
//! ��������malloc�����ڴ棬Ȼ��ָ��ָ������ڴ��ַ��������ͷŵ�
//! �����ǣ���̬�������������ڴ�ռ䣬��������ɢ���ڴ�ռ䣬malloc����ռ䷵�صĵ�ַǿת����Ҳ��ͬ������һ���ǽṹ�����ͣ���̬���鰴��ת��
//! �п�ͷ�ڵ㣬������ɾ���ڿ�ͷ�������
//! ��̬��¼βָ�룬�ŵ���ĩβ�����½ڵ�ʱ�����ٴ�ͷ��ѯ�õ�βָ�룬��ߴ���ִ��Ч��
//  �����ڸı�ָ����Ҫ����ָ��
//! void�����е�return;���˳���������

//! ����DeleteFirstNodeByData�����᷵���ҵ��ڵ��ǰһ���ڵ㣬������������������Ŀ��ڵ�

//* ����һ��������ڵ�ṹ�� */
typedef struct Node
{
    char Data[20];//! 20�����ü����ַ���������'\0'
    //! ���ﲻС��д���˳�������������ַ������������Խ�磬��ʱ�����Ī����ס

    //TODO ����ISO C++ forbids converting a string constant to 'char*'
    //TODO ԭ����C�����У��ַ������������� "Add Same" �� "First Modified"��ʵ������ָ���ַ�������Ԫ�ص�ָ�룬���ǵ������� const char*�����㳢�Խ�����Ϊ�������ݸ�char* ���Ͳ���ʱ���������ᱨ����Ϊ���ǲ���ȫ�ġ����ַ��������ǲ�Ӧ�ñ��޸ĵ�
    //TODO ���������1�������������Ҫ�޸Ĵ�����ַ��������Խ��������͸�Ϊ const char*
    //TODO ��Ҫ�޸ģ�2�����δ�����ջ�϶����ַ����飬��ʹ�� strcpy �����������ַ�����������Щ�����У������д�����Щ����
    struct Node *pNext;
}LLNode;

void AddToHead(LLNode ** pHead, LLNode ** pEnd, const char Data[]);//* �ڿ�ͷ�����½ڵ�
void AddToEnd(LLNode ** pHead, LLNode ** pEnd, const char Data[]);//* ��ĩβ�����½ڵ�
void AddSomeNodeToEnd(LLNode ** pHead, LLNode ** pEnd, unsigned int Number, const char Data[]);//* ��β�����Ӷ����ͬ���ݵĽڵ�
void InsertNodeByIndex(LLNode ** pHead, LLNode ** pEnd, unsigned int Index, const char Data[]);//* ͨ���±����ڵ�

void DeleteHead(LLNode ** pHead, LLNode ** pEnd);//* ɾ��ͷ�ڵ�
void DeleteEnd(LLNode ** pHead, LLNode ** pEnd);//* ɾ��β�ڵ�
void DeleteNodeByIndex(LLNode ** pHead, LLNode ** pEnd, unsigned int Index);//* ͨ���±�ɾ���ڵ�
LLNode * DeleteFirstNodeByData(LLNode ** pHead, LLNode ** pEnd, const char Data[]);//* ͨ����ֵɾ����һ���ڵ�
void DeleteAllNodeByData(LLNode ** pHead, LLNode ** pEnd, const char Data[]);//* ͨ����ֵɾ�����нڵ�

void ChangeFirstDataByData(LLNode * pHead, const char OldData[], const char NewData[]);//* �޸�ָ����ֵ�ĵ�һ���ڵ����
void ChangeAllDataByData(LLNode * pHead, const char OldData[], const char NewData[]);//* �޸�ָ����ֵ��ȫ���ڵ����ֵ

int GetNodeCount(LLNode * pHead);//* ͳ������ڵ�����
LLNode * FindNodeByIndex(LLNode * pHead, unsigned int Index);//* ͨ���±���ҽڵ�
LLNode * FindFirstNodeByData(LLNode * pHead, const char Data[]);//* ͨ����ֵ���ҽڵ�

void SwapByData(LLNode * pHead, const char Data1[], const char Data2[]);//* ���������ڵ������
void SwapByIndex(LLNode * pHead, unsigned int Index1, unsigned int Index2);//* ͨ���±꽻���ڵ�����
void ReverseListByData(LLNode * pHead, LLNode * pEnd);//* ��ת����
void ReverseListByHelpSpace(LLNode ** pHead, LLNode ** pEnd);//* ��ת���������ռ䣩

void FreeList(LLNode ** pHead, LLNode ** pEnd);//* �ͷ�����ռ䣬ͷβָ������
void ShowList_Data(LLNode *  pHead);//* ��ӡ����

int main(void)
{
    LLNode * pHead = NULL;
    LLNode * pEnd = NULL;

    //* ���ӽڵ�
    AddToEnd(&pHead, &pEnd, "3");
    AddToHead(&pHead, &pEnd, "2");
    AddToEnd(&pHead, &pEnd, "4");
    AddToEnd(&pHead, &pEnd, "5");
    AddToHead(&pHead, &pEnd, "1");
    //* ���Ӷ���ڵ�
    AddSomeNodeToEnd(&pHead, &pEnd, 5, "6");
    //* ��ָ���±����ڵ�
    InsertNodeByIndex(&pHead, &pEnd, 6, "Insert7");
    InsertNodeByIndex(&pHead, &pEnd, 8, "Insert8");
    //! ��ʾ����---��
    ShowList_Data(pHead);

    //* ɾ��ͷ�ڵ�
    DeleteHead(&pHead, &pEnd);
    //* ɾ��β�ڵ�
    DeleteEnd(&pHead, &pEnd);
    //* ɾ��ָ���±�ڵ�
    DeleteNodeByIndex(&pHead, &pEnd, 3);
    //* ɾ��ָ����ֵ�ڵ�
    DeleteFirstNodeByData(&pHead, &pEnd, "Insert7");
    //* ɾ��ָ����ֵ�����нڵ�
    DeleteAllNodeByData(&pHead, &pEnd, "6");
    //! ��ʾ����---ɾ
    ShowList_Data(pHead);

    //* ���Ӷ���ڵ�
    AddSomeNodeToEnd(&pHead, &pEnd, 5, "9");
    //* �޸Ľڵ���ֵ
    ChangeFirstDataByData(pHead, "9", "9 Modified");
    //* �޸Ľڵ���ֵ��ȫ����
    ChangeAllDataByData(pHead, "9", "9 All Modified");
    //! ��ʾ����---��
    ShowList_Data(pHead);

    //* �����±���ҽڵ�
    LLNode * pTemp_Index = FindNodeByIndex(pHead, 2);
    if (pTemp_Index == NULL) 
        printf("Node at index 2 not found.\n");
    //* ������ֵ���ҽڵ�
    LLNode * pTemp_Data = FindFirstNodeByData(pHead, "1");
    if (pTemp_Data == NULL) 
        printf("Node with data '1' not found.\n");
    //! ��ʾ���---��
 
    //* ���������ڵ�����
    SwapByData(pHead, "9 Modified", "9 All Modified");
    //* ��ת����
    ReverseListByData(pHead, pEnd);
    //* ��ת���������ռ䣩
    ReverseListByHelpSpace(&pHead, &pEnd);
    //! ��ʾ����---��
    ShowList_Data(pHead);

    //�ͷ�����
    FreeList(&pHead, &pEnd);

    return 0;
}

void AddToHead(LLNode ** pHead, LLNode ** pEnd, const char Data[])//* �ڿ�ͷ�����½ڵ�
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

void AddToEnd(LLNode ** pHead, LLNode ** pEnd, const char Data[])//* ��ĩβ�����½ڵ�
{
    //�����ڵ�
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode != NULL)//��������ռ�ʧ�ܵĿ�����
    {
        //�ڵ��Ա��ֵ
        strcpy(pNewNode->Data, Data);
        pNewNode->pNext = NULL;//����
        //����
        if(*pHead == NULL)//������
        {
            *pHead = pNewNode;//�½ڵ��Ϊ��һ���ڵ�
        }
        else 
            (*pEnd)->pNext = pNewNode;//���Ӿ�β�ڵ����β�ڵ�
        *pEnd = pNewNode;//βָ��ָ���½ڵ�
    }
}

void AddSomeNodeToEnd(LLNode ** pHead, LLNode ** pEnd, unsigned int Number, const char Data[])//* ��β�����Ӷ����ͬ���ݵĽڵ�
{
    for(int i = 0; i < Number; i++)
        AddToEnd(pHead, pEnd, Data);
}

void InsertNodeByIndex(LLNode ** pHead, LLNode ** pEnd, unsigned int Index, const char Data[])//* ͨ���±����ڵ�
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
        //Ѱ�Ҳ���λ�õ�ǰһ���ڵ�
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
    //�����Ϸ��Լ��
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
    //�����Ϸ��Լ��
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
        //��β�ڵ��ǰһ��
        LLNode * pCurrent = *pHead;
        while(pCurrent->pNext != *pEnd)
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
        LLNode * pLast = FindNodeByIndex(*pHead, Index - 1);
        if(pLast != NULL)
        { 
            if(pLast->pNext == *pEnd)//! ���ָ��±���β�ڵ�λ��
                DeleteEnd(pHead, pEnd);
            else
            {
                LLNode * pTemp = pLast->pNext;
                pLast->pNext = pTemp->pNext;
                free(pTemp);
            }            
        }
    }
    return; 
}

LLNode * DeleteFirstNodeByData(LLNode ** pHead, LLNode ** pEnd, const char Data[])//* ͨ����ֵɾ���ҵ��ĵ�һ���ڵ�
{
    //�����Ϸ��Լ��
    if(*pHead == NULL)//������
        return NULL;
    if(strcmp((*pHead)->Data, Data) == 0)//��ֵ��Ӧ����ͷ�ڵ�
    {
        DeleteHead(pHead, pEnd);
        return *pHead;//! ɾ������ͷ�ڵ㣬�򷵻ص�Ҳ��ͷ�ڵ�
    }
    //! ���ﲻ���ж�β�ڵ���ֵ����Ϊ���ڶ������Ҫ��ڵ�ʱ������©�м�ڵ㣬�ʣ����밴�ڵ�˳��
    else//��Ŀ��ڵ��ǰһ��
    {
        LLNode * pCurrent = *pHead;
        while(pCurrent->pNext != NULL)
        {
            if(strcmp(pCurrent->pNext->Data, Data) == 0)
            {
                if(pCurrent->pNext == *pEnd)//! �������ۣ�ɾ��β�ڵ�ʱҪͬʱ�޸�βָ�룬�����ڵ㲻��
                {
                    DeleteEnd(pHead, pEnd);
                    return NULL;
                }
                else
                {
                    LLNode * pTemp = pCurrent->pNext->pNext;
                    free(pCurrent->pNext);
                    pCurrent->pNext = pTemp;
                    return pCurrent;//! ɾ���Ĳ���ͷ�ڵ㣬�򷵻�ɾ���ڵ��ǰһ���ڵ�,����DeleteAllNodeByData�Ľڵ����ӣ���ֹ����
                }
            }
            pCurrent = pCurrent->pNext;
        }
        return NULL;
    }
}

void DeleteAllNodeByData(LLNode ** pHead, LLNode ** pEnd, const char Data[])//* ɾ��ָ����ֵ�����нڵ�
{
    //�����Ϸ��Լ��
    if(*pHead == NULL)//������
        return;
    LLNode * pStart = DeleteFirstNodeByData(pHead, pEnd, Data);//ɾ���ҵ��ĵ�һ���ڵ�
    while(pStart != NULL)
        pStart = DeleteFirstNodeByData(&pStart, pEnd, Data);//! ��ɾ���ڵ��ǰһ���ڵ㿪ʼѭ����ɾ������Ҫ��ĵ�һ���ڵ�

    /* if(strcmp((*pHead)->Data, Data) == 0)//�ȴ���������ͷ�ڵ㣬��û��ǰ�ڵ㣬�޷�����������Ĵ���
        DeleteHead(pHead, pEnd);
    LLNode * pCurrent = *pHead;
    LLNode * pTemp = NULL;
    while(pCurrent->pNext != NULL)
    {
        if(strcmp(pCurrent->pNext->Data, Data) == 0)
        {
            pTemp = pCurrent->pNext->pNext;
            free(pCurrent->pNext);
            pCurrent->pNext = pTemp;
        }
        else pCurrent = pCurrent->pNext;//! һ��Ҫ��else
        //! ɾ��ĳ�ڵ�󣬺���ڵ�pLater��λ����ʱ��pCurrent���Ƶ�pLater���´�ѭ������ʱ������ֵ�Ƚϵ���pLater�ĺ�һ���ڵ㣬pLater����ͱ������ˣ��ʣ�ɾ��ĳ�ڵ��pCurrent���ܺ��ƣ�������Ҫ�ٴο���ѭ�������в�λ�ĺ�ڵ����ֵ�Ƚϣ�ֱ����ڵ㲻��Ҫɾ��Ϊֹ
    } */
}

void ChangeFirstDataByData(LLNode * pHead, const char OldData[], const char NewData[])//* �޸�ָ����ֵ�ĵ�һ���ڵ����
{
    LLNode * pDes = FindFirstNodeByData(pHead, OldData);
    if(pDes != NULL)
        strcpy(pDes->Data, NewData);
    else
        printf("�˽ڵ㲻���ڣ��޷��޸�\n");
}

void ChangeAllDataByData(LLNode * pHead, const char OldData[], const char NewData[])//* �޸�ָ����ֵ��ȫ���ڵ����ֵ
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

int GetNodeCount(LLNode * pHead)
{
    //�����Ϸ��Լ��
    if(pHead == NULL)
        return -1;
    int Num = 0;
    while (pHead != NULL)
    {
        Num++;//�������ٸ��ڵ�
        pHead = pHead->pNext;
    }
    return Num;
}

LLNode * FindNodeByIndex(LLNode * pHead, unsigned int Index)//* ͨ���±���ҵ�һ���ڵ�
{
    //�����Ϸ��Լ��
    if(pHead == NULL || Index < 0)
    {
        printf("ָ��ΪNULL/�±���Ч���������");
        return NULL;
    }
    //��ѯ����
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

LLNode * FindFirstNodeByData(LLNode * pHead, const char Data[])//* ͨ����ֵ���ҵ�һ���ڵ�
{
    //�����Ϸ��Լ��
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

void SwapByData(LLNode * pHead, const char Data1[], const char Data2[])//* ���������ڵ��ȫ������
{
    //�����Ϸ��Լ��
    if(pHead == NULL)
        return;
    LLNode *pData1 = FindFirstNodeByData(pHead, Data1);
    LLNode *pData2 = FindFirstNodeByData(pHead, Data2);
    if(pData1 != NULL && pData2 != NULL)
    {
        /* strcpy(pData1->Data, Data2);
        strcpy(pData2->Data, Data1); *///һ���ڵ���������ܶ�ʱ��������ֵ���鷳
        //* ע�⣺�ṹ���Ա�ڴ������ѭ����ԭ��
        //* ��Ա����ʼ��ַ�����С�������������磬����һ��һ�ֽڱ���������һ��int���ֽڱ�������int�����ӵ�����ֽڿ�ʼ�洢
        LLNode TempNode = *pData1;
        memcpy(pData1, pData2, 20);
        memcpy(pData2, &TempNode, 20);//* һ���Կ����ڵ�����в�ͬ�������ݣ�ע�����������ռ�ֽ�������Ҫ��������pNext
    } 
}

void SwapByIndex(LLNode * pHead, unsigned int Index1, unsigned int Index2)//* ͨ���±꽻���ڵ�����
{
    //�����Ϸ��Լ��
    if(pHead == NULL)
        return;
    LLNode *pData1 = FindNodeByIndex(pHead, Index1);
    LLNode *pData2 = FindNodeByIndex(pHead, Index2);
    if(pData1 != NULL && pData2 != NULL)
    {
        LLNode TempNode = *pData1;
        memcpy(pData1, pData2, 20);
        memcpy(pData2, &TempNode, 20);
    }
}

void ReverseListByData(LLNode * pHead, LLNode * pEnd)//* ��ת��������ڵ�������ͨ���±�Ի����ݣ�
{
    //�����Ϸ��Լ��
    if(pHead == NULL || pHead->pNext == NULL)//ֻ��һ���ڵ㣬���跭ת
        return;
    int EndIndex = GetNodeCount(pHead) - 1;
    for(int i = 0; i < EndIndex; i++, EndIndex--)//! ִ��Ч�ʵͣ�ÿ�ν������ݶ�Ҫ��ͷ��ʼ��ѯ���ڵ�λ��
        SwapByIndex(pHead, i, EndIndex);//��������
}

void ReverseListByHelpSpace(LLNode ** pHead, LLNode ** pEnd)//* ��ת���������ռ䣩
{
    //�����Ϸ��Լ��
    if(*pHead == NULL || (*pHead)->pNext == NULL)//ֻ��һ���ڵ㣬���跭ת
        return;
    LLNode * pCurrent = *pHead;
    LLNode * pNewHead = NULL;LLNode * pNewEnd = NULL;//* ���������ͷָ���βָ��
    while (pCurrent != NULL)//! ֻ����ѯһ�飬�����������ת
    {
        AddToHead(&pNewHead, &pNewEnd, pCurrent->Data);//* ����ͷ��Ӻ�������������ѯ��ÿ���ڵ����ݶ���ӵ��������ͷ��ʵ�ַ�תЧ��
        pCurrent = pCurrent->pNext;
    }
    FreeList(pHead, pEnd);
    //ͷβָ��ָ�����˷�ת���ݵ�������
    *pHead = pNewHead;
    *pEnd = pNewEnd;
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
