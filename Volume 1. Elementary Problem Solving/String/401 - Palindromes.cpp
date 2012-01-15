#include<stdio.h>
#include<string.h>
//char one[40] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
char rev[40]="A   3 HIL JM O   2TUVWXY51SE Z 8 ";

char transform(char ch)
{
     if(ch=='0') return 'O';
    if(ch <= '9') return rev[ch-'1'+26] ;
    else return rev[ch-'A'];
}

int is_mirrored(char* s, int n) //判断是否为mirrored string
{
    int i;
    for(i = 0, n -= 1;i < n;i++, n--)
    {

        /*判断是否是在reverse 序列里*/

        if(transform(s[i]) == '\0'||transform(s[n]) == '\0') return 0;
        else
        {
            if(s[i]==transform(s[n])||transform(s[i])==s[n]) continue;
            else return 0;
        }

    }
    return 1;
}



int is_palind(char* s, int n)//判断是否为regular palindrome
{
    int  i ;
    for(i = 0, n -= 1;i < n;i++, n--)
    {
        if(s[i] != s[n]) return 0;
    }
    return 1;
}

int main()
{
    char s[25];
    int  n;
    freopen("data.txt", "r", stdin);
    while(gets(s) != NULL)
    {
        n = strlen(s);
        int a = is_palind(s, n), b = is_mirrored(s, n);
        if(a&&b)
         printf("%s -- is a mirrored palindrome.\n",s);
       else if(a)
         printf("%s -- is a regular palindrome.\n",s);
       else if(b)
         printf("%s -- is a mirrored string.\n",s);
       else
         printf("%s -- is not a palindrome.\n",s);
       putchar('\n');


       /* if(a&&b)
            printf("%s -- is a mirrored palindrome.\n",s);
        else if(a&&!b)
            printf("%s -- is a regular palindrome.\n", s);
        else if(!a&&b)
            printf("%s -- is a mirrored string.\n", s);
        else
            printf("%s -- is not a palindrome.\n", s);
        printf("\n"); */
    }
    return 0;
}
