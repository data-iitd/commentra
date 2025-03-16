
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
typedef long long ll;
using namespace std;
const int N=2e5+10;
ll a[N],pre[N],last[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
			scanf("%lld",&a[i]);
	}
	ll sumpre=0,sumlast=0;
	for(int i = 1;i<n;i++){
		sumpre=sumpre+a[i];
		pre[i]=sumpre;
//		printf("%lld++\n",pre[i]);
	}
	for(int i = n;i>1;i--){
		sumlast=sumlast+a[i];
		last[i]=sumlast;
//		printf("%lld+++\n",last[i]);
	}
	ll d=(1ll<<60);
	for(int i = 1;i<n;i++){
//		printf("%lld\n",pre[i]-last[i+1]);
		d=min(d,abs(pre[i]-last[i + 1]));
	}
	printf("%lld\n",d);
}
