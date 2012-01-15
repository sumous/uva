#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i = 0;i < t;i++)
	{
		if(i) cout<<endl;
		int k;
		cin>>k;
		if(k==0){cout<<"3"<<endl;continue;}
		if(k<0) k=-k;
		int n=sqrt(k<<1);
		int s=n*(n+1)>>1;
		while(1)
		{
			if(s>=k) break;
			n++;
			s+=n;
		}
		while((s-k)&1)
		{
			n++;
			s+=n;
		}
		cout<<n<<endl;
		
	}
	return 0;
}