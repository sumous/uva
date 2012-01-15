#include<stdio.h>
#include<string.h>
void up(char* s)
{
	char tmp=s[0];
	s[0]=s[1];s[1]=s[5];s[5]=s[4];s[4]=tmp;
}
void down(char* s)
{
	char tmp=s[0];
	s[0]=s[4];s[4]=s[5];s[5]=s[1];s[1]=tmp;
}
void right(char* s)
{
	char tmp=s[1];
	s[1]=s[2];s[2]=s[4];s[4]=s[3];s[3]=tmp;
}
void left(char* s)
{
	char tmp=s[1];
	s[1]=s[3];s[3]=s[4];s[4]=s[2];s[2]=tmp;
}
void rl(char* s)
{
	char tmp=s[0];
	s[0]=s[3];s[3]=s[5];s[5]=s[2];s[2]=tmp;
}
void lr(char* s)
{
	char tmp=s[0];
	s[0]=s[3];s[3]=s[5];s[5]=s[2];s[2]=tmp;
}
int main()
{
//	freopen("data.txt","r",stdin);
	char s[13], s1[7], s2[7];
	while(gets(s)!=NULL)
	{
		int i;
		for(i = 0;i < 6;i ++)
		{
			s1[i]=s[i];
			s2[i]=s[i+6];
		}
		s1[i]=s2[i]='\0';
		if(strcmp(s1,s2)==0) {printf("TRUE\n");continue;}
		bool flag=false;
		char tmp[7];
		
		strcpy(tmp,s1);
		for(i = 0;i < 4;i ++)
		{
			if(strcmp(tmp,s2)==0) {flag=true;break;}
			lr(tmp);
		}
		if(flag) {printf("TRUE\n");continue;}
		
		strcpy(tmp,s1);
		up(tmp);
		for(i = 0;i < 4;i ++)
		{		
			if(strcmp(tmp,s2)==0) {flag=true;break;}
			left(tmp);
		}
		if(flag) {printf("TRUE\n");continue;}
		
		strcpy(tmp,s1);
		down(tmp);
		for(i = 0;i < 4;i ++)
		{
			if(strcmp(tmp,s2)==0) {flag=true;break;}
			left(tmp);
		}
		if(flag) {printf("TRUE\n");continue;}
		
		strcpy(tmp,s1);
		down(tmp);
		down(tmp);
		for(i = 0;i < 4;i ++)
		{
			if(strcmp(tmp,s2)==0) {flag=true;break;}
			lr(tmp);
		}
		if(flag) {printf("TRUE\n");continue;}
		
		strcpy(tmp,s1);
		left(tmp);
		for(i = 0;i < 4;i ++)
		{
			if(strcmp(tmp,s2)==0) {flag=true;break;}
			up(tmp);
		}
		if(flag) {printf("TRUE\n");continue;}
		
		strcpy(tmp,s1);
		right(tmp);
		for(i = 0;i < 4;i ++)
		{
			if(strcmp(tmp,s2)==0) {flag=true;break;}
			up(tmp);
		}
		
		if(flag) printf("TRUE\n");
		else printf("FALSE\n");
	}
	return 0;
}