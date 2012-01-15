#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int val;
	struct node* next,*pre;
};
int q=0;
node* block[30];
node* ta,*tb;
int n;
int a,b;
bool find()//查找a,b对应的位置 
{
	node* p;
	int la,lb;
	bool fa=false, fb=false;
	for(int i = 0;i < n;i ++)
	{
		if(fa && fb) return (la==lb)?false:true;
		p=block[i]->next;
		while(p!=NULL)
		{
			if(fa && fb) return (la==lb)?false:true;
			if(p->val==a){ta=p;la=i;fa=true;}
			if(p->val==b){tb=p;lb=i;fb=true;}
			p=p->next;
		}
	}
}
void place_ori(node* cur)//放回原处 
{
	node* p=cur;
	while(p!=NULL)
	{
		node* tmp=p;
		node* q=block[p->val];
		while(q->next!=NULL) q=q->next;
		q->next=tmp;
		tmp->pre=q;
		p=p->next;
		tmp->next=NULL;
	}
}
void move_onto()
{
	if(!find()) return;
	place_ori(ta->next);
	place_ori(tb->next);
	tb->next=ta;
	ta->pre->next=NULL;
	ta->pre=tb;
	ta->next=NULL;
}
void move_over()
{
	if(!find()) return;
	place_ori(ta->next);
	while(tb->next!=NULL) tb=tb->next;	
	tb->next=ta;
	ta->pre->next=NULL;
	ta->pre=tb;
	ta->next=NULL;
}
void pile_onto()
{
	if(!find()) return;
	place_ori(tb->next);
	tb->next=ta;
	ta->pre->next=NULL;
	ta->pre=tb;
}
void pile_over()
{
	if(!find()) return;
	while(tb->next!=NULL) tb=tb->next;
	tb->next=ta;
	ta->pre->next=NULL;
	ta->pre=tb;
}
void destroy()
{
	for(int i = 0; i < n;i++)
	{
		node* p=block[i];
		while(p!=NULL)
		{
			node* tmp=p;
			p=p->next;
			free(tmp);
		}
	}
}
int main()
{
	char s1[5],s2[5];
	freopen("data.txt","r",stdin);
//	freopen("res2.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i < n;i++)//初始化 
		{
			block[i]=(node *)malloc(sizeof(node));
			node* p=(node *)malloc(sizeof(node));
			p->val=i;
			block[i]->val=-1;
			block[i]->next=p;
			p->next=NULL;
			p->pre=block[i];
			block[i]->pre=NULL;
		}
		while(1)//输入数据并处理 
		{
			scanf("%s",s1);
			if(s1[0]=='q') break;
			scanf("%d %s %d\n",&a,s2,&b);
			if(a==b) continue;
			if(s1[0]=='m' && s2[1]=='n') move_onto();
		    else if(s1[0]=='m' && s2[1]=='v') move_over();
			else if(s1[0]=='p' && s2[1]=='n') pile_onto();
			else if(s1[0]=='p' && s2[1]=='v') pile_over();
		}
		for(int i = 0;i < n;i++)//输出数据 
		{
			printf("%d:",i);
			node* p=block[i]->next;
			while(p!=NULL)
			{
				printf(" %d",p->val);
				p=p->next;
			}
			printf("\n");
		}
		destroy();
	}
	return 0;
}