
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define debug(x) cout<<"LINE "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl;
using namespace std;

typedef long long ll;

int main(void)
{

int n,m;

cin>>n>>m;

//n gu m ki

int ans =0;
// gu gu
ans+= n*(n-1)/2;

//kiki
ans +=m*(m-1)/2;

cout<<ans<<endl;




