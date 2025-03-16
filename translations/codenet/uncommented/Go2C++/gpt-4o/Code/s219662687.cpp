#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    const int INF = pow(10, 11);
    int A, B, Q;
    cin >> A >> B >> Q;

    vector<int> s(A + 2);
    s[0] = -INF;
    s[A + 1] = INF;
    for (int i = 1; i <= A; i++) {
        cin >> s[i];
    }

    vector<int> t(B + 2);
    t[0] = -INF;
    t[B + 1] = INF;
    for (int i = 1; i <= B; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;

        int b = lower_bound(s.begin(), s.end(), x) - s.begin();
        int d = lower_bound(t.begin(), t.end(), x) - t.begin();
        int res = INF;

        for (int S : {s[b - 1], s[b]}) {
            for (int T : {t[d - 1], t[d]}) {
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T);
                res = min(res, min(d1, d2));
            }
        }

        cout << res << endl;
    }

    return 0;
}

// <END-OF-CODE>
