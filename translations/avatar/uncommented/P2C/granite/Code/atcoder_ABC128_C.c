
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <set>
#include <map>
#define MOD 100000007
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main() {
    int n, m;
    cin >> n >> m;
    vvi li(m);
    rep(i, m) {
        int l;
        cin >> l;
        li[i].resize(l);
        rep(j, l) cin >> li[i][j];
    }
    vi p(m);
    rep(i, m) cin >> p[i];
    set<int> q, v;
    rep(i, n) v.insert(i + 1);
    rep(i, m) {
        rep(j, li[i].size()) {
            q.insert(li[i][j]);
            v.erase(li[i][j]);
        }
    }
    int ans = 0;
    rep(i, q.size() + 1) {
        rep(j, (1 << i)) {
            bitset<30> bs(j);
            bool flag = true;
            rep(k, m) {
                int cnt = 0;
                rep(l, li[k].size()) {
                    if (q.count(li[k][l]) && bs[li[k][l] - 1]) cnt++;
                    else if (!q.count(li[k][l]) &&!bs[li[k][l] - 1]) cnt++;
                }
                if (cnt % 2!= p[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans += (1 << (v.size()));
        }
    }
    cout << ans << endl;
    return 0;
}
// END-OF-CODE