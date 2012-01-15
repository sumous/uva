#include <stdio.h>
#include <string.h>
#define len 5000
typedef struct{
int v,d; //v记录容器大小，d记录已经占用的空间
}ote;
ote stack[len];
int s[len];
bool deal(int n){
int i,top;
memset(stack,0,sizeof(stack)); //可加也可不加，只不过加了之后方便调试
for(i=0,top=-1;i<n;i++){
if(s[i]<0){
stack[++top].v=-s[i]; //s[i]<0入栈
stack[top].d=0;
}
else{ //s[i]>0出栈
if(s[i]!=stack[top].v)
return false;
if(top)
stack[--top].d+=s[i];
if(stack[top].v<=stack[top].d)
return false;
}
}
return true;
}
int main(void){
int n;
char ch;
freopen("data.txt","r",stdin);
for(n=0;scanf("%d%c",&s[n++],&ch)!=EOF;)
if(ch=='\n')
if(n&1){ //n为奇数时，必然不正确
n=0;
puts(":-( Try again.");
continue;
}
else{
if(deal(n))
puts(":-) Matrioshka!");
else
puts(":-( Try again.");
n=0;
}
return 0;
}