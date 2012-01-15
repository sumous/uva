/**
*  409 - Excuses, Excuses!
*/

#include<stdio.h>
#include<string.h>
char key[21][20], exc[21][71];
int K, E;
int case1 = 1;
/**
**判断当前字符是否为字母
**/
int isalpha(char ch)
{
	if((ch >= 'a'&&ch <= 'z')||(ch >= 'A'&&ch <= 'Z'))
		return 1;
	return 0;
}

/**
**判断当前位置是否和key相等 
**cur_exc是第cur_exc个借口,cur_key是第cur_key个关键词,exc_place当前借口的位置 
**/
int is_cur(int cur_exc,  int cur_key,int exc_place)
{
	int i;
	for(i = 0;i < strlen(key[cur_key]);i ++)
	{
		int flag = (key[cur_key][i] == exc[cur_exc][i+exc_place])||(key[cur_key][i] == exc[cur_exc][i+exc_place]-'A'+'a');
		if(flag == 0) return 0;
	}
	/**
	* 其后必须不是字母，这样可以排除单词在另外一个单词里的情况 
	*/
	if(isalpha(exc[cur_exc][i+exc_place]))
		return 0;
	else return 1;
}

int main()
{
	//freopen("data.txt", "r", stdin);

	while(scanf("%d%d", &K, &E) == 2)
	{
		int i, j, k, max = 0, times[21] = {0};
		getchar();
		
		/**
		*输入关键词key 
		*/
		for(i = 0;i < K;i ++) gets(key[i]);
		
		/**
		*输入借口exc,并计算出其包含的关键词个数 
		*/
		for(i = 0;i < E;i ++) 
		{
			gets(exc[i]);
			/**
			* 先判断第一个 
			*/
			if(isalpha(exc[i][0]))
				for(k = 0;k < K;k ++)
				{
					if(is_cur(i, k, 0))
					{
						times[i] ++;
					}
				}
			/**
			* 接着判断 
			*/
			for(j = 1;j < strlen(exc[i]);j ++)
			{
				/**
				*  当前位置不是字母且下一个是字母时进行判断 
				*/
				if(!isalpha(exc[i][j])&&isalpha(exc[i][j+1]))
				{
					j ++;
					for(k = 0;k < K;k ++)
					{
						if(is_cur(i, k, j))
						{
							times[i] ++;
							j +=  strlen(key[k]) - 1;//加上当前长度，节约时间 
							break;
						}
					}
				}
			}
			if(times[i]>max) max = times[i];
		}
		

		printf("Excuse Set #%d\n", case1);
		for(i = 0;i < E;i ++)
		{
			if(times[i] == max )
			{			
				puts(exc[i]);			
			}
			
		}
		putchar('\n');
		case1 ++;
	}
	return 0;
}