/*10300 - Ecological Premium*/
#include<stdio.h>
int main()
{
    int n, f, i, j, a, b, c, sum;
    scanf("%d", &n);    //测试数据组数
    while(n--)
    {
        scanf("%d", &f);
        sum = 0;
        while(f--)
        {
            scanf("%d %d %d", &a, &b, &c);
            sum += a*c;
        }
        printf("%d\n", sum);
    }
    return 0;
}
