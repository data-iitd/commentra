
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<long long> heap;
long long a[100000];
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	for(i=0;i<n;i++)heap.push(a[i]);
	for(i=0;i<m;i++){
		long long tm=heap.top();
		heap.pop();
		tm/=2;
		heap.push(tm);
	}
	long long ans=0;
	for(i=0;i<n;i++)ans+=heap.top(),heap.pop();
	printf("%lld\n",ans);
	return 0;
}

