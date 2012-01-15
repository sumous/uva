#include<iostream>
using namespace std;
int main()
{
	int H, U, D, F,d;
//	freopen("data.txt","r",stdin);
	while(cin>>H>>U>>D>>F)
	{
		if(H==0) break;
		int s=0;
	
		F*=U;U*=100;D*=100;H*=100;
		for(d=1;;d++)
		{		
			if(U>=0) s+=U;
			if(s>H){cout<<"success on day "<<d<<endl;break;}

			s-=D;
			if(s<0){cout<<"failure on day "<<d<<endl;break;}

			U-=F;
		}
	}
	return 0;
}