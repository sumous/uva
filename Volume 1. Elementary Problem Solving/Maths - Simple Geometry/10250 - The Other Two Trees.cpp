#include<stdio.h>
int main()
{
	double ax,ay,cx,cy;
	while(scanf("%lf%lf%lf%lf",&ax,&ay,&cx,&cy)!=EOF)
	{
		 double bx = (cx+ax+cy-ay)/2;
         double by = (cy+ay+ax-cx)/2;
         double dx = (cx+ax+ay-cy)/2;
         double dy = (cy+ay+cx-ax)/2;
         printf("%.10lf %.10lf %.10lf %.10lf\n",bx,by,dx,dy);

	}
	return 0;
}