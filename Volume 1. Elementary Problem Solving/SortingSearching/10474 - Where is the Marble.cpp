#include<stdio.h>
#include<stdlib.h>
#define max 10005
int cmp(const void *a,const void *b)//一维整数数组比较函数 
{
	return *(int *)a > *(int *)b;//转换成（int *）类型后取值比较 
}

int main()
{
	int n,q, cas = 1;
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d", &n, &q) && n!=0 && q!=0)
	{
		int i, j;
		int a[max];
		printf("CASE# %d:\n", cas++);
		for(i = 0;i < n;i ++) scanf("%d", &a[i]);
		
		qsort(a, n, sizeof(int), cmp);//printf("test");
		for(i = 0;i < q;i ++)
		{
			int cur;
			bool flag = true;
			scanf("%d", &cur);
			for(j = 0;j < n;j ++)
			{
				if(cur == a[j])
				{
					printf("%d found at %d\n", cur, j+1);
					flag = false;
					break;
				}
				
			}
			if(flag) printf("%d not found\n", cur);
		}
	}
	return 0;
}