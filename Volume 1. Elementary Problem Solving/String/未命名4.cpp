#include <stdio.h>
#include <string.h>
#define MAXN 400
char str[MAXN]={'\0'},s[MAXN]={'\0'},rules[20][102]={'\0'},replace[21][102]={'\0'};
int n;
void Autoedit(char *str,char *rule,char *rep)
{
     int len=strlen(str),lr=strlen(rule),lp=strlen(rep),k;
     for(int i=0;i<=len-lr;i++)
     {
        sprintf(s,"%.*s",lr,str+i);
        s[lr]='\0';
        if(strcmp(s,rule)==0)
        {
           memset(s,0,sizeof(s));
           sprintf(s,"%.*s",i,str);
           strcat(s,rep);
           k=i+lp;
           for(int j=i+lr;j<len;j++) s[k++]=str[j];
           sprintf(str,"%.*s",k,s);
           str[len=k]='\0';
           i--;
        }
     }
}
int main()
{
	freopen("data.txt", "r", stdin);
    while(true)
    {
       scanf("%d\n",&n);
       if(n==0) break;
       for(int i=0;i<n;i++)
       {
          gets(rules[i]);
          gets(replace[i]);
       }
       gets(str);
       for(int i=0;i<n;i++)
          Autoedit(str,rules[i],replace[i]);
       printf("%s\n",str);
    }
    return 0;
}