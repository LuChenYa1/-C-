#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *pNext;
};

struct Node * Search_Element(struct Node *pHead, int Data);
struct Node * Search_Index(struct Node *pHead, int Index);
int Number_Element(struct Node *pHead, int Data);
char ChangeByElement(struct Node *pHead, int OldValue, int NewValue);
char ChangeByIndex(struct Node *pHead, int Index, int NewValue);
int Nodes_Element(struct Node *pHead, struct Node * Arr[4], int Data, int ArrSize);
void PrintList(struct Node *pHead);

int main(void) 
{
    //* ��ʼ������
    struct Node a = {1, NULL},
    b = {2, NULL},
    c = {3, NULL},
    d = {4, NULL};
    a.pNext = &b;
    b.pNext = &c;
    c.pNext = &d;
    d.pNext = NULL;

    struct Node * pTemp;

    //* ��ӡ����
    PrintList(&a);

    //* ����������Ԫ��2�Ľڵ�
    pTemp = Search_Element(&a, 2);
    if(pTemp == NULL)printf("�����в�����Ԫ��2\n");
    else printf("�����д���Ԫ��%d\n", pTemp->Data);

    //* �����������±�Ϊ3��Ԫ��
    pTemp = Search_Index(&a, 3);
    if(pTemp == NULL)printf("�����в����ڴ˽ڵ�\n");
    else printf("�����д��±��ӦԪ��Ϊ%d\n", pTemp->Data);

    //* ����������Ԫ��2�ĸ���
    int i = Number_Element(&a, 1);
    printf("�����д�Ԫ�صĸ���Ϊ%d\n", i);

    //* ����������Ԫ��4��Ӧ�Ľڵ�
    struct Node * Arr[4] = {NULL, NULL, NULL, NULL};// ����һ�����飬���ڴ洢������ĳԪ�ص����нڵ�
    Nodes_Element(&a, Arr, 4, 2);//! Arr������ĵ�ַ��Arr+����ֱ��ָ��ʵ������ռ䣬p[0] = *p[0]

    for(int i = 0; i < 4 && Arr[i] != NULL; i++)//! i < 4 ���� p[i] != NULLǰ�棬��ֹԽ��
        printf("%d \n", Arr[i]->Data);

    //* ͷ��ӽڵ�
    struct Node e = {1, NULL};
    e.pNext = &a;
    //* β��ӽڵ�
    struct Node f = {2, NULL};
    d.pNext = &f;
    //* �м���ӽڵ�
    struct Node g = {3, NULL};
    g.pNext = &c;
    b.pNext = &g;
    PrintList(&e);

    //* ɾ��ͷ�ڵ�
    e.pNext = NULL;
    // ...�ͷ�
    PrintList(&e);
    //* ɾ��β�ڵ�
    d.pNext = NULL;
    PrintList(&a);
    //* ɾ���м�ڵ�
    b.pNext = g.pNext;
    PrintList(&a);

    //* �滻������Ԫ��1Ϊ2
    ChangeByElement(&a, 4, 2);
    PrintList(&a);
    ChangeByIndex(&a, 1, 1);
    PrintList(&a);

    return 0;
}

struct Node * Search_Element(struct Node *pHead, int Data)//* ����������Ԫ��Data��Ӧ�Ľڵ�,Ĭ��ֻ��һ��
{
    //* ��������ֱ���ҵ�ֵΪData�Ľڵ��������Ϊ��
    while (pHead != NULL && pHead->Data != Data)
    {
        // �ƶ�ָ�뵽��һ���ڵ�
        pHead = pHead->pNext;
    } 

    // �����ҵ��Ľڵ㣬���δ�ҵ��򷵻�NULL
    if(pHead == NULL)return NULL;
    else return pHead;// �����ҵ��Ľڵ�
} 

struct Node * Search_Index(struct Node *pHead, int Index)//* ���������е�ָ���±�Ľڵ�
{
    int i = 0;
    while (pHead != NULL && i < Index)// ��������ֱ���ҵ��±�ΪIndex�Ľڵ��������Ϊ��
    {
        // �ƶ�ָ�뵽��һ���ڵ�
        pHead = pHead->pNext;
        i++;
    } 
    if(pHead == NULL)return NULL;
    else return pHead;// �����ҵ��Ľڵ�
}

char ChangeByElement(struct Node *pHead, int OldValue, int NewValue)//* �滻������Ԫ��OldValueΪNewValue
{
    char i = 0;
    while(pHead != NULL)
    {
        if(pHead->Data == OldValue)
        {
            pHead->Data = NewValue;
            i = 1;
        }
        // �ƶ�ָ�뵽��һ���ڵ�
        pHead = pHead->pNext;
    }
    return i;
}

char ChangeByIndex(struct Node *pHead, int Index, int NewValue)//* �滻�����е�ָ���±��Ԫ��ΪNewValue
{
    struct Node *pTarget = Search_Index(pHead, Index);
    if(pTarget == NULL)return 0;//�ýڵ㲻����
    else 
    {
        pTarget->Data = NewValue;
        return 1;
    }
}

int Number_Element(struct Node *pHead, int Data)//* ����������ĳ��Ԫ�صĸ���
{
    int i = 0;
    while (pHead != NULL)
    {
        if(pHead->Data == Data)i++;
        // �ƶ�ָ�뵽��һ���ڵ�
        pHead = pHead->pNext;
    } 
    return i;
}

int Nodes_Element(struct Node *pHead, struct Node * Arr[4], int Data, int ArrSize)//* ����������Ԫ��Data��Ӧ�Ľڵ�͸���
{
    int i = 0;
    while (pHead != NULL)
    {
        if(pHead->Data == Data && i < ArrSize)
        {
            Arr[i++] = pHead;
        }
        // �ƶ�ָ�뵽��һ���ڵ�
        pHead = pHead->pNext;
    } 
    return i;
}

void PrintList(struct Node *pHead)//* ��ӡ����
{
    printf("����Ԫ��Ϊ��");
    while(pHead != NULL)
    {
        printf("%d ", pHead->Data);
        pHead = pHead->pNext;
    }
    printf("\n");
}
