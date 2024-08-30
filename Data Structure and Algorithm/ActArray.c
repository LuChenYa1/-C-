#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct ActArrayType
{
    unsigned int Capacity;//�ռ�����
    int * pArray;//malloc�ռ�ָ��
    unsigned int Number;//��������
};

void Struct_Init(struct ActArrayType * pStruct);//*�ṹ���ʼ��
void Ensure_EnoughCapacity(struct ActArrayType * pStruct);//* ȷ����̬����ռ���������
void Malloc_Add(struct ActArrayType * pStruct, int Data);//* ��̬��������Ԫ��
void Malloc_Insert(struct ActArrayType *pStruct, int Data, unsigned char Subscript);//* ��̬�������Ԫ��
void Malloc_Delete_End(struct ActArrayType *pStruct);//* ��̬����ɾ��ĩβԪ��
void Malloc_Delete_All(struct ActArrayType *pStruct);//* ��̬����ɾ��ȫ��Ԫ��
void Malloc_freeSpace(struct ActArrayType *pStruct);//* �ͷŵ�ǰ�Ķ�̬����
void Malloc_Delete(struct ActArrayType *pStruct, unsigned char Subscript);//* ɾ��ָ���±��Ԫ��
void Print_ActArray(struct ActArrayType *pStruct);//*��ӡ��̬������Ϣ

int main(void)
{
    struct ActArrayType ActArray;
    Struct_Init(&ActArray);

    Malloc_Add(&ActArray, 1);
    Malloc_Add(&ActArray, 2);
    Malloc_Add(&ActArray, 99935);
    Malloc_Add(&ActArray, 4);
    Malloc_Add(&ActArray, 5);
    Malloc_Add(&ActArray, 6);
    Malloc_Add(&ActArray, 7);
    Malloc_Insert(&ActArray, 3, 0);
    Malloc_Insert(&ActArray, 9, 10);

    //Print_ActArray(NULL);
    Print_ActArray(&ActArray);//���

    Malloc_Delete_End(&ActArray);
    Malloc_Delete_End(&ActArray);
    Malloc_Delete_All(&ActArray);
    Malloc_freeSpace(&ActArray);
    Print_ActArray(&ActArray);//�ٴ����

    Struct_Init(&ActArray);
    Malloc_Add(&ActArray, 1);
    Malloc_Add(&ActArray, 2);
    Malloc_Add(&ActArray, 4);
    Print_ActArray(&ActArray);//�ٴ����

    Malloc_Delete(&ActArray, 1);
    Print_ActArray(&ActArray);//�ٴ����

    free(ActArray.pArray);//*�ͷžɿռ�

    //!system("pause");����������Լ�����������
    return 0;
}

void Struct_Init(struct ActArrayType * pStruct)//*�ṹ���ʼ��
{
    pStruct->Capacity = 5;
    pStruct->pArray = (int *)malloc(sizeof(int) * 10);
    pStruct->Number = 0;
}

void Ensure_EnoughCapacity(struct ActArrayType * pStruct)//* ȷ��malloc�ռ���������
{
    if(NULL == pStruct)
    {
        fprintf(stderr, "��������\n"); // ʹ��stderr���������Ϣ
        return;//void���������ؿ�
    }
    
    if(pStruct->Capacity == pStruct->Number)//����������С�ڿռ�����
    {
        pStruct->Capacity += 5;//��������
        int *pTemp = (int *)malloc(sizeof(int) * pStruct->Capacity);//����ռ�
        for (int i = 0; i < pStruct->Number; i++)//ԭ������
        {
            pTemp[i] = pStruct->pArray[i];
        }
        free(pStruct->pArray);//*�ͷžɿռ�
        pStruct->pArray = pTemp;//��ָ��ָ���¿ռ��ַ
    }
}

