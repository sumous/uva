/*489 - Hangman Judge*/
#include<stdio.h>
#include<string.h>

/*int is_exist(char* ans, char puz ,int n)
{
    int i, count = 0;
    for(i = 0;i < n;i ++)
    {
         if(puz == ans[i]) count++;
    }
    if(count != 0) return count;
    else return 0;
}  */
int main()
{
    int  round, i ;
    scanf("%d", &round);
    while(round != -1)
    {

        char puz, ans[1000];
        int fail = 0, in = 0, is_log[27];
        memset(is_log, 0, 27*sizeof(int));
        scanf("%s", ans);
        //puts(ans);
        getchar();
        puz = getchar();
        
        while(puz != '\n')
        {
            //putchar(puz);
            int temp = 0;
            if(is_log[puz-'a'])
            {
                puz = getchar();
                continue;
            }
            is_log[puz-'a']=1;
            //temp = is_exist(ans,puz,strlen(ans));
             for(i = 0;i < strlen(ans);i ++)
            {
                if(puz == ans[i]) temp++;
            }
            if(temp == 0) fail++;
            else in += temp;
            //if(in == strlen(ans)||fail>=7) break;
            puz = getchar();

        }
        printf("Round %d\n", round);
        if(in == strlen(ans))
        {
            printf("You win.\n");
        }
        else if(fail >= 7) printf("You lose.\n");
        else printf("You chickened out.\n");

        scanf("%d", &round);
          getchar();
       // printf("%d", round);
    }
    return 0;
}
