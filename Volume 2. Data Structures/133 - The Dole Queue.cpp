/*Լɪ������*/ 
#include<stdio.h>
#include<stdlib.h>
typedef struct qnode
{
	int place;//���ڼ�¼������λ�� 
	struct qnode *next,*pre; 

}Node;
typedef Node* node;
node q;
void CreateList(int n)//�������� 
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

void DeleteList(node p)//ɾ����ǰ���ĺ�һ��� 
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
		
		CreateList(n);//���ݴ�����n��������
		node qk=q,qm=q->pre;//printf("test");
		while(count<n)
		{
			for(int i = 1;i < k;i++)  qk=qk->next;
			for(int i = 1;i < m;i++)  qm=qm->pre;
			if(qk->place==qm->place)//ɾ������ͬһ�����ʱ 
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
				if(qk->next==qm) {qk=qm->next;DeleteList(qm->pre);}//��ֹɾ������һ�������qm 
				else{qk=qk->next;DeleteList(qk->pre);}							
				qm=qm->pre;
				DeleteList(qm->next);
			}
			if(count==n-1) {printf("%3d\n",qm->place);DeleteList(qm);break;}
		}
	}
	return 0;
}