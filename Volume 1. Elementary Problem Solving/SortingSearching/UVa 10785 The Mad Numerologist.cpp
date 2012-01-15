#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const char s[]="AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIR";
bool cmp(char a, char b)
{
	return a<b;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		char res[212];
		char v[106],c[106];
		int k = 0;
		for(int j = 1; j < n;j +=2)
			c[k++]=s[j];
		c[k]='0';
		sort(c, c+k, cmp);
		k=0;
		for(int j = 0; j < n;j +=2)
			v[k++]=s[j];
		v[k]='\0';
		sort(v, v+k, cmp);
		k=0;
		for(int j = 1; j<n;j+=2) res[j]=c[k++];
		k=0;
		for(int j = 0; j<n;j+=2) res[j]=v[k++];
		res[n]='\0';
		printf("Case %d: %s\n",i,res);
	}
	return 0;
}
