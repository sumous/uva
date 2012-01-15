#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[35], dic[35], len;
int fin_pla(int cur)
{
	for(int i =0;i < len;i++)
		if(a[i]==cur) return i;
}
void rev(int start, int stop)
{
	int i, j;
	for(i = start, j=stop;i<j;i++,j--)
	{
		int tmp = a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
}
int cmp(const void *a, const void *b)//排序参考函数 
{
	return (*(int *)b-*(int *)a);
}
int main()
{
	//freopen("data.txt","r",stdin);
//	freopen("data.in","w",stdout);
	char ch[100];
	while(gets(ch)!=NULL)
	{
		int i, j = 0;
	 	len = strlen(ch);
		for(i = 0;i < len;i ++)
		{
			if(ch[i] == ' ') continue;
			if(ch[i+1] != ' ' && ch[i+1]!='\0')
			{
		 		dic[j] = a[j] = (ch[i] - '0')*10+ch[i+1]-'0';
		 		i++;
			}
			else
				dic[j] = a[j] = ch[i] - '0';
			j++;
		}
		len = j;
		//for(int j = 0;j < len;j++) printf("%d ",a[j]);
		qsort(dic,len,sizeof(dic[0]), cmp);
		puts(ch);//输出原始数据 
		
		for(j = 0;j < len;j ++)
		{//printf("%d ",dic[j]);
			if(a[len-j-1] == dic[j]) continue;
			if(a[0] == dic[j])
			{
				rev(0,len-j-1);
				printf("%d ",j+1);
				continue;
			}
			int pla = fin_pla(dic[j]);
			printf("%d %d ", len-pla, j+1);
			rev(0,pla);
			rev(0,len-j-1);
		}
		printf("0\n");
	}
	return 0;
}