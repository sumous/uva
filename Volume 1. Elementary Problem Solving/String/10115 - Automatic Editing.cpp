/**
* 10115 - Automatic Editing
**/
#include<stdio.h>
#include<string.h>

void rule_place(char* s,char* dic, char* rule)
{	
	int i, j, k;
	int ls = strlen(s), ld = strlen(dic), lr = strlen(rule);
	for(i = 0;i <= ls - ld;i ++)
	{
		char str[257];
		sprintf(str, "%.*s", ld, s+i);//将当前位置后ld个字符赋值给str 
		str[i+ld] = '\0';	
		
		if(strcmp(str, dic) == 0) 
		{	
			sprintf(str, "%.*s", i, s);//将当前位置之前的i个字符赋值给str			
			strcat(str, rule);//在str尾部添上换后的rule
			/*s中其余字符赋值给str，然后在把str复制给s，调换中间dic成功*/ 
			for(k = i+lr, j = i + ld;j < ls;k ++,j ++)
				str[k] = s[j];
			str[k] = '\0';
					
			strcpy(s, str);
			ls = strlen(s);//完了之后，得对ls进行修改 
			i--;
		}
	}
}

int main()
{
	int n;
	//freopen("data.txt", "r", stdin);
	while(scanf("%d", &n)&&n != 0)
	{
		char dic[11][81], rule[11][81], s[257];
		int i;
		getchar();
		for(i = 0;i < n;i ++)
		{
			gets(dic[i]);
			gets(rule[i]);
		}
		
		gets(s);
	
		for(i = 0;i < n;i ++)//自动编辑 
			rule_place(s, dic[i], rule[i]);
					
		puts(s);
	}
	return 0;
}