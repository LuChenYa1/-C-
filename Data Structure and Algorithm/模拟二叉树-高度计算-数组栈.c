#include <stdio.h>
#include <malloc.h>

//! �������߶ȼ���ԭ������ջ��������������ջ��ջ������ջ��Ԫ�ظ������ʱ��Ϊ�������ĸ߶�

//* �������ڵ㶨��
typedef struct TNode
{
    int Data;
    struct TNode * pFather;
    struct TNode * pLeft;
    struct TNode * pRight;
}TreeNode;

//* ����ջ
#define Deep 5
TreeNode * Stack[Deep];
int StackTop = -1;//��ʼû�����ݣ�ջ���±�ָ��-1

int Max_Height;

//* �������ڵ�������ջ��β��ӣ�
void Push(TreeNode * pTree)
{
    //�����Ϸ��Լ��
    if(pTree == NULL)
        return;
    StackTop ++;
    Stack[StackTop] = pTree;
}

//* �������ڵ������ջ��βɾ����
TreeNode * Pop(void)
{
    //ջΪ��
    if(StackTop == -1)
        return NULL;
    int Temp = StackTop;
    StackTop--;
    return Stack[Temp];
}

//* �������������������Ϊջ�����Ԫ����������ͨ�ã��ܼ����ƽ�������
void Look_1(TreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    TreeNode * pCurrent = pRoot;
    TreeNode * pPre = NULL;
    while(1)
    {
        //������������һֱ��Ҷ�ӽڵ�
        while(pCurrent != NULL)
        {
            Push(pCurrent);
            pCurrent = pCurrent->pLeft;
        }
        if(StackTop == -1)
            break;

        //* ����1������ջ���У�
        //! ��������ջ����ɫ��ջ��ָ�����±꣬ʵʱ��¼ջ��Ԫ�ظ������Ƚϴ�С
        if(StackTop > Max_Height)
            Max_Height = StackTop;
        printf("%d ", StackTop + 1);

        if(Stack[StackTop]->pRight == NULL || Stack[StackTop]->pRight == pPre)
        {
            pPre = Pop();
            // printf("%d ", pPre->Data); 
        }
        else
            pCurrent = Stack[StackTop]->pRight;
    }
    Max_Height ++;
    printf("\n");
}

//* ǰ/�������������������Ϊջ�����Ԫ�������� 1��ֻ������ƽ���������ֻҪ��һ�������Ĳ㣬ջ��������Ͷ������������ͼ�һ��
void Look_2(TreeNode * pRoot)
{
    int Height = 0;
    if(pRoot == NULL)
        return;
    TreeNode * pCurrent = pRoot;
    while(1)
    {
        //������������һֱ��Ҷ�ӽڵ�
        while(pCurrent != NULL)
        {
            // printf("%d ", pCurrent->Data);
            Push(pCurrent);
            pCurrent = pCurrent->pLeft;

            //* ��������ͨ�ã�
            Height ++;
            if(Height > Max_Height)
                Max_Height = Height;
            printf("%d ", Height);
        }
        if(StackTop == -1)
            break;
        TreeNode * pTemp = Pop();
        Height --;
        pCurrent = pTemp->pRight;
    }
    Max_Height ++;
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

    //! ʹ��ǰ��/����������������������ʱ�����뱣֤������Ϊƽ���������������Ҷ�Ӳ㣬�����㶼������
    // t7.pFather = &t5;
    // t8.pFather = &t5;
    // //* �˴����޸ģ�������Ϊ5
    // t9.pFather = &t6;
    // t9.pRight = &t10;
    // t10.pFather = &t9;

    // �Ĳ�
    t6.pRight = &t10;
    t7.pFather = &t5;
    t8.pFather = &t5;
    t9.pFather = &t6;
    t10.pFather = &t6;
    
    printf("�������: ");
    Look_1(&t1);
    printf("����������Ϊ%d\n", Max_Height);

    Max_Height = 0;

    printf("ǰ�����: ");
    Look_2(&t1);
    printf("����������Ϊ%d\n", Max_Height);
    return 0;
}
