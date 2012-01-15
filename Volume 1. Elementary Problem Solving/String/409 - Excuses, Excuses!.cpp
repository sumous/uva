/**
*  409 - Excuses, Excuses!
*/

#include<stdio.h>
#include<string.h>
char key[21][20], exc[21][71];
int K, E;
int case1 = 1;
/**
**�жϵ�ǰ�ַ��Ƿ�Ϊ��ĸ
**/
int isalpha(char ch)
{
	if((ch >= 'a'&&ch <= 'z')||(ch >= 'A'&&ch <= 'Z'))
		return 1;
	return 0;
}

/**
**�жϵ�ǰλ���Ƿ��key��� 
**cur_exc�ǵ�cur_exc�����,cur_key�ǵ�cur_key���ؼ���,exc_place��ǰ��ڵ�λ�� 
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
	* �����벻����ĸ�����������ų�����������һ������������ 
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
		*����ؼ���key 
		*/
		for(i = 0;i < K;i ++) gets(key[i]);
		
		/**
		*������exc,�������������Ĺؼ��ʸ��� 
		*/
		for(i = 0;i < E;i ++) 
		{
			gets(exc[i]);
			/**
			* ���жϵ�һ�� 
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
			* �����ж� 
			*/
			for(j = 1;j < strlen(exc[i]);j ++)
			{
				/**
				*  ��ǰλ�ò�����ĸ����һ������ĸʱ�����ж� 
				*/
				if(!isalpha(exc[i][j])&&isalpha(exc[i][j+1]))
				{
					j ++;
					for(k = 0;k < K;k ++)
					{
						if(is_cur(i, k, j))
						{
							times[i] ++;
							j +=  strlen(key[k]) - 1;//���ϵ�ǰ���ȣ���Լʱ�� 
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