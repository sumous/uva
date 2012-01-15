#include<stdio.h>
int main()
{
	int a[51], n, cas=0;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int ave = 0, mov=0;
		for(int i = 0;i < n;i++) {scanf("%d",&a[i]);ave+=a[i];}
		ave/=n;
		for(int i = 0;i < n;i ++)
		{
			if(a[i]>ave) mov+=a[i]-ave;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",++cas,mov);
	}
	return 0;
}