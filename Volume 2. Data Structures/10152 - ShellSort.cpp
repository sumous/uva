#include<stdio.h>
#include<string.h>
char s[210][105],st[105];
int a[210],n, at;
void search()
{
	for(int i = 0;i < n;i++)
	{
		if(strcmp(st,s[i])==0) {a[at++]=i;return;}
	}
}
int main()
{
//	freopen("data.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		at=0;
		scanf("%d\n",&n);
	//	getchar();
		for(int i = 0;i < n;i++) gets(s[i]);
		for(int i = 0 ;i < n;i++)
		{
			gets(st);
			search();
		}
		for(n-=2;n>=0;n--) if(a[n+1]<a[n]) break;
		for(;n>=0;n--) puts(s[a[n]]);
		putchar('\n');
	}
	return 0;
}