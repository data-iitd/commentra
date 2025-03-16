
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1e11;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<int> s(A+2, -INF);
    vector<int> t(B+2, -INF);
    for (int i = 1; i <= A; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= B; i++) {
        cin >> t[i];
    }
    s[A+1] = INF;
    t[B+1] = INF;
    for (int i = 0; i < Q; i++) {
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

