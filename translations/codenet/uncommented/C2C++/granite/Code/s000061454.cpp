
#include <iostream>

using namespace std;

int main(void) {
	int a,b,n;
	int sum;
	int i,j;
	while(cin>>a>>b>>n) {
		a%=b;
		sum=0;
		for(i=1;i<=n;i++) {
			a*=10;
			for(j=9;j>=0;j--) {
				if(b*j<=a)break;
			}
			a%=b;
			sum+=j;
		}
		cout<<sum<<endl;
	}
	return 0;
}

