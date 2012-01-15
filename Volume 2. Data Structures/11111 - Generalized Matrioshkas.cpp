#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 5000
struct Matrio
{
	int size_,sur;
};
Matrio st[M]={0};
int n,a[M];

bool Box()
{
	memset(st,0,sizeof(st));
	int top=0;
	for(int i = 0;i < n;i++)
	{
		 if(a[i]<0)
        {
           st[top].sur-=a[i];
           st[++top].size_=a[i];
        }
        else
        {
           if(-st[top].size_!=a[i]) return false;
           if(st[top].sur>=a[i]) return false;
           st[top--].sur=0;
        }

	}
	return true;
}
int main()
{
	char ch;
	n=0;
//	freopen("data.txt","r",stdin);
	while(scanf("%d%c",&a[n++],&ch)!=EOF)
	{
		if(ch=='\n')
		{
			if(n&1){puts(":-( Try again.");n=0;continue;}
			if(Box()) puts(":-) Matrioshka!");
			else puts(":-( Try again.");
			n=0;
		}
	}
	return 0;
}