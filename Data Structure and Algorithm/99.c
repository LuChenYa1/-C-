#include <stdio.h>
#include <stdio.h>

int main(void)
{
    //* ��ӡ���½ǳ˷���
    for(unsigned char i = 1; i < 10; i++)
    {
        for(unsigned char j = 1; j <=i; j++)
        {
            printf("%dx%d=%2d ", j, i, i*j);
        }
        printf("\n");
    }

    //* ��ӡ���Ͻǳ˷���
    for(unsigned char i = 9; i > 0; i--)
    {
        for(unsigned char j = 1; j <=i; j++)
        {
            printf("%dx%d=%2d ", j, i, i*j);
        }
        printf("\n");
    }

    //* ��ӡ���Ͻǳ˷���
    for(unsigned char i = 1; i < 10; i++)
    {
        for(unsigned char j = 1; j <=9; j++)
        {
            if(j >= i) printf("%dx%d=%2d ", j, i, i*j);
            else printf("       "); 
        }
        printf("\n");
    }

    //* ��ӡ���½ǳ˷���
    for(unsigned char i = 9; i > 0; i--)
    {
        for(unsigned char j = 1; j <=9; j++)
        {
            if(j >= i) printf("%dx%d=%2d ", j, i, i*j);
            else printf("       ");
        }
        printf("\n");
    }
    return 0;
}

