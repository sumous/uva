/*490 - Rotating Sentences*/
#include<stdio.h>
#include<string.h>
char former[105][105];
int main()
{

    int i, j, row = 0, col = 0;

       memset(former[i],0,sizeof(former));
    while(gets(former[row]))
    {
        if(strlen(former[row]) > col) col = strlen(former[row]);
        row++;
    }
    row--;
     for(j=0;j<=col-1;j++)
     {
     for(i=row;i>=0;i--)
          if(former[i][j])printf("%c",former[i][j]);
          else putchar(' ');
      printf("\n");
      }
    return 0;
}
