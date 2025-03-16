
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <functional>
#include <bitset>
#include <stack>

using namespace std;
using Int = int64_t;
const char endl = '\n';
#define REP(i, n) for(Int i = 0; i < (n); i++)
#define FOR(i, a, b) for(Int i = (a); i < (b); i++)
#define RREP(i, n) for(Int i = (n) - 1; i >= 0; i--)
#define RFOR(i, a, b) for(Int i = (b) - 1; i >= (a); i--)
#define ALL(obj) (obj).begin(), (obj).end()

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<int> a(n); REP(i, n) cin >> a[i];
    // 変数未使用エラー回避
    a[0] = 0;

    int sum = k;
    int ans = 1;
    while(sum < n){
        sum = sum - 1 + k;
        ans++;
    }
    cout << ans << endl;

    return 0;
}

