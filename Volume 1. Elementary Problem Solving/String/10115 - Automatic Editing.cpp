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
		sprintf(str, "%.*s", ld, s+i);//����ǰλ�ú�ld���ַ���ֵ��str 
		str[i+ld] = '\0';	
		
		if(strcmp(str, dic) == 0) 
		{	
			sprintf(str, "%.*s", i, s);//����ǰλ��֮ǰ��i���ַ���ֵ��str			
			strcat(str, rule);//��strβ�����ϻ����rule
			/*s�������ַ���ֵ��str��Ȼ���ڰ�str���Ƹ�s�������м�dic�ɹ�*/ 
			for(k = i+lr, j = i + ld;j < ls;k ++,j ++)
				str[k] = s[j];
			str[k] = '\0';
					
			strcpy(s, str);
			ls = strlen(s);//����֮�󣬵ö�ls�����޸� 
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
	
		for(i = 0;i < n;i ++)//�Զ��༭ 
			rule_place(s, dic[i], rule[i]);
					
		puts(s);
	}
	return 0;
}