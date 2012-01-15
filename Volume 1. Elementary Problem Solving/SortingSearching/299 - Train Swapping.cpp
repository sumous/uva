#include<stdio.h>
int main()
{
//	freopen("data.txt","r",stdin);
	int i , j, flag, temp, count, t, n, array[55];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		count = 0;
		for(i = 0;i < n;i ++)
			scanf("%d", &array[i]);
		
		for(i = 0;i < n-1;i ++)
		{
			for(j = 0;j < n-i-1;j ++)
			{
				if(array[j] > array[j+1])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
					count++;
					flag = 0;
				}
			}
			if(flag) break;
		}
		//	for(i = 0;i < n;i ++) printf("%d ",array[i]);
		printf("Optimal train swapping takes %d swaps.\n",count);
	}
	return 0;
}