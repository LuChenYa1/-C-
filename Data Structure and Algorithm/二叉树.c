#include <stdio.h>
#include <malloc.h>

//! �������ṹ�����ڵ㡢Ҷ�ӽڵ㡢�ֵܽڵ㡢ǰ���ڵ㡢�����ڵ㡢��������������
//! ǰ������������������������������ҡ�����ҡ����Ҹ�


typedef struct Node
{ 
    int Data;
    struct Node * pFather;
    struct Node * pLeft;
    struct Node * pRight;
}TreeNode;

TreeNode * CreateTreeNode(int Data);//* ����һ���������ڵ�

 
int main(void)
{
    
    return 0;
}

TreeNode * CreateTreeNode(int Data)//* ����һ���������ڵ�
{
    //����ڵ�ռ�
    TreeNode * pNewNode = (TreeNode *)malloc(sizeof(TreeNode));
    if(pNewNode == NULL)
        return NULL;
    //�ڵ��Ա�Ǹ�ֵ
    pNewNode->Data = Data;
    pNewNode->pFather = NULL;
    pNewNode->pLeft = NULL;
    pNewNode->pRight = NULL;
    //���ؽڵ��ַ
    return pNewNode;
}
