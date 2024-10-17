#include <stdio.h>
#include <malloc.h>


typedef struct TNode
{
    int Data;
    struct TNode * pFather;
    struct TNode * pLeft;
    struct TNode * pRight;
}TreeNode;

int Max_Number;

//* ����ջ
#define Deep 5
TreeNode * Stack[Deep];
int StackTop = -1;//��ʼû�����ݣ�ջ���±�ָ��-1

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

void GetLayers(TreeNode * pLeaf)
{
    //* �����ǰ�����Ľڵ���Ҷ�ӽڵ㣬��ʼ����ڵ㷴�ƣ��ۼӲ���
    if(pLeaf->pLeft == NULL && pLeaf->pRight == NULL)
    {
        int Branch_Number = 0;
        while(pLeaf)
        {
            Branch_Number ++;
            pLeaf = pLeaf->pFather;
        }
        printf("%d ", Branch_Number);
        if(Branch_Number > Max_Number)
            Max_Number = Branch_Number;
    }
}

//* �ݹ�ʵ��
void Look_1(TreeNode * pRoot)
{   
    if(pRoot == NULL)
        return;
    //* ���㵱ǰҶ�ӽڵ�Ĳ����������Ҷ�ӽڵ㣩
    GetLayers(pRoot);
    Look_1(pRoot->pLeft);
    Look_1(pRoot->pRight);
}

//* �ǵݹ�ʵ��
void Look_2(TreeNode * pRoot)
{   
    if(pRoot == NULL)
        return;
    while(1)
    {
        while(pRoot)//* ��������ջ
        {
            Push(pRoot);
            pRoot = pRoot->pLeft;
        }
        //* ���������һ���ڵ�
        if(StackTop == -1)
            break;
        //* ȡ�������ջ�Ľڵ�
        pRoot =  Pop();
        //* ���㵱ǰҶ�ӽڵ�Ĳ����������Ҷ�ӽڵ㣩
        GetLayers(pRoot);
        //* ת��������
        pRoot = pRoot->pRight;
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

    t7.pFather = &t5;
    t8.pFather = &t5;
    //* �˴����޸ģ�������Ϊ5
    t9.pFather = &t6;
    t9.pRight = &t10;

    t10.pFather = &t9;

    Look_1(&t1);
    printf("�ݹ鷨����������ĸ߶�Ϊ %d \n", Max_Number);
    Look_2(&t1);
    printf("�ǵݹ鷨����������ĸ߶�Ϊ %d \n", Max_Number);

    return 0;
} 
