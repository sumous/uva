/*约瑟夫问题*/ 
#include<stdio.h>
#include<stdlib.h>
typedef struct qnode
{
	int place;//用于记录其所在位置 
	struct qnode *next,*pre; 

}Node;
typedef Node* node;
node q;
void CreateList(int n)//构建链表 
{
	node p , r ;
	int i;
	q = (node)malloc(sizeof(qnode));
	q->place = 1;
	r = q;
	for(i = 2;i <= n;i ++){
		p = (node)malloc(sizeof(qnode));
		p->place = i;
		p->pre=r;
		r->next = p;
		r = r->next;
	}
	r->next = q;
	q->pre=r;
}

void DeleteList(node p)//删除当前结点的后一结点 
{
	node tmp=p;
	p->pre->next=p->next;
	p->next->pre=p->pre;
	free(tmp); 
}

int main()
{
	int n , m  ,k;
/*	freopen("data.txt","r",stdin);
	freopen("res2.txt","w",stdout);*/
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		if(n==0&&k==0&&m==0) break;
		if(n==1) {printf("  1\n");continue;}
		int count = 0;			
		
		CreateList(n);//根据传来的n建立链表
		node qk=q,qm=q->pre;//printf("test");
		while(count<n)
		{
			for(int i = 1;i < k;i++)  qk=qk->next;
			for(int i = 1;i < m;i++)  qm=qm->pre;
			if(qk->place==qm->place)//删除的是同一个结点时 
			{
				count++;
				printf("%3d,",qk->place);
				qk=qk->next;
				qm=qm->pre;
				DeleteList(qk->pre);
				
			}
			else
			{
				count+=2;
				if(count==n){printf("%3d%3d\n",qk->place,qm->place);DeleteList(qk);DeleteList(qm);break;}	
				else printf("%3d%3d,",qk->place,qm->place);				
				if(qk->next==qm) {qk=qm->next;DeleteList(qm->pre);}//防止删除的下一个结点是qm 
				else{qk=qk->next;DeleteList(qk->pre);}							
				qm=qm->pre;
				DeleteList(qm->next);
			}
			if(count==n-1) {printf("%3d\n",qm->place);DeleteList(qm);break;}
		}
	}
	return 0;
}