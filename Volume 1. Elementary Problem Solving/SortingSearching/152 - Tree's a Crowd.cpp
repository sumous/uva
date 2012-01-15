#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include <float.h>

struct point 
{
	double x, y, z;
}a[5005];
int res[11];
void fin_plc(double t)
{
	int tmp = int(t);
	if(tmp<10)
		res[tmp]++;
}
double dist(int i , int j)
{
	return (double)sqrt((a[j].x-a[i].x)*(a[j].x-a[i].x)+(a[j].y-a[i].y)*(a[j].y-a[i].y)+(a[j].z-a[i].z)*(a[j].z-a[i].z));
}
int main()
{
//	freopen("data.txt","r",stdin);
	int i = 0, j, k;
	while(scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z)==3)
	{
		if(a[i].x==0.0 && a[i].y==0.0 && a[i].z==0.0) break;
		i++;
	}
	memset(res,0,sizeof(res));
	
	for(j = 0;j < i;j ++)
	{	
		double min=DBL_MAX;
		for(k = 0;k < i;k ++)
		{
			if(k == j) continue;
			double tmp = dist(j,k);
			if(tmp < min) min = tmp;
		}
		fin_plc(min);
	}
	for(j = 0;j < 10;j ++) printf("%4d", res[j]);
	printf("\n");
	return 0;
}