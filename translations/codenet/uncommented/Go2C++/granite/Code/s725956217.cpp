
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cctype>
#include <random>
#include <time.h>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int main() {
    int n, m; cin >> n >> m;
    vector<P> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i].first >> s[i].second;
    }
    sort(s.begin(), s.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        int num = min(m, s[i].second);
        ans += num * s[i].first;
        m -= num;
        if(m == 0) break;
    }
    cout << ans << endl;
}

