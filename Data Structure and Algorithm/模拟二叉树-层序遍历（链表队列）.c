#include <stdio.h>
#include <malloc.h>

//* ԭ������������ö���ʵ�֣��ڵ���ӣ�����ӡ��ʱ�����������ҽڵ���ӣ�������ң�
//* ʵ�֣�ͬһ��ڵ����δ�������Ӻ���һ��ڵ����������

typedef struct Node
{
    int Data;
    struct Node * pFather;
    struct Node * pLeft;
    struct Node * pRight;
}TreeNode;

//! ����ṹ�Ķ��У�β��ӡ�ͷɾ���������п�ͷ����
//* ɾ���ڵ�������ǰһ���ڵ㣬���Բ��õ�������
//* �п�ͷ���Լ��߼���������ͷָ��仯�����Բ����п�ͷ����
typedef struct LLNode
{
    TreeNode * pTreeNode;
    struct LLNode * pNext;
}QueueNode;

QueueNode QueueHead;//* ��ͷ
QueueNode * pQueueEnd = &QueueHead;//* ��βָ��

void Push(TreeNode * Node)//β���
{
    if(Node == NULL)
        return;
    //�����ڵ�
    QueueNode * pNew = (QueueNode *)malloc(sizeof(QueueNode));
    if(pNew == NULL)
        return;
    //�ڵ��Ա��ֵ
    pNew->pTreeNode = Node;
    pNew->pNext = NULL;
    //���ӣ��ڶ�β����Ԫ��
    pQueueEnd->pNext = pNew;
    pQueueEnd = pNew;
}

//ͷɾ��
TreeNode * Pop(void)//* һ��Ҫ����ɾ������β�ڵ���������ʱβָ����Ҫָ���ͷ
{
    //������Ԫ�أ��������
    if(pQueueEnd == &QueueHead)
        return NULL;
    //��¼��ͷ���������ӣ�
    QueueNode * pTemp = QueueHead.pNext;
    //�޸�ָ��
    QueueHead.pNext = pTemp->pNext;
    //* Ҫɾ����ͷ�ڵ�ͬʱҲ��β�ڵ�
    if(pTemp->pNext == NULL)
        pQueueEnd = &QueueHead;
    //* ��¼��ͷ�洢�Ķ������ڵ��ַ����Ϊ��ͷ�洢������������return ֮ǰ�Ѿ����ͷţ�������Ҫ���صĶ������ڵ��ַ
    TreeNode * pNode = pTemp->pTreeNode;
    //�ͷŶ�ͷ
    free(pTemp);
    //����ԭ���Ķ�ͷ
    return pNode;
}

void Look(TreeNode * pRoot)
{
    //��ֹ�ն�����
    if(pRoot == NULL)
        return;
    TreeNode * pCurrent = pRoot;
    Push(pCurrent);
    while(1)
    {
        pCurrent =  Pop();
        printf("%d ", pCurrent->Data);
        if(pCurrent->pLeft !=  NULL)
            Push(pCurrent->pLeft);
        if(pCurrent->pRight !=  NULL)
            Push(pCurrent->pRight);
        //* ����ʱ��������һ��ڵ���ӣ�����ֻ����һ��û�нڵ㼴����Ϊ���һ��ʱ������ڵ�ȫ�����Ӻ���п��ˣ���ʱ�����������������
        if(pQueueEnd == &QueueHead)
            return;
    }
}

int main(void)
{
    TreeNode t1 = {1};
    TreeNode t2 = {2};
    TreeNode t3 = {3};
    TreeNode t4 = {4};
    TreeNode t5 = {5};
    TreeNode t6 = {6};
    TreeNode t7 = {7};
    TreeNode t8 = {8};
    TreeNode t9 = {9};
    TreeNode t10 = {10};

    t1.pLeft = &t2;
    t1.pRight = &t3;

    t2.pFather = &t1;
    t2.pLeft = &t4;
    t2.pRight = &t5;

    t3.pFather = &t1;
    t3.pRight = &t6;

    t4.pFather = &t2;

    t5.pFather = &t2;
    t5.pLeft = &t7;
    t5.pRight = &t8;

    t6.pFather = &t3;
    t6.pLeft = &t9;
    t6.pRight = &t10;

    t7.pFather = &t5;
    t8.pFather = &t5;
    t9.pFather = &t6;
    t10.pFather = &t6;


    Look(&t1);

    return 0;
} 
