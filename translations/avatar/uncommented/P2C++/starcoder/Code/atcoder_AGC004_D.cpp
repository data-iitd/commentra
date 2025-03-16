#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define len(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const int MOD = 1000000007;
const int MAXN = 100000 + 10;
int n, k;
vi links[MAXN];
int dfs(int v, int p) {
    int height_from_leaf = 0, cut_count = 0;
    for (int u : links[v]) {
        if (u == 0) continue;
        int hgt, cut = dfs(u, v);
        height_from_leaf = max(height_from_leaf, hgt);
        cut_count += cut;
    }
    height_from_leaf++;
    if (p!= 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count++;
    }
    return height_from_leaf, cut_count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) links[i].clear();
    rep(i, 1, n) {
        int a;
        cin >> a;
        links[a - 1].pb(i);
    }
    int _, ans = dfs(0, 0);
    if (aaa[0]!= 1) ans++;
    cout << ans << endl;
    return 0;
}
