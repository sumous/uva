#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define len 202
#define le 10002
#define llen 52
#define lee 12
#define opp 3005
char s[len][le],word[llen][lee],keyword[opp][le],lword[lee],tem[le];
int ak;
int icmp(const void *a,const void *b){
return strcmp((char *)a,(char *)b);
}
void transform_lower(char *st){
int i,n=(int)strlen(st);
for(i=0;i<n;i++)
if(isalpha(st[i]))
st[i]=tolower(st[i]);
}
void transform_upper(char *st){
int i,n=(int)strlen(st);
for(i=0;i<n;i++)
if(isalpha(st[i]))
st[i]=toupper(st[i]);
}
void find(char *st,int k){
int i,j,n=(int)strlen(st),m;
char key[le];
bool flag;
for(i=m=0;i<=n;i++){
flag=false;
key[m+1]='\0';
if(isalpha(st[i]))
key[m++]=st[i];
if(!isalpha(st[i])&&st[i-1]!=' '){
m=0;
//search whether the key is in the word[k]
for(j=0;j<k;j++)
if(!strcmp(word[j],key)){
flag=true;
break;
}
if(flag)
continue;
//search whether the key have been in keyword
for(j=0;j<ak;j++)
if(!strcmp(keyword[j],key)){
flag=true;
break;
}
if(!flag)
strcpy(keyword[ak++],key);
}
}
}
char *stroi(char *str,char *rt,int kd){
int i,j,m,n=(int)strlen(str);
char ss[le];
for(i=kd,m=0;i<=n;i++){
ss[m+1]='\0';
if(isalpha(str[i]))
ss[m++]=str[i];
else{
if(!strcmp(ss,rt))
return &str[i]-m;
m=0;
}
}
return NULL;
}
void output(int n){
int i,j,m,kd;
char *p,*k;
for(i=0;i<ak;i++)
for(j=kd=0;j<n;j++){
p=stroi(s[j],keyword[i],kd); //gain the address of the keyword in s[j]
if(p==NULL){
kd=0;
continue;
}
strcpy(lword,keyword[i]);
transform_upper(lword);
for(k=s[j];k<p;k++)
putchar(*k);
m=(int)strlen(lword);
printf("%s",lword);
puts(p+m);
kd=p-s[j]+m+1;
j--;
}
}
int main(void){
int i,j,k;freopen("data.txt","r",stdin);
//input
for(k=0;gets(word[k])!=NULL&&strcmp(word[k],"::");k++);
for(i=0;gets(tem)!=NULL;)
if(tem[0]!=0)
strcpy(s[i++],tem);
//transform array s to lower letters
for(j=0;j<i;j++)
transform_lower(s[j]);
//find the keyword
for(j=ak=0;j<i;j++)
find(s[j],k);
//���ؼ��ֵ��ֵ�������
qsort(keyword,ak,sizeof(char)*le,icmp);
//output
output(i);
}