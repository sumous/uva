#include <iostream>

#include <cmath>
using namespace std;
int main()
{
	double m,n,N,K;

	while(cin>>m>>n)
	{
		if(m==0||n==0) break;
		N=1;
		while(abs(log(N)/log(N+1) - log(n)/log(m))>1e-10) ++N;
		K=int(0.5+log(m)/log(N+1));
		//double tmp=N/(N+1);
		int hei=int(m*(1+N)*(1-pow(N/(1+N),K+1))+0.5);
		int noer;
		if(int(N)==1) noer=int(K);
		else noer=int((1-pow(N,K))/(1-N)+0.5);
		cout<<noer<<' '<<hei<<endl;
	}
	return 0;
}