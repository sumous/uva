#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100000
/*dic[]���ڰ���ĸת��Ϊ��Ӧ������*/
char dic[]="22233344455566677778889999";
char ch[80] , a[max+5][9];
int comp(const void *elem1 , const void *elem2)//�ȽϺ���ģ�� 
{
	return strcmp((char *)elem1,(char *)elem2);
}
void output(int n){
int i,j;
bool flag;
for(i=1,j=flag=0;i<n;i++){ //count ����ÿ���绰������ֵĴ���
	if(strcmp(a[i],a[i-1])){
		if(i-j>1){
			printf("%s %d\n",a[j],i-j);
			flag=true;
		}
		j=i;
	}
}
if(n-j>1){
	printf("%s %d\n",a[j],i-j);
	flag=true;
}
if(!flag)
	printf("No duplicates.\n");
}
int main()
{
//	freopen("data.txt" , "r" ,stdin);
	
	int n , i ,j = 0 , count, t, cas;
	scanf("%d", &t);
	while(t--){
		scanf( "%d" , &n );
	
		for(i = 0;i < n;i ++){
			scanf("%s", ch);
	
			j = 0;
			int k = 0;
			int len = strlen(ch);
			while(j < 8){
				if(ch[k] == '-') {k++;continue;}
				if(ch[k] >= 'A'&&ch[k] <= 'Z') a[i][j] = dic[ch[k] - 'A'];
				else a[i][j] = ch[k];
				j ++;
				if(j == 3){//�����ĸ��ַ���ֵΪ'-' 
					a[i][j] = '-';
					j ++;
				}
				k++;
			}
			a[i][j] = '\0';
		}
		qsort(a , n , 9 , comp);//�Ƚ����밴�ֵ����� 
		output(n);
		if(t) putchar('\n');
	}
	return 0;
}
