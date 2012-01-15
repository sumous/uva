#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const char head[]="------------------------------------------------------------";
int cmp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
int main()
{
//	freopen("data.txt","r",stdin);
	int n;
	char str[105][65];
	while(scanf("%d",&n) != EOF)
	{
		
		puts(head);
		int i, j, max = 0, len[105];
		for(i = 0;i < n;i ++)
	 	{
			 scanf("%s", str[i]);
			 len[i]=strlen(str[i]);
			 if(len[i]>max) max=len[i];
	 	}
	 	max+=2;
 	 	int R=60>max?60:max;
	 	int col=R/max;//printf("t%d",col);
	 	int row=(n+col-1)/col;
	 //	printf("%d %d\n",max,num);
		qsort(str, n, sizeof(str[0]),cmp);
	//	for(i = 0;i < n;i ++) puts(str[i]);
		for(i = 0;i < row;i ++)
		{
			for(j = 0;j < col;j ++)
			{
				int cur = j*row+i;
				if(cur<n)
				{
					printf("%s",str[cur]);
					for(int k = len[cur];k < max;k++)
						putchar(' ');
					
				}
				
			}
			printf("\n");
		}
	}
	return 0;
}