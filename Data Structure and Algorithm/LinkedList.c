#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


//! ����Ͷ�̬����һ����ֻ��Ҫһ��ָ������װ��ͷ�ڵ��ַ���ɣ�����Ҫÿ����һ���ڵ㣬����һ���µ�����
//! ��������malloc�����ڴ棬Ȼ��ָ��ָ������ڴ��ַ��������ͷŵ�
//! �����ǣ���̬�������������ڴ�ռ䣬��������ɢ���ڴ�ռ䣬malloc����ռ䷵�صĵ�ַǿת����Ҳ��ͬ������һ���ǽṹ�����ͣ���̬���鰴��ת��

//* ����һ��������ڵ�ṹ�� */
typedef struct LLNode
{
    char Data[10];//! 10�����ü����ַ���������'\0'
    struct LLNode *pNext;
}LLNode;

LLNode * Node_Init(char * Data);//* ��ʼ��һ���ڵ㣬������ָ��ýڵ��ָ�� 
void Add_Node(LLNode * pHead, char * Data);//* �ѽڵ�ӵ�����β�� 
void Delete_EndNode(LLNode * pHead);//* ɾ������β���ڵ�
void Delete_Node(LLNode * pHead, char * Data);//* ���ݽڵ�ֵɾ������ڵ�
//* �����±���ҽڵ㣬����ָ��ýڵ��ָ��
LLNode * Find_Node(LLNode * pHead, char * Data);//* ���ݽڵ�ֵѰ�ҽڵ�
void Change_Node(LLNode * pHead, char * OldData, char * NewData);//* ���ݽڵ�ֵ�޸Ľڵ�
void Free_List(LLNode * pHead);//* �ͷ������ڴ�ռ�
void Print_List(LLNode * pHead);//* ��������

int main(void)
{
    LLNode * pHead = NULL; 
    pHead = Node_Init("1234567890");

    printf("��\n");
    Add_Node(pHead, "1111111111");
    Add_Node(pHead, "2222222222");
    Add_Node(pHead, "3333333333");
    Add_Node(pHead, "4444444444");
    Add_Node(pHead, "5555555555");
    Add_Node(pHead, "6666666666");
    Print_List(pHead);
    printf("ɾ\n");
    Delete_EndNode(pHead);
    Print_List(pHead);
    printf("-----------------------\n");
    Delete_Node(pHead, "4444444444");
    Print_List(pHead);
    printf("��-��\n");
    Change_Node(pHead, "2222222222", "7777777777");
    Print_List(pHead);

    Free_List(pHead);
    return 0;
}

LLNode * Node_Init(char * Data)//* ��ʼ��һ���ڵ㣬������ָ��ýڵ��ָ�� 
{
    LLNode * pNewNode = (LLNode *)malloc(sizeof(LLNode));
    if(pNewNode != NULL)
    {
        strcpy(pNewNode->Data, Data);
        pNewNode->pNext = NULL;//! ����һ��Ҫ��ʼ������Ȼ������⣬�ḳֵһ�������ַ
        return pNewNode;
    }
    else
    {
        printf("malloc failed!\n");
        return NULL;
    }
}

void Add_Node(LLNode * pHead, char * Data)//* ���½ڵ�ӵ�����β�� 
{
    LLNode * pNewNode = Node_Init(Data);//��ʼ��һ���ڵ�
    LLNode * pCurrent = pHead;
    if (pCurrent != NULL)
    {
        while(pCurrent->pNext != NULL)//��β�ڵ�
        {
            pCurrent = pCurrent->pNext;
        }
        pCurrent->pNext = pNewNode;
    }
}

void Delete_EndNode(LLNode * pHead)//* ɾ������β���ڵ�
{
    LLNode * pCurrent = pHead;
    if (pCurrent->pNext != NULL)
    {
        while((pCurrent->pNext)->pNext != NULL)
        {
            pCurrent = pCurrent->pNext;
        }
        free(pCurrent->pNext);
        pCurrent->pNext = NULL;
    }
}

void Delete_Node(LLNode * pHead, char * Data)//* ���ݽڵ�ֵɾ������ڵ�
{
    LLNode * pCurrent = pHead;
    while(pCurrent->pNext != NULL)
    {
        if(strcmp(pCurrent->pNext->Data, Data) == 0)
        {
            LLNode * pLast = pCurrent->pNext->pNext;
            free(pCurrent->pNext);
            pCurrent->pNext = pLast;
        }
        pCurrent = pCurrent->pNext;
    }
}

LLNode * Find_Node(LLNode * pHead, char * Data)//* ���ݽڵ�ֵѰ�ҽڵ�
{
    LLNode * pCurrent = pHead;
    while(pCurrent != NULL)
    {
        if(strcmp(pCurrent->Data, Data) == 0)
        {
            return pCurrent;
        }
        pCurrent = pCurrent->pNext;
    }
    return NULL;
}

void Change_Node(LLNode * pHead, char * OldData, char * NewData)//* ���ݽڵ�ֵ�޸Ľڵ�
{
    LLNode * pCurrent = Find_Node(pHead, OldData);
    if(pCurrent != NULL)
    {
        strcpy(pCurrent->Data, NewData);
    }
}

void Free_List(LLNode * pHead)//* �ͷ������ڴ�ռ�
{
    LLNode * pCurrent = pHead;
    while(pCurrent != NULL)
    {
        free(pCurrent);
        pCurrent = pCurrent->pNext;
    }
}

//* ��������
void Print_List(LLNode * pHead)
{
    LLNode * pCurrent = pHead;
    while (pCurrent != NULL)
    {
        printf("%s\n", pCurrent->Data);
        pCurrent = pCurrent->pNext;
    }
}
