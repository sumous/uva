#include<stdio.h>
#include<math.h>
int main()
{
	while(1)
	{
		long n, r, c;
		scanf("%ld",&n);
		if(n==0) break;
		long cr=sqrt(n);
		if(cr*cr==n)
		{
			if(cr%2==0) printf("%ld %ld\n",cr,1);
			else printf("%ld %ld\n",1,cr);
		}
		else
		{
			long s=cr*cr;
			if(cr%2==1)
			{
				if(n-s<=cr+1) printf("%ld %ld\n",n-s,cr+1);
				else printf("%ld %ld\n",cr+1,2*cr+2-n+s);
			}
			else
			{
				if(n-s<=cr+1) printf("%ld %ld\n",cr+1,n-s);
				else printf("%ld %ld\n",2*cr+2-n+s,cr+1);
			}
		}
	}
	return 0;
}