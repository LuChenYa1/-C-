#include <stdio.h>
#include <malloc.h>

//* ͷ�����е�Ŀ����ȥ������ʱ��������Ǩ�ƵĹ���
//* ͷ��/β��ָ���ǳ���ʱ˭�ڶ�

//! ��β�ڽڵ����ʱ�����ƣ����ڵ����ʱλ�ò�����ͷ��������������� N ���ڵ㣬��β�ͻ������� N λ����˶��������Ԫ�ظ���ҲΪ N ��
//! β������ֻ��Ҫ�ɽڵ�������Ĳ����Ԫ�ظ�����������ʱ��Ҫ����ǰ�ƣ�����ʱ�任�ռ�
//! ������ʾ��ͷ�������ÿռ任ʱ�䣬�����Ԫ�ظ��������̵�ִ��ʱ��

typedef struct Node
{
    int Data;
    struct Node * pFather;
    struct Node * pLeft;
    struct Node * pRight;
}TreeNode;

//* ���ƶ���
#define Queue_Size 10 //* ����ÿ��Ľڵ�������������Ĳ�Ľڵ������Ϊ����������������ӹ��������ɵ����ڵ�����
TreeNode * Queue[Queue_Size];
int QueueHead = 0; 
int QueueEnd = -1;

void Push(TreeNode * Node)
{
    //����Ԫ�ؼ�һ
    QueueEnd ++;
    //�ڶ�β����Ԫ��
    Queue[QueueEnd] = Node;
}

TreeNode * Pop(void)
{
    //������Ԫ�أ��������
    if(QueueEnd < QueueHead)
        return NULL;
    //��¼��ͷ���������ӣ�
    TreeNode * pTemp = Queue[QueueHead];
    //��ͷ������һλ��������ԭ���Ķ�ͷ
    QueueHead ++;
    //����ԭ���Ķ�ͷ
    return pTemp;
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
        if(QueueEnd < QueueHead)
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

