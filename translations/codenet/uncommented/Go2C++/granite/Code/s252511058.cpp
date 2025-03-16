
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <utility>
#include <numeric>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
using namespace std;
typedef long long LL;

struct point {
    int x, l, r;
    bool operator<(const point &p) const {
        return r < p.r;
    }
};

int main() {
    int N;
    cin >> N;
    vector<point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].l;
        points[i].l = points[i].x - points[i].l;
        points[i].r = points[i].x + points[i].l;
    }
    sort(points.begin(), points.end());
    int ans = 1, start = points[0].r;
    for (int i = 1; i < N; ++i) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}

