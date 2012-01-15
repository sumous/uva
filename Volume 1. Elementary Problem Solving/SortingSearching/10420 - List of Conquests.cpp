#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define m 2005
using namespace std; 
int cmp(const void *a,const void *b)//二维字符数组比较函数 
{
	return strcmp(((char *)a),((char *)b));
}
int main()
{
	//freopen("data.txt","r", stdin);
	char coun[m][76], lit[75];
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i ++)
	{
		scanf("%s", coun[i]);
		//puts(coun[i]);
		gets(lit);
	}
	qsort(coun, n, sizeof(coun[0]), cmp);
	for(int i = 0;i < n;i ++)
	{
		printf("%s ", coun[i]);
		int count = 1, j;
		for(j = i+1;j < n;j ++)
		{
			if(strcmp(coun[i],coun[j]) == 0) count++;
			else break;
		}
		i = j-1;
		printf("%d\n", count);
	}
	return 0; 
} 