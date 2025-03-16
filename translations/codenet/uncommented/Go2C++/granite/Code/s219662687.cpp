
```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    const int INF = 1e11;
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<int> s(A+2, -INF), t(B+2, -INF);
    s[0] = s[A+1] = INF;
    t[0] = t[B+1] = INF;
    for (int i = 1; i <= A; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= B; i++) {
        cin >> t[i];
    }
    while (Q--) {
        int x;
        cin >> x;
        int b = distance(s.begin(), lower_bound(s.begin(), s.end(), x));
        int d = distance(t.begin(), lower_bound(t.begin(), t.end(), x));
        int res = INF;
        for (int S : {s[b-1], s[b]}) {
            for (int T : {t[d-1], t[d]}) {
                int d1 = abs(S-x) + abs(T-S);
                int d2 = abs(T-x) + abs(S-T);
                res = min(res, min(d1, d2));
            }
        }
        cout << res << endl;
    }
    return 0;
}

