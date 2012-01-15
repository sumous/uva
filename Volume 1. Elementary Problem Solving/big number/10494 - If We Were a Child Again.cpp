#include<stdio.h>
#include<string.h>
#define MAX 1000000
char s[MAX];
void divide(char ch, long long n)
{
	long long len=(long long)strlen(s), rem, i;
	for(i = rem = 0;i < len;i ++)
	{
		rem = rem*10 + s[i] - '0';
		s[i] = rem/n+'0';
		rem%=n;
	}
	if(ch == '/')
	{
		for(i = 0;i < len&&s[i] == '0';i ++);
		if(i >= len)
			printf("0\n");
		else
	 		puts(s+i);
	}
	else
		printf("%lld\n", rem);
}

int main()
{
	char ch;
	
	long long n;
	while(scanf("%s %c %lld", s, &ch, &n) != EOF)
	{//printf("%s %c %lld\n", s, ch ,n);
		divide(ch ,n);
	}
	return 0;
}