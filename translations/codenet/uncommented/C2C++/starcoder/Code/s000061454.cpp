#include <iostream>
using namespace std;

int main() {
	int a,b,n;
	int sum;
	int i,j;
	while(1) {
		cin>>a>>b>>n;
		if(cin.eof())break;
		a-=a/b*b;
		sum=0;
		for(i=1;i<=n;i++) {
			a*=10;
			for(j=9;j>=0;j--) {
				if(b*j<=a)break;
			}
			a-=b*j;
			sum+=j;
		}
		cout<<sum<<endl;
	}
	return 0;
}

