#include<stdio.h>
#include<limits.h>
#include<math.h>
#define delta 1e-4
long zer(int n, int base)
{
	long zero=INT_MAX;
	for(long i = 2;i <= base;i++)
	{
		if(base%i!=0) continue;
		
		long int_b=0,int_n=0;
		while(base%i==0 && base!=0){int_b++;base/=i;}//计算base中质因数为i的个数 
	//	printf("%d\n",int_b);
		for(long j = i;j<=n;j*=i) int_n+=n/j;//计算n!中质因数为i的个数 
		if(zero>int_n/int_b) zero=int_n/int_b;//取最小值 
	//	base=b;
	}
	return zero;
}
long digits(long n, long b)
{
	double sum=0.0,base=log(double(b));
	for(int i = 2;i <= n;i++) sum+=log(i);
//	printf("%f\n",ceil(3.00));
	return long((sum/base+delta)+1);
}
int main()
{
	long n,b;
	while(scanf("%ld%ld",&n,&b)!=EOF)
	{
		printf("%ld %ld\n",zer(n,b),digits(n,b));
	}
	return 0;
}