#include<stdio.h>
#include<string.h>
#define max 200
int an1[max+10];
int an2[max+10];
char str1[max+10];
char str2[max+10];
int main()
{
	//freopen("data.txt", "r", stdin);
	int i,j;
	scanf("%s",str1);
	memset( an1, 0, sizeof(an1));
	int len1=strlen(str1);
	for(j=0,i=len1-1;i>=0;i--)
	   an1[j++]=str1[i]-'0';
	   
	while(str2[0] != '0')
	{
		scanf("%s",str2);
    
  	 	memset( an2, 0, sizeof(an2));
	
 		int len2=strlen(str2);
		for(j=0,i=len2-1;i>=0;i--)
	   		an2[j++]=str2[i]-'0';
	 	for(i=0;i<max;i++)
	 	{
	 		an1[i]+=an2[i];
	 		if(an1[i]>=10)
	 		{
	 			an1[i]-=10;
	 			an1[i+1]++;
		 	}
	 	}
	}
	 for(i=max;(i>=0)&&(an1[i]==0);i--);
	 //if(i>=0)
	 for(;i>=0;i--) printf("%d",an1[i]);
	 printf("\n");
	 return 0;
}