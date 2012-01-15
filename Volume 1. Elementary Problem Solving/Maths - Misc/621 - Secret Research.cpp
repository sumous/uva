#include<stdio.h>
#include<string.h>
char s[1000];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		int len=strlen(s);
		if(len<3) printf("+\n");
		else if(s[len-1]=='5'&&s[len-2]=='3') printf("-\n");
		else if(s[len-1]=='4'&&s[0]=='9') printf("*\n");
		else printf("?\n");
	}
	return 0;
}
