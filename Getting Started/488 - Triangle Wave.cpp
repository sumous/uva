/*488 - Triangle Wave*/
#include<stdio.h>
int main()
{
    int n, c, f, i, j;
    scanf("%d", &n);

    while(n --)
    {
        //getchar();
        scanf("%d", &c); //�������
        scanf("%d", &f);//����Ƶ��
        //printf("\n");
        while(f --)
        {
             for(i = 1;i <= c;i ++) //ǰһ��
             {
                for(j = 1;j <= i;j ++)
                {
                    printf("%d", i);
                }
                printf("\n");
             }
             
             for(i = c - 1;i > 0;i --)//��һ��
             {
                for(j = 1;j <= i;j ++)
                {
                    printf("%d", i);
                }
                printf("\n");
             }
             if(f||n) printf("\n");
        }
    }
    return 0;
}
