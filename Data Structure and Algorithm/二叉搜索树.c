#include <stdio.h>
#include <malloc.h>

//* �����������ص㣺
//*  ÿ�������ĸ��Ƿֽ�㣬���������Ǳȸ�С�ģ����������Ǳȸ���ģ����� < �� <= ��
//* �������߼�˳�������������ݵ�˳��Ҳ�������

//* �������ڵ㶨��
typedef struct TNode
{
    int Data;
    struct TNode * pFather;
    struct TNode * pLeft;
    struct TNode * pRight;
}TreeNode;

void Insert(TreeNode ** pRoot, int Data)
{
    // ����ڵ�ռ�
    TreeNode * pNewNode = (TreeNode *)malloc(sizeof(TreeNode));
    if(pNewNode == NULL)
        return;
    //��ֵ
    pNewNode->Data = Data;
    pNewNode->pFather = NULL;
    pNewNode->pLeft = NULL;
    pNewNode->pRight = NULL;
    //* ��Ϊ�գ��½ڵ�Ϊ���ڵ�
    if(*pRoot == NULL)
        *pRoot = pNewNode;
    
}

int main()
{
    TreeNode * pRoot = NULL;
    Insert(&pRoot, 12);

    return 0;
}
