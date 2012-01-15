/*488 - Triangle Wave*/
#include<stdio.h>
int main()
{
    int n, c, f, i, j;
    scanf("%d", &n);

    while(n --)
    {
        //getchar();
        scanf("%d", &c); //输入振幅
        scanf("%d", &f);//输入频率
        //printf("\n");
        while(f --)
        {
             for(i = 1;i <= c;i ++) //前一半
             {
                for(j = 1;j <= i;j ++)
                {
                    printf("%d", i);
                }
                printf("\n");
             }
             
             for(i = c - 1;i > 0;i --)//后一半
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
