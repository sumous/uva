/**
*  10878 - Decode the tape
*/
#include<stdio.h>
#include<string.h>
 const int exp[11] = {0, 128, 64, 32, 16, 8, 0, 4, 2, 1};
 
int main()
{
	char  code[20];
	int j = 0;
	//freopen("data.txt","r",stdin);
	
	while(gets(code))
	{
		if(code[0] != '|') continue;
		int i, asc = 0;
		for(i = 1;i < strlen(code)-1 ;i ++)
		{
			if(code[i] == '.') continue;
			if(code[i] == 'o')
			{
				asc += exp[i];

			}

		}
		
	printf("%c", asc);
	}
	
	return 0;
}
