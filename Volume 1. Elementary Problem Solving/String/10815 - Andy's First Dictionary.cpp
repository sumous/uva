#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
char s[100005][201];


int comp(const void *a,const void *b)//二维字符数组比较函数 
{
	return strcmp(((char *)a),((char *)b));
}

/**
**判断当前字符是否为字母
**/
int isalpha(char ch)
{
	if((ch >= 'a'&&ch <= 'z')||(ch >= 'A'&&ch <= 'Z'))
		return 1;
	return 0;
}


int main()
{
	char  ch;
	int len = 0, n = 0;
	//freopen("data.txt", "r", stdin);
	while(1)
    {
       if((ch=getchar())==EOF) break;
       if(isalpha(ch))
          s[n][len++]=tolower(ch);
       else
         if(isalpha(s[n][0])){ s[n++][len]='\0';len=0; }
    }
	
	qsort(s, n, sizeof(s[0]), comp ) ;
	int i = 0;
	for(;i < n;i++)
	{
		if(strcmp(s[i], s[i - 1]) == 0) continue;
 		printf("%s\n", s[i]);
	}
	return 0;
}