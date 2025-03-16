

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

template<class T> void read(T &x){
    cin >> x;
}
template<class H, class T> void read(pair<H, T> &p){
    cin >> p.first >> p.second;
}
template<class T, size_t S> void read(array<T, S> &a){
    for(int i=0;i<S;i++) cin >> a[i];
}
template<class T> void read(vector<T> &v){
    for(int i=0;i<v.size();i++) cin >> v[i];
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll p=1;
    for(int i=2;i<=n;i++){
        p=p*i%MOD;
    }
    vector<ll> q(n);
    q[0]=1;
    for(int i=1;i<n;i++){
        q[i]=(q[i-1]+MOD+modinv(i+1,MOD))%MOD;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll val=(q[i]+q[n-i-1]-1)%MOD;
        val=val*a[i]%MOD;
        val=val*p%MOD;
        ans=(ans+val)%MOD;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

