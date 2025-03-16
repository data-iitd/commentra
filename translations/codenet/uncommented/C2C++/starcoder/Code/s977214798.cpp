#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin>>n;
	vector<vector<int>> a(n, vector<int>(n-1));
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			cin>>a[i][j];
		}
	}
	vector<int> e1(n*n, 0);
	vector<int> e2(n*n, 0);
	vector<int> d(n*n, 0);
	vector<bool> b(n*n, false);
	for(int i=0; i<n; i++){
		for(int j=0; j<n-2; j++){
			int from = i*n+a[i][j];
			int to = i*n+a[i][j+1];
			if(e1[from]==0){
				e1[from]=to;
			}else if(e2[from]==0){
				e2[from]=to;
			}else{
				cout<<"-1"<<endl;
				return 0;
			}
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		int from = i*n+a[i][0];
		int now=0;
		while(true){
			if(b[from]) break;
			if(d[from]) break;
			b[from]=true;
			int to;
			to = e1[from];
			int max=0;
			if(to!=0){
				int now=f(to);
				if(now<0) break;
				if(now>max) max=now;
			}
			to = e2[from];
			if(to!=0){
				int now=f(to);
				if(now<0) break;
				if(now>max) max=now;
			}
			b[from]=false;
			d[from]=max+1;
			if(max==0) break;
			from=to;
		}
		if(now<0){
			ans=-1;
			break;
		}
		if(now>ans) ans=now;
	}
	cout<<ans<<endl;
}

