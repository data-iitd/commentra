#include <iostream>
#include <map>
using namespace std;

int main() {
	int N,K;
	cin>>N>>K;
	map<int,bool> hm;
	while(1){
		if(!hm[N]){
			hm[N]=true;
			N = abs(N-K);
		}else{
			break;
		}
	}
	int mini=999999999;
	for(auto k:hm){
		mini=min(mini,k.first);
	}
	cout<<mini<<endl;
}
