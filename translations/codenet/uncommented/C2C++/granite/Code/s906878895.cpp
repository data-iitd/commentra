
#include<iostream>
using namespace std;
int main()
{
	int a,b,x,w;
	while(cin>>a>>b)
	{
		x=a+b;
		w=0;
		while(x)
		{
			w++;
			x/=10;
		}
		cout<<w<<endl;
	}
	return 0;
}
//END-OF-CODE