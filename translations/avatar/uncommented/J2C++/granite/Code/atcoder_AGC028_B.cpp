
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <exception>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define CLR(a,b) memset((a),(b),sizeof(a))
#define fr first
#define sc second
#define foreach(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define print(X) cout<<#X<<" = "<<(X)<<endl

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int n;
ll a[100001];
ll mod = 1000000007;
ll p = 1;
ll q[100001];

ll modinv(ll a,int m){
    ll b = m;
    ll u = 1;
    ll v = 0;
    ll tmp;
    while(b>0){
        ll t = a/b;
        a -= t*b;
        tmp = a;
        a = b;
        b = tmp;
        u -= t*v;
        tmp = u;
        u = v;
        v = tmp;
    }
    u %= m;
    if(u<0) u+=m;
    return u;
}

int main(){
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        p *= (i+1);
        p %= mod;
    }
    q[0] = 1;
    rep(i,n){
        q[i+1] = (q[i] + modinv(i+2,mod))%mod;
    }
    ll ans = 0;
    rep(i,n){
        ll val = q[i] + q[n-i-1] - 1;
        val *= a[i];
        val %= mod;
        val *= p;
        val %= mod;
        ans += val;
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}
//END-OF-CODE