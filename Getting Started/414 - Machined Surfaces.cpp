/*414 - Machined Surfaces */

#include<stdio.h>

int main()
{
    int max_len,  n, i, j, k, B;
    char ch;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &n);

    for(j = 0;n != 0;j ++) //输入不为0时
    {
        //getchar();
        int x[15] = {0};
        B = 0;
        max_len = 0;
        for(k = 0;k < n;k ++)
        {
            for(i = 0;i < 25;i ++)
            {
                ch = getchar();
                if(ch == 'X') x[k]++;
            }
            if(x[k] > max_len) max_len = x[k];
            //printf("%d\n", x[k]);
            getchar();
        }
        
        for(k = 0;k < n;k ++)
            B += (max_len - x[k]);

        printf("%d\n", B);
        scanf("%d", &n);
    }
    
    
    return 0;
}
