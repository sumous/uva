#include<stdio.h>
#include<string.h>
#include<math.h>
char s[7];
int num1[152],res[152], dot_place, n;

void trans()
/*把字符串转化成数字 
  并去掉小数点
  用dot_place记录小数点位置 
*/ 
{
	int i, j;
	for(i = 5, j = 0;i >= 0;i --)
	{
		if(s[i] != '.')
		{
	 		num1[j] = s[i] - '0';
			j ++;
		}
		else
		{
	 		dot_place = 5-i ;
		}
	}
}
void res_num1()//高精度计算res和num1的乘积 
{	
	int i, j, len1, len2;
	int c[302];
	memset(c, 0, sizeof(c));
	len1 = 149;len2 = 149;
	for(i=0;i<=len2;i++)
	{
		for(j=0;j<=len1;j++)
		{
			c[i+j]+=num1[j]*res[i];
		} 
	}
	for(i=0;i<150;i++)
	{
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			res[i] = c[i]%=10;
		}
		else res[i] = c[i];
	}	
}
void num1_pow()//计算num1的平方 
{
	int i, j, len1;
	int c[302];
	memset(c, 0, sizeof(c));
	for(len1 = 149;len1 >=0&&num1[len1] == 0;len1--);//printf("%d", num1[len1]);
	for(i=0;i<=len1;i++)
	{//printf("%d %d\n", i, len1);
		for(j=0;j<=len1;j++)
		{
			c[i+j]+=num1[j]*num1[i];
		} 
	}
	for(i=0;i<150;i++)
	{
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			num1[i] = c[i]%=10;
		}
		else num1[i] = c[i];
	}
}
void cal()
 /*
   快速幂 
 */
{
	while(n>0)
	{
		if(n%2==1)
		{
	 		res_num1();
		}
		num1_pow();//printf("test");
		n/=2;
	}
 }
 int main()
 {
 	freopen("data.txt","r", stdin);
 	while(scanf("%s%d", s, &n) != EOF)
 	{
 		/*
 			两种特殊情况，分别考虑 
 		*/
 		if(n == 0) {printf("1\n");continue;}
 		if(n == 1) {printf("%s\n", s);continue;}
 		
 		memset(res, 0, sizeof(res));
 		res[0] = 1;
 		memset(num1, 0, sizeof(num1));

		 trans();
	 	int  len, tail, cur_dot = dot_place *n;


 		cal();
 		for(len = 149;len >=0&&res[len] == 0; len--);
 		for(tail = 0;len <=len&&res[tail] == 0; tail++);
 		if(len < cur_dot)//小数点在头部的情况 
		 {
	  		len = cur_dot;
	 		for(;len >=tail ;len --)
	 		{
	 			if(len == cur_dot) {printf(".");}
	 			else printf("%d", res[len]);
		 	}
		 }
		 else if(cur_dot == 0)//小数点在尾部的情况，不输出小数点 
		 	for(;len >=tail ;len --)
	 		{
	 			printf("%d", res[len]);
		 	}
	 	else
	 		for(;len >=tail ;len --)
	 		{
	 			if(len == cur_dot) {printf("%d", res[len]);printf(".");}
	 			else printf("%d", res[len]);
		 	}
	 	printf("\n");
 	}
 	return 0;
 } 