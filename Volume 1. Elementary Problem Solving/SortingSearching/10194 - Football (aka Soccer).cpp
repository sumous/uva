#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct team
{
	char name[35];
	int b,c,d,e,f,g,h;
}t[35];
bool cmp(struct team a1, struct team a2)
{
	if(a1.b>a2.b) return true;
	if(a1.b<a2.b) return false;
	if(a1.d>a2.d) return true;
	if(a1.d<a2.d) return false;
	if(a1.g>a2.g) return true;
	if(a1.g<a2.g) return false;
	if(a1.h>a2.h) return true;
	if(a1.h<a2.h) return false;
	if(a1.c<a2.c) return true;
	if(a1.c>a2.c) return false;
	for(int i = 0;i < 35;i++)
	{
		char c1=a1.name[i],c2=a2.name[i];
		if(c1>='A'&&c1<='Z') c1=c1-'A'+'a';
		if(c2>='A'&&c2<='Z') c2=c2-'A'+'a';
		if(c1<c2) return true;
		if(c1>c2) return false;
	}
	return false;
}

int main()
{
//	freopen("data.txt","r", stdin);
	int T;
	char rou[105];
	char s1[35],s2[35], s[80];
	scanf("%d", &T);getchar();
	while(T--)
	{		
		gets(rou);
		puts(rou);
		int n;
		scanf("%d", &n);
		getchar();
		for(int i = 0;i < n;i ++)//输入队名 
		{
			gets(t[i].name);
			t[i].b=t[i].c=t[i].d=t[i].e=t[i].f=t[i].g=t[i].h=0;
		}
		int n0, p1, p2;
		
		scanf("%d",&n0);
		getchar();
		while(n0--)//输入每个回合，并统计 
		{
			gets(s);
			int len=strlen(s);
			s[len]='\0';
			int j = 0, i = 0;
			while(s[i]!='#')
				s1[j++]=s[i++];
			s1[j]='\0';
			if(s[i+2]!='@'){ p1=(s[i+1]-'0')*10+s[i+2]-'0';i+=4;}
			else {p1=s[i+1]-'0';i+=3;}
			
			if(s[i+1]!='#'){ p2=(s[i]-'0')*10+s[i+1]-'0';i+=3;}
			else {p2=s[i]-'0';i+=2;}
			j=0;
			while(i<len)
				s2[j++]=s[i++];
			s2[j]='\0';
							
			if(p1>p2)
			{
				for(int i = 0;i < n;i ++)
				{
					if(strcmp(s1,t[i].name)==0)//赢家 
					{
						t[i].b+=3;t[i].c++;t[i].d++;t[i].g+=p1-p2;t[i].h+=p1;
					}
					if(strcmp(s2,t[i].name)==0)//输 
					{
						t[i].c++;t[i].f++;t[i].g+=p2-p1;t[i].h+=p2;
					}
				}
			}
			else if(p1<p2)
			{
				for(int i = 0;i < n;i ++)
				{
					if(strcmp(s2,t[i].name)==0)//赢家 
					{
						t[i].b+=3;t[i].c++;t[i].d++;t[i].g+=p2-p1;t[i].h+=p2;
					}
					if(strcmp(s1,t[i].name)==0)//输 
					{
						t[i].c++;t[i].f++;t[i].g+=p1-p2;t[i].h+=p1;
					}
				}
			}
			else
			{
				for(int i = 0;i < n;i ++)
				{
					if(strcmp(s1,t[i].name)==0)
					{
						t[i].b+=1;t[i].c++;t[i].e++;t[i].h+=p1;
					}
					if(strcmp(s2,t[i].name)==0)
					{
						t[i].b+=1;t[i].c++;t[i].e++;t[i].h+=p2;
					}
				}
			}
		}
		sort(t,t+n,cmp);
		for(int i = 0;i < n;i ++)//输出数据 
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,t[i].name,t[i].b,t[i].c,t[i].d,t[i].e,t[i].f,t[i].g,t[i].h,t[i].h-t[i].g);
		if(T!=0) putchar('\n');
	}
	return 0;
}