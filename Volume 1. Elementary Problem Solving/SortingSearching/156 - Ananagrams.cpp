#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1001][21];
char alp_s[1001][21];
char res[1001][21];
bool is_ana[1001];
int len=0;
int cmp(const void *a, const void *b)//�ȽϺ��� 
{
	return (*(char *)a)>(*(char *)b);
}
int cmp_str(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
void low_cas()//ת��ΪСд��������������alp_s��,�Ҷ�ÿ���ʽ������� 
{
	int i , j;
	for( i = 0;i < len;i++)
	{
		int len1=strlen(s[i]);
		for(j = 0; j < len1;j++)
		{
			if(s[i][j]>='A'&&s[i][j]<='Z') alp_s[i][j]=s[i][j]-'A'+'a';
			else alp_s[i][j]=s[i][j];
		}
		alp_s[i][j]='\0';
		qsort(alp_s[i], len1, sizeof(alp_s[i][0]),cmp);
	}
}

void find_ana()//Ѱ��Ananagrams 
{
	int i, j;
	for(i = 0;i < len;i ++)
	{
		if(is_ana[i] == true) continue;
		for(j = i+1;j < len;j ++)
		{
			if(is_ana[j] == true) continue;
			if(strcmp(alp_s[i],alp_s[j]) == 0)
			{
				is_ana[i] = is_ana[j] = true;
			}
		}
	}
}

void find_res()//��������������ѡ������������ 
{
	int i, j=0;
	for(i = 0;i < len;i++)
	{
		if(is_ana[i] == false)
			strcpy(res[j++],s[i]);
	}
	qsort(res, j, sizeof(res[0]), cmp_str);
	len = j;
}
int main()
{
//	freopen("data.txt","r",stdin);
	while(scanf("%s",s[len]) != EOF)
	{
		if(strcmp(s[len],"#") == 0) break;
		len++;
	}
	low_cas();
	memset(is_ana, false, sizeof(is_ana));
	find_ana();
	find_res();
	for(int j = 0;j < len;j++) puts(res[j]);
//	puts(alp_s[0]);
	return 0;
}
