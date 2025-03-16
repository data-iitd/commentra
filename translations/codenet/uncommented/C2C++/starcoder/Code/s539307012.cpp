#include<iostream>
using namespace std;

int main(void){
	int n,x,min,m,i;
	cin>>n>>x>>min;
	x-=min;
	for(i=1;i<n;i++){
		cin>>m;
		x-=m;
		if(min>m){
			min=m;
		}
	}
	cout<<n+x/min<<endl;
	return 0;
}
