
#include <iostream>

using namespace std;

int main(void)
{
	int a,b,c,i,j,k;
	int max;

	cin>>j;

	for(i=0;i<j;i++){
		cin>>a;
		cin>>b;
		cin>>c;

		max=a;
		k=0;
		if(max<=b){
			max=b;
			k=1;
		}
		if(max<=c){
			max=c;
			k=2;
		}

		max=max*max;
		a=a*a;
		b=b*b;
		c=c*c;
		if(k==0 && max==b+c){
			cout<<"YES\n";
		}
		else if(k==1 && max==a+c){
			cout<<"YES\n";
		}
		else if(k==2 && max==a+b){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}

return (0);
}

