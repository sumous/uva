/**
**537 - Artificial Intelligence?
**/
#include<stdio.h>
double find_plo(char ch)//找出对应的前缀 
{
	if(ch == 'm') return 0.001;
	
	if(ch == 'k') return 1000;
	
	if(ch == 'M') return 1000000;
	
	return 1;
}

int main()
{
	freopen("data.txt", "r", stdin);
	double P, U, I;
	char ch, s[100];
	int flag, n, i;
	scanf("%d", &n);
	getchar();
	for( i = 1;i <= n;i ++)
	{
		P = 0.0;U = 0.0;I = 0.0;
		
		while(1)
		{
			ch = getchar();
			//putchar(ch);
			if(ch == '\n') break;
			if(ch == 'P')
			{
				ch = getchar();
				if(ch == '=')
				{
					scanf("%lf", &P);
					ch = getchar();
					P *= find_plo(ch);	
				}
			}
			
			if(ch == 'U')
			{
				ch = getchar();
				if(ch == '=')
				{
					scanf("%lf", &U);
					ch = getchar();
					U *= find_plo(ch);
				}		
			}
			
			if(ch == 'I')
			{
				ch = getchar();
				if(ch == '=')
				{
					scanf("%lf", &I);
					ch = getchar();
					I *= find_plo(ch);
				}
			}
			
		
			
			
		}
		printf("Problem #%d\n", i);
		if(I == 0.0)
		{
			printf("I=%.2lfA\n", P/U);
		}
		else if(U == 0.0)
		{
			printf("U=%.2lfV\n", P/I);
		}
		else printf("P=%.2lfW\n", U*I);
		printf("\n");
	}
	return 0;
}