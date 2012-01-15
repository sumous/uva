/*445 - Marvelous Mazes*/
#include<stdio.h>
#include<string.h>
int main()
{
    int i, j;
    char maze[140], ch;
    //freopen("data.txt", "r", stdin);
    while(gets(maze) != NULL)
    {
         for(i = 0;i <strlen(maze);i ++)
         {
            int count = 0;
              //if(maze[i] == 'b') printf(" ");
              
              if(maze[i] == '!') printf("\n");
              
              while(maze[i]>='0'&&maze[i]<='9')
              {
                  count += maze[i] - '0';
                  i ++;
              }
              if(maze[i] == 'b')
                  for(j = 0;j <count;j ++)
                  {
                      printf(" ");
                  }
              else
                  for(j = 0;j < count;j ++)
                  {
                      printf("%c", maze[i]);
                  }

         }
         printf("\n");
    }
    return 0;
}

