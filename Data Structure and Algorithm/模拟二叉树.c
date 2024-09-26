#include <stdio.h>
#include <malloc.h>

//! �������ṹ�����ڵ㡢Ҷ�ӽڵ㡢�ֵܽڵ㡢ǰ���ڵ㡢�����ڵ㡢��������������
//! ǰ������������������������������ҡ�����ҡ����Ҹ�

//* �������ڵ㶨��
typedef struct TNode
{
    int Data;
    struct TNode * pFather;
    struct TNode * pLeft;
    struct TNode * pRight;
}TreeNode;

//* ջ�ڵ㶨��
typedef struct SNode
{
    TreeNode * pTreeNode;//װ�Ŷ������ڵ�
    struct SNode * pNext;
    struct SNode * pPre;
}StackNode;

//* ջ�Ŀ�ͷ
StackNode Head;
//* ջ��ջ��ָ�루βָ�룩
StackNode * pStackTop = &Head;

//* �������ڵ���ջ��β��ӣ�
void Push(TreeNode * pTreeNode)
{
    //�����Ϸ��Լ��
    if(pTreeNode == NULL)
        return;
    //����ջ�ڵ�
    StackNode * pNewStackNode = (StackNode *)malloc(sizeof(StackNode));
    if(pNewStackNode == NULL)
        return;
    //ջ�ڵ��Ա��ֵ
    pNewStackNode->pTreeNode = pTreeNode;
    pNewStackNode->pPre = NULL;
    pNewStackNode->pNext = NULL;
    //����
    pStackTop->pNext = pNewStackNode;
    pNewStackNode->pPre = pStackTop;
    pStackTop = pNewStackNode;
}

//* �������ڵ��ջ��βɾ����
TreeNode * Pop(void)
{
    //ջΪ��
    if(pStackTop == &Head)
        return NULL;
    //��¼Ҫɾ����ջ���ڵ�
    TreeNode * pTreeNode = pStackTop->pTreeNode;
    //�ͷ�ջ���ڵ㡢�޸�ջ��ָ��
    pStackTop = pStackTop->pPre;
    free(pStackTop->pNext);
    pStackTop->pNext = NULL;
    //����ɾ���Ķ������ڵ�
    return pTreeNode;
}

//! ���õݹ����������ʱ����ջ����ջ��ջ���̣�һ����ʼִ��ĳ�ڵ㺯���ĵ�һ�䣬�ýڵ������ջ��ִ�������һ�䣨�������������ýڵ�ͳ�ջ
void PrintTreeList(TreeNode * TreeNode) 
{
    if(TreeNode != NULL)
    {
        //�����д���Ĳ�ͬλ�ÿ���ʵ�����ֱ�����ʽ
        printf("%d ", TreeNode->Data);
        PrintTreeList(TreeNode->pLeft);
        PrintTreeList(TreeNode->pRight);
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
    
    PrintTreeList(&t1);

    return 0;
}