void Malloc_Add(struct ActArrayType * pStruct, int Data)//*malloc��̬��������Ԫ��
{  
    if(NULL == pStruct)
    {
        fprintf(stderr, "��������\n"); // ʹ��stderr���������Ϣ
        return;//void���������ؿ�
    }

    Ensure_EnoughCapacity(pStruct);

    pStruct->pArray[pStruct->Number] = Data;//*����Ԫ�طŵ�������
    pStruct->Number ++;
}

void Malloc_Insert(struct ActArrayType *pStruct, int Data, unsigned char Subscript)//*malloc��̬�������Ԫ��
{
    if(NULL == pStruct)
    {
        fprintf(stderr, "��������\n"); // ʹ��stderr���������Ϣ
        return;//void���������ؿ�
    }

    Ensure_EnoughCapacity(pStruct);
    
    if(Subscript >= pStruct->Number) Subscript = pStruct->Number;//*�±����ʱ����������Ԫ��ĩβ

    for(unsigned int i = pStruct->Number; i > Subscript; i--)//*�Ӳ��봦����Ų������Ԫ������λ
    {
        pStruct->pArray[i] = pStruct->pArray[i - 1];
    }

    pStruct->pArray[Subscript] = Data;//���ݸ����±긳ֵ��ָ��λ��

    pStruct->Number ++;
}

void Malloc_Delete_End(struct ActArrayType *pStruct)//* malloc��̬����ɾ��ĩβԪ��
{
    if(NULL == pStruct)
    {
        fprintf(stderr, "��������\n"); // ʹ��stderr���������Ϣ
        return;
    }
    pStruct->Number --;
    //! ֻ��Ҫ��������һ��Ԫ��û��Ҫ���㣬����ͱ���ԭֵû����ϵͳֻ��Ԫ������
    // ����ɾ��Ԫ�غ����������������ƥ�䣬һ�㲻��Ҫ��������ռ䣬�������ٶ����������Ϊ����ʺ�����Ҫ������Ԫ��
}

void Malloc_Delete_All(struct ActArrayType *pStruct)//* malloc��̬����ɾ��ȫ��Ԫ��
{
    if(NULL == pStruct)
    {
        fprintf(stderr, "��������\n"); // ʹ��stderr���������Ϣ
        return;
    }
    pStruct->Number = 0;
}

void Malloc_freeSpace(struct ActArrayType *pStruct)// �ͷŵ�ǰ��malloc��̬����
{
    if(NULL == pStruct)
    {
        fprintf(stderr, "��������\n"); // ʹ��stderr���������Ϣ
        return;
    }
    pStruct->Number = 0;
    pStruct->Capacity = 0;
    free(pStruct->pArray);
    pStruct->pArray = NULL;
}

void Malloc_Delete(struct ActArrayType *pStruct, unsigned char Subscript)//* ɾ��ָ���±��Ԫ��
{
    if(NULL == pStruct)
    {
        fprintf(stderr, "��������\n"); // ʹ��stderr���������Ϣ
        return;
    }

    for(unsigned int i = Subscript; i < pStruct->Number - 1; i++)//* ��ɾ���㿪ʼ���������Ԫ��ǰ��
    {
        pStruct->pArray[i] = pStruct->pArray[i + 1];
    }
    pStruct->Number --;
}

void Print_ActArray(struct ActArrayType *pStruct)//*��ӡmalloc��̬������Ϣ
{
    if(NULL == pStruct)
    {
        fprintf(stderr, "��������\n"); // ʹ��stderr���������Ϣ
        return;
    }

    printf("Number:%d, Capacity:%d\n", pStruct->Number, pStruct->Capacity);
    printf("����Ԫ��:");
    for (size_t i = 0; i < pStruct->Number; i++)
    {
        // printf("%p\n", &(pStruct.pArray[i]));ָ��������int���ʼ�һ�ռ��ַǰ�����ֽ�
        printf("%d ", pStruct->pArray[i]);
    }
    printf("\n");
}

