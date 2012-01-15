#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct qnode
{
	char ch;
	struct qnode* next,*pre;
}Node;
typedef Node* node;
node head;
struct matrix
{
	int r,c;
}m[100];

void destroy()
{
	node p=head->next;
	while(p!=NULL)
	{
		node tmp=p;
		p=p->next;
		free(tmp);
	}
	head->next=NULL;
}
int main()
{
	int n;
//	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	getchar();
	for(int i = 0;i < n;i ++) 
	{
		char ch;
		scanf("%c",&ch);
		scanf("%d %d\n",&m[ch-'A'].r,&m[ch-'A'].c);
	}
	char s[1000];
	head=(node)malloc(sizeof(qnode));
	while(scanf("%s",s)!=EOF)
	{
		int len=strlen(s);
		if(len==1){printf("0\n");continue;}
		int count=0;
		node tail=head;
		for(int i = 0;i < len;i++)//建立链表 
		{
			node p=(node)malloc(sizeof(qnode));
			p->ch=s[i];
			tail->next=p;
			p->pre=tail;
			tail=p;
		}
		tail->next=NULL;
		bool flag=true;
		int tn=n;
		while(head->next!=NULL && int(head->next->ch)<'A'+n)//链表被完全删除 
		{//printf("%d\n",count);
			node p=head->next;
			while(p->ch!=')'&& p!=NULL ) p=p->next;//找到右括号 
			node q1=p->pre,q2=q1->pre,q3=q2->pre;
			if(m[q2->ch-'A'].c!=m[q1->ch-'A'].r){flag=false;destroy();break;}//不满足链表相乘 
			/**
				满足链表相乘，将左括号改成'A'+n，并修改m[n]的c、r值 
			*/
			count+=m[q2->ch-'A'].r*m[q2->ch-'A'].c*m[q1->ch-'A'].c;
			m[tn].r=m[q2->ch-'A'].r;m[tn].c=m[q1->ch-'A'].c;
			q3->ch='A'+tn;q3->next=p->next;
			tn++;
			if(p->next!=NULL) p->next->pre=q3;
			free(p);free(q1);free(q2);
		}
		if(flag) printf("%d\n",count);
		else printf("error\n");
	}
	return 0;
}