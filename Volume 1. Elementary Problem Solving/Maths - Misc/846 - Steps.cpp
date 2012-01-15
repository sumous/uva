#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t, a, b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a==b) {cout<<"0"<<endl;continue;}
		a=b-a;
		int n = sqrt(a)+1;
		while(n*(n+1)>a)
			n--;
		if((n+1)*n==a) cout<<2*n<<endl;		
		else if((n+1)*(n+1)>=a) cout<<2*n+1<<endl;
		else cout<<2*n+2<<endl;
	}
	return 0;
}