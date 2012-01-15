#include<stdio.h>
#include<string.h>
#define m 1001
int sec[m], gues[m][m];
bool  bsec[m],bgues[m];
int main()
{
	int n, set = 1;
	//freopen("data.txt","r", stdin);
	while(scanf("%d", &n)!=EOF && n != 0)
	{
		printf("Game %d:\n", set++);
		int  i, j , k, cas = 0;
		
		
		for(i = 0; i < n;i ++) scanf("%d", &sec[i]);
		
		while(true)	//输入猜想 
		{
			int flag = 0;
			for(j = 0;j < n;j ++)
				scanf("%d", &gues[cas][j]);

			if(gues[cas][0] == 0) break;//输入结束 
			cas++;
		}
		
		for(i = 0;i <= cas;i++)
		{
			memset(bgues, false, sizeof(bgues));
			memset(bsec, false, sizeof(bsec));
			int a = 0, b = 0;
			for(j = 0;j < n;j ++)//找出a并标记为访问过 
			{
				if(sec[j] == gues[i][j])
				{
					a++;
					bsec[j] = true;
					bgues[j] = true;
				}
	
			}
			for(j = 0;j < n;j ++)
			{
				if(bsec[j]) continue;
				for(k = 0;k < n;k ++)
				{
					if(bgues[k] || k == j) continue;
	
					if(sec[j] == gues[i][k])
					{
						b++;
						bgues[k] = true;
						break;
					}
				}
			}
			printf("    (%d,%d)\n", a, b);
		}
	}
	return 0;
}