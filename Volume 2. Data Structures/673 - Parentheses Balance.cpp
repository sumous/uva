#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct qnode
{
	char ch;
	struct qnode* next,*pre;
}Node;
typedef Node* node;
char ch[1000];
int main()
{
	int t;
//	freopen("data.txt","r",stdin);
	scanf("%d",&t);
	getchar();
	while(t--)
	{		
		node head=(node)malloc(sizeof(qnode));
		node tail=head;
		gets(ch);
		for(int i = 0;i < strlen(ch);i++)
		{
			node p=(node)malloc(sizeof(qnode));
			p->ch=ch[i];
			tail->next=p;
			p->pre=tail;
			tail=p;
		}
		tail->next=head;
		head->pre=tail;
		int count=0;
		bool flag=true;
		
		while(head->next!=head)
		{
			int tmp=count;
			node p=head->next;
			while(p->next!=head)
			{
				if((p->ch=='(' && p->next->ch==')') || (p->ch=='[' && p->next->ch==']'))
				{
					node q1=p,q2=p->next;
					p->pre->next=p->next->next;
					p->next->next->pre=p->pre;
					p=p->next->next;
					count+=2;
					free(q1);free(q2);
				}
				else p=p->next;
			}
			if(tmp==count){flag=false;break;}
		}
		if(flag) printf("Yes\n");
		else
		{//printf("test");
			node p=head->next;
			while(p!=head)
			{
				node tmp=p;
				p=p->next;
				free(tmp);
			}
			free(head);
			printf("No\n");
		}
	}
	return 0;
}