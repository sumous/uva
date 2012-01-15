/*457 - Linear Cellular Automata
*/
#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, j, k;

    scanf("%d", &n);
    for(i = 0;i < n;i++)
    {
        int pre[50]={0}, cur[50] = {0}, temp, dic[10];
        cur[20] = 1;
        for(j = 0;j < 10;j ++)
        {
            scanf("%d", &dic[j]);

        }
        //print_pre(pre) ;
        for(j = 0;j < 50;j ++)
        {
            for(k = 1;k <= 40;k ++)
            {
                if(cur[k]==0) printf(" ");
                else if(cur[k]==1) printf(".");
                else if(cur[k]==2) printf("x");
                else printf("W");
            }
            printf("\n");
            memcpy(pre, cur, sizeof(pre));
            for(k = 1;k <= 40;k ++)
            {
                temp = pre[k] + pre[k-1] + pre[k+1];
                cur[k] = dic[temp];
            }
            //print_pre(cur);

        }
        if(i!=n-1) printf("\n");
    }
    return 0;
}
