#include <stdio.h>
#include <malloc.h>

//! �������ṹ�����ڵ㡢Ҷ�ӽڵ㡢�ֵܽڵ㡢ǰ���ڵ㡢�����ڵ㡢��������������
//! ǰ������������������������������ҡ�����ҡ����Ҹ�

//! ջ�����ڵ����ȡ���ڶ���������ȣ������������Ϊ4����ջ����ջ��ջ�����еĽڵ��������ҲΪ4��

//* �������ڵ㶨��
typedef struct TNode
{
    int Data;
    struct TNode * pFather;
    struct TNode * pLeft;
    struct TNode * pRight;
}TreeNode;

//* ����ջ�ڵ㶨��
typedef struct SNode
{
    TreeNode * pTree;//װ�Ŷ������ڵ�
    struct SNode * pNext;
    struct SNode * pPre;
}StackNode;

//* ����ջ�Ŀ�ͷ
StackNode Head;
//* ����ջ��ջ��ָ�루βָ�룩
StackNode * pStackTop = &Head;//��ʼû�����ݣ�ָ���ͷ

//* �������ڵ�������ջ��β��ӣ�
void Push(TreeNode * pTree)
{
    //�����Ϸ��Լ��
    if(pTree == NULL)
        return;
    //����ջ�ڵ�
    StackNode * pNewStack = (StackNode *)malloc(sizeof(StackNode));
    if(pNewStack == NULL)
        return;
    //ջ�ڵ��Ա��ֵ
    pNewStack->pTree = pTree;
    pNewStack->pPre = NULL;
    pNewStack->pNext = NULL;
    //����
    pStackTop->pNext = pNewStack;
    pNewStack->pPre = pStackTop;
    pStackTop = pNewStack;
}

//* �������ڵ������ջ��βɾ����
TreeNode * Pop(void)
{
    //ջΪ��
    if(pStackTop == &Head)
        return NULL;
    //��¼Ҫɾ����ջ���ڵ�
    TreeNode * pTree = pStackTop->pTree;
    //�ͷ�ջ���ڵ㡢�޸�ջ��ָ��
    pStackTop = pStackTop->pPre;
    free(pStackTop->pNext);
    pStackTop->pNext = NULL;
    //����ɾ���Ķ������ڵ�
    return pTree;
}

//* ���õݹ����������ʱ����ջ����ջ��ջ���̣�һ����ʼִ��ĳ�ڵ㺯���ĵ�һ�䣬�ýڵ������ջ��ִ�������һ�䣨�������������ýڵ�ͳ�ջ
void Look_1(TreeNode * pRoot) 
{
    if(pRoot != NULL)
    {
        //�����д���Ĳ�ͬλ�ÿ���ʵ�����ֱ�����ʽ
        printf("%d ", pRoot->Data);
        Look_1(pRoot->pLeft);
        Look_1(pRoot->pRight);
    }
}

//* ��������ջ����������
void Look_2(TreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    TreeNode * pCurrent = pRoot;
    while(pCurrent != NULL || pStackTop != &Head)//�˳���������û���ˣ�ջҲû����
    {
        //������������һֱ��Ҷ�ӽڵ�
        while(pCurrent != NULL)
        {
            printf("%d ", pCurrent->Data);
            Push(pCurrent);
            pCurrent = pCurrent->pLeft;
        }

        // if(pStackTop == &Head)//��ʱpCurrent һ����NULL��ֻ��Ҫ�ж�ջ���Ƿ�Ϊ��ͷ����
        //     break;

        //ȡ��ջ���ڵ㣬ת���ҽڵ�(Ȼ��ѭ���ص���ʼ�������ҽڵ��������)
        TreeNode * pTemp = Pop();
        pCurrent = pTemp->pRight;

        //�ж��Ƿ����ȫ��
        //pStackTop == &Head���Ѿ����������ڵ�����ұߣ��������ϵĽڵ㶼�Ѿ���ջ�Ҵ�ӡ��
        //pCurrent == NULL��pTemp ��Ҷ�ӽڵ�
    }
    printf("\n");
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
    
    Look_1(&t1);
    printf("\n");
    Look_2(&t1);

    return 0;
}
