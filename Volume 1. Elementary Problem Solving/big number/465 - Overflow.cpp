#include<stdio.h>
#include<string.h>
#define max 1000
char str1[max+10], ch, str2[max+10];
int len1, len2;
const int dic[10] = {2,1,4,7,4,8,3,6,4,7};
int is_bigstr(char* s, int len)
{
	if(len > 9) return 1;
	if(len < 9) return 0;
	int  i, j;//printf("%d\n", len);
	for(i = 0, j = 9-len;i <= len;i ++, j++)
	{
		if(s[i]-'0' < dic[j])
			return 0;
		if(s[i]-'0' > dic[j])
			return 1;	
	}
	return 0;
}
int is_big(int* s, int cur)//判断该整数是否超过了int 
{
	int  i, j;
	if(cur > 9) return 1;
	if(cur < 9) return 0;
	for(i = cur, j = 9-cur;i >= 0;i --, j++)
	{
		if(s[i] < dic[j])
			return 0;
		else if(s[i] > dic[j])
			return 1;
	}
	return 0;
}
int plus()
{
	int an1[max+10]={0}, an2[max+10]={0}, i, j;

	for(j=0,i=len1-1;i>=0;i--)
	   an1[j++]=str1[i]-'0';

	for(j=0,i=len2-1;i>=0;i--)
	   an2[j++]=str2[i]-'0';
	 for(i=0;i<max+10;i++)
	 {
	 	an1[i]+=an2[i];
	 	if(an1[i]>=10)
	 	{
	 		an1[i]-=10;
	 		an1[i+1]++;
		 }
	 }
	 for(i=max+9;(i>=0)&&(an1[i]==0);i--);
	 if(is_big(an1, i)) return 1;
	 return 0;
}
int product()
{
	int a[max+10]={0},b[max+10]={0};
		int i,j;
		if(len1 + len2 > 11) return 1;
		int c[max*2+20]={0};
		str1[len1]='\0';str2[len2]='\0';
		for(j=0,i=len1-1;i>=0;i--)
		{
			a[j++]=str1[i]-'0';
		}
		for(j=0,i=len2-1;i>=0;i--)
		{
			b[j++]=str2[i]-'0';
		}
		for(i=0;i<len2;i++)
		{
			for(j=0;j<len1;j++)
			{
				c[i+j]+=a[j]*b[i];
			} 
		}
		for(i=0;i<max*2+10;i++)
		{
			if(c[i]>=10)
			{
				c[i+1]+=c[i]/10;
				c[i]%=10;
			}
		}
		for(i=max*2+10;(i>=0)&&(c[i]==0);i--);
		//printf("test");
		if(is_big(c, i)) return 1;
		return 0;
}
int main()
{
//	freopen("data.txt","r", stdin);
	while(scanf("%s %c %s", str1, &ch, str2) != EOF)
	{//printf("test");
		
		len1=strlen(str1),len2=strlen(str2);
		str1[len1] = '\0';str2[len2] = '\0';
		int flag[3]={0}, is_ne = 1;
		
		if((strcmp(str1, "0") == 0||strcmp(str2, "0") == 0)&&(ch == '*'))
		{//printf("test");
			if(is_bigstr(str1, len1-1 ))//第一个数据太大 
			{
				flag[0] = 1;
			}
			if(is_bigstr(str2, len2-1 ))//第二个数据太大 
			{//printf("test\n");
				flag[1] = 1;
			}
		}
		else
		{
		 	if(is_bigstr(str1, len1-1))//第一个数据太大 
			{//printf("test");
				flag[0] = 1;
				flag[2] = 1;
				is_ne = 0;
			}
			if(is_bigstr(str2, len2-1 ))//第二个数据太大 
			{//printf("test\n");
				flag[1] = 1;
				flag[2] = 1;
				is_ne = 0;
			}
			if(is_ne)//第一个或第二个数据太大了，结果肯定大了 
			{
				if(ch == '+')
				{
					if(len1 < 10&&len2 < 10)
						flag[2] = 0;
					else if(plus())
							flag[2] = 1;
				}
				else
				{
					if(product())
						flag[2] = 1;
				}
			}
		}
		printf("%s %c %s\n", str1, ch, str2);
		if(flag[0]) printf("first number too big\n");
		if(flag[1]) printf("second number too big\n");
		if(flag[2]) printf("result too big\n");
	}
	return 0;
}