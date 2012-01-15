#include<stdio.h>
#include<math.h>
int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF && n>=0)
	{
		long long fac;
		for(fac=2;fac<=sqrt(n);fac++)
		{
			if(n%fac!=0) continue;
			while(n%fac==0)
			{
				printf("    %lld\n",fac);
				n/=fac;
			}
			
		}
		if(n>1)
				printf("    %lld\n\n",n);
		else printf("\n");
	}
	return 0;
}