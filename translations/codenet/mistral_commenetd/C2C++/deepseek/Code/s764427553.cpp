#include<iostream>
#include<vector>

using namespace std;

int main(){
	const int MAX_V=999999;
	vector<bool> prime(MAX_V+1, true);

	for(int i=2;i<=MAX_V;i++){
		if(prime[i]){
			for(int k=i*i;k<=MAX_V;k+=i){
				prime[k]=false;
			}
		}
	}

	prime[0]=false;
	prime[1]=false;

	int count=0;
	int n;

	while(cin>>n){
		count++;
		int cnt=0;
		for(int i=n;i>0;i--){
			if(prime[i]){
				cnt++;
			}
		}
		cout<<cnt<<endl;
		if(count==30)break;
	}

	return 0;
}

