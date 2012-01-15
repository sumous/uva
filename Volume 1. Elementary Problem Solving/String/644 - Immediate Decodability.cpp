/**
* 644 - Immediate Decodability
*/

#include<stdio.h>
#include<string.h>
int main()
{
	char s[12][10], ch;
	//freopen("data.txt", "r", stdin);
	int i = 0, len[12], set = 1;
	while(scanf("%s",s[i]) != EOF)
	{
		
		while(s[i][0] != '9')//输入数据，直到不是结束标志时 
		{
			len[i] = strlen(s[i]);//记录下每行数据的长度 
			i++;
			scanf("%s",s[i]);
		}
		
		int j, k, flag = 1;
		for(j = 0;s[j+1][0] != '9';j ++)
		{
			//if(flag) break;
			int flag2 = j + 1;
			for(k = j + 1;s[k][0] != '9';k ++)
			{							
				int l;
				for(l = 0;l < len[j]&&l < len[k];l ++)
				{
					if(s[j][l] != s[k][l])
					{
						flag2 ++;
						break;
					}
				}
				
			}
			if(flag2 != k) 
			{
				printf("Set %d is not immediately decodable\n", set);
				flag = 0;
				break;
			}
		}
		if(flag == 1) printf("Set %d is immediately decodable\n", set;
	
		set++;
		i = 0;
	}
	return 0;
}