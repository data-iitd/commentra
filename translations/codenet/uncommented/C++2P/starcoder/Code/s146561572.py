
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define endl '\n'
#define watch(x) cout << #x << " : " << x << endl;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main () {
    FastIO
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int ans = 0;
        for (int i=1;i<=n;i++) {
            ans += i * (n-i+1);
        }
        for (int i=1;i<n;i++) {
            int u,v;
            cin>>u>>v;
            int a = max(u,v);
            int b = min(u,v);
            ans -= b * (n-a+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}

