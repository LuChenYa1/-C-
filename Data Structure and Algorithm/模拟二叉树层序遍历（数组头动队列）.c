#include <stdio.h>
#include <malloc.h>

//* 头动队列的目的是去掉出队时整体数据迁移的过程
//* 头动/尾动指的是出队时谁在动

//! 队尾在节点入队时往后移，但节点出队时位置不动（头动），所以如果有 N 个节点，队尾就会往后移 N 位，因此队列数组的元素个数也为 N 个
//! 尾动队列只需要由节点个数最多的层决定元素个数，但出队时需要整体前移，其用时间换空间
//! 本节演示的头动队列用空间换时间，更多的元素个数，更短的执行时间

typedef struct Node
{
    int Data;
    struct Node * pFather;
    struct Node * pLeft;
    struct Node * pRight;
}TreeNode;

//* 非移动型
#define Queue_Size 10 //* 计算每层的节点个数，个数最多的层的节点个数即为队列在整个出队入队过程中容纳的最多节点数量
TreeNode * Queue[Queue_Size];
int QueueHead = 0; 
int QueueEnd = -1;

void Push(TreeNode * Node)
{
    //队列元素加一
    QueueEnd ++;
    //在队尾加入元素
    Queue[QueueEnd] = Node;
}

TreeNode * Pop(void)
{
    //队中无元素，无需出队
    if(QueueEnd < QueueHead)
        return NULL;
    //记录队头（即将出队）
    TreeNode * pTemp = Queue[QueueHead];
    //队头往后移一位，舍弃了原来的队头
    QueueHead ++;
    //返回原来的队头
    return pTemp;
}

void Look(TreeNode * pRoot)
{
    //防止空二叉树
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
        //* 出队时伴随着下一层节点入队，所以只有下一层没有节点即本层为最后一层时，本层节点全部出队后队列空了，此时二叉树层序遍历结束
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

