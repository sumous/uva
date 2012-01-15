/**
**10361-Automatic Poetry
**/
#include<stdio.h>
int main()
{
	char s[6][100], ch;
	int n, i, j;
	//freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	
	while(n --)
	{
		getchar();
		ch = getchar();
		i = 0;
		while(ch != '<')//输入s1 
		{
			s[0][i] = ch;
			ch = getchar();
			i ++;
		}
		s[0][i] = '\0';
		
		ch = getchar();
		i = 0;
		while(ch != '>')//输入s2 
		{
			s[1][i] = ch;
			ch = getchar();
			i ++;
		}
		s[1][i] = '\0';
		
		ch = getchar();
		i = 0;
		while(ch != '<')//输入s3
		{
			s[2][i] = ch;
			ch = getchar();
			i ++;
		}
		s[2][i] = '\0';
		
		ch = getchar();
		i = 0;
		while(ch != '>')//输入s4
		{
			s[3][i] = ch;
			ch = getchar();
			i ++;
		}
		s[3][i] = '\0';
		
		ch = getchar();
		i = 0;
		while(ch != '\n')//输入s3
		{
			s[4][i] = ch;
			ch = getchar();
			i ++;
		}
		s[4][i] = '\0';
		
		ch = getchar();
		i = 0;
		while(ch != '.')//输入第二行数据 
		{
			s[5][i] = ch;
			ch = getchar();
			i ++;
		}
		s[5][i] = '\0';
		
		getchar();
		getchar();
		for(i = 0;i < 5;i ++)
			printf("%s", s[i]);
		printf("\n%s%s%s%s%s\n", s[5], s[3], s[2], s[1], s[4]);
	}
	//fclose(stdin);
	return 0;
}