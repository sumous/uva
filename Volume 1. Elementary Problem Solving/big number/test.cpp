#include <stdio.h>
#include <string.h>
const int Int[11]={2,1,4,7,4,8,3,6,4,7};
char *s1="first number too big",*s2="second number too big",*s3="result too big";
char exp[10010]={'\0'},opr;
int a[510]={0},b[510]={0},la,lb;
bool Bignum(int *a,int la)
{
     if(la>10) return true;
     else if(la<10) return false;
     for(int i=0;i<10;i++)
        if(a[i]>Int[i]) return true;
        else if(a[i]<Int[i]) return false;
     return false;
}
int Delzero(int *a,int la)
{
    while(!a[la-1]&&la-1) la--;
    return la;
}
void Change(int *a,int la)
{
     int t;
     for(int i=0;i<la-i-i;i++)
     { t=a[i]; a[i]=a[la-1-i]; a[la-1-i]=t; }
}
void Plus(int *a,int *b,int la)
{
     for(int i=0;i<la;i++)
     {
        a[i]+=b[i];
        if(a[i]>=10)
        {
           a[i+1]++;
           a[i]%=10;
        }
     }
     if(a[la]) la++;
     la=Delzero(a,la);
     Change(a,la);
     if(Bignum(a,la)) printf("%s\n",s3);
}
void Mult(int *a,int *b,int la,int lb)
{
     int c[510]={0};
     for(int i=0;i<la;i++)
        for(int j=0;j<lb;j++)
        {
            c[i+j]+=a[i]*b[j];
            if(c[i+j]>=10)
            {
               c[i+j+1]+=c[i+j]/10;
               c[i+j]%=10;
            }
        }
     la+=lb;
     la=Delzero(c,la);
     Change(c,la);
     if(Bignum(c,la)) printf("%s\n",s3);
}
int main()
{
    freopen("data.txt","r",stdin);
   // freopen("uva465.out","w",stdout);
    bool t;
    while(gets(exp)!=NULL)
    {
       t=true;la=lb=0;
       memset(a,0,sizeof(a));
       memset(b,0,sizeof(b));
       puts(exp);
       for(int i=0;i<strlen(exp);i++)
          if(exp[i]==' '||exp[i]=='*'||exp[i]=='+')
          {
             if(exp[i]=='*'||exp[i]=='+') opr=exp[i];
             t=false;
          }
          else
          {
             if(t) a[la++]=exp[i]-'0';
             else b[lb++]=exp[i]-'0';
          }
       Change(a,la); la=Delzero(a,la); Change(a,la);
       Change(b,lb); lb=Delzero(b,lb); Change(b,lb);
       if(Bignum(a,la)) printf("%s\n",s1);
       if(Bignum(b,lb)) printf("%s\n",s2);
       Change(a,la); Change(b,lb);
       if(opr=='+') Plus(a,b,la>lb?la:lb);
       else         Mult(a,b,la,lb);
    }
    return 0;
}

