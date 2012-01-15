#include<stdio.h>
#include<string.h>
int main()
{
	freopen("data.txt","r",stdin);
	char s[35];
	while(gets(s)!=NULL)
	{
		if(s[0]=='0') break;
		long pow=2, res=0;
		for(int i = strlen(s)-1;i>=0;i--)
		{
			res+=(s[i]-'0')*(pow-1);
			pow*=2;
		}
		printf("%ld\n",res);
	}
	return 0;
}