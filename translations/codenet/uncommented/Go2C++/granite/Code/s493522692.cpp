
```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cassert>
#include <random>
#include <iomanip>

using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define RREP(i, n) for(int i=(n)-1; i>=0; i--)
#define RFOR(i, a, b) for(int i=(a)-1; i>=(b); i--)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define print(x) cout << (x) << "\n"
#define print0(x) cout << (x) << " "
#define printa(x, n) REP(i, n){cout << (x)[i] << " \n"")[i];}
#define printv(v) REP(i, v.size()){cout << (v)[i] << " \n"")[i];}
#define printvv(vv) REP(i, vv.size()){cout << (vv)[i] << " \n"")[i];}
#define printP(p) cout << (p).first << " " << (p).second << "\n"
#define printVP(vp) REP(i, vp.size()){cout << (vp)[i].first << " " << (vp)[i].second << "\n"")[i];}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PI;

int main() {
    int N, M;
    cin >> N >> M;
    int tmp = min(N, M/2);
    int ans = tmp;
    N -= tmp;
    M -= tmp * 2;
    ans += M/4;
    cout << ans << endl;
    return 0;
}

