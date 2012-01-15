#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
	char k[16];
	int sta,end;
	int row;
}key[3005];
char ig[52][12],tit[202][10005];
int ig_num = 0, tit_num = 0, key_num = 0;
bool cmp(node a, node b)//排序用的函数 
{
	if(strcmp(a.k,b.k)>0) return false;
	else if(strcmp(a.k,b.k)<0) return true;
	else
	{
		if(a.row==b.row)
			return a.sta<b.sta;
		else
			return a.row<b.row;
	}	
}
int fin_ig(char* s)
{
	for(int i = 0;i < ig_num;i++)
		if(strcmp(ig[i],s)==0) return 0;
	return 1;
}
void change()
{
	int i, len=strlen(tit[tit_num]);
	for(i = 0;i < len;i++)
	{
		if(tit[tit_num][i]==' ') continue;
		int j = 0;
		char str[16];
		while(tit[tit_num][i]!=' '&&i<len)
		{
			if(tit[tit_num][i]>='A' && tit[tit_num][i]<='Z')
				str[j++]=tit[tit_num][i]=tit[tit_num][i]-'A'+'a';
			else str[j++]=tit[tit_num][i];
			i++;
		}
		str[j]='\0';
		int f=fin_ig(str);
		if(f) 
		{
			int len=strlen(str);
			for(j=0;j<len;j++) str[j]+='A'-'a';
			strcpy(key[key_num].k,str);//puts();
			key[key_num].sta=i-len;
			key[key_num].end=i-1;
			key[key_num].row=tit_num;
			key_num++;
		}
	} 
}
int main()
{
//	freopen("data.txt","r",stdin);
	int i = 0;
	while(1)//输入ignore词 
	{
		gets(ig[ig_num]);
		if(strcmp(ig[ig_num],"::") == 0) break;
		ig_num++;
	}
	
	while(gets(tit[tit_num]) != NULL)//输入title 
	{//puts(str);
		change();
		tit_num++;
	}
	sort(key,key+key_num,cmp);//for(i=0;i<key_num;i++) puts(key[i].k);
	for(i = 0;i < key_num;i ++)
	{
		int j;
		for(j = 0;j < strlen(tit[key[i].row]);j++)
		{
			if(j==key[i].sta)
			{
				printf("%s",key[i].k);
				j+=key[i].end-key[i].sta;
			}
			else putchar(tit[key[i].row][j]);
		}
		putchar('\n');
	}
	return 0;
}