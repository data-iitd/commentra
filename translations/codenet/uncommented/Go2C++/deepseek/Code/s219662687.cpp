#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int nextInt() {
    int num;
    cin >> num;
    return num;
}

int main() {
    const int INF = 1e11;
    int A = nextInt();
    int B = nextInt();
    int Q = nextInt();
    vector<int> s(A + 2);
    s[0] = -INF;
    s[A + 1] = INF;
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt();
    }

    vector<int> t(B + 2);
    t[0] = -INF;
    t[B + 1] = INF;
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt();
    }

    for (int i = 0; i < Q; i++) {
        int x = nextInt();
        int b = lower_bound(s.begin(), s.end(), x) - s.begin();
        int d = lower_bound(t.begin(), t.end(), x) - t.begin();
        int res = INF;
        for (int S : {s[b - 1], s[b]}) {
            for (int T : {t[d - 1], t[d]}) {
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T);
                res = min({res, d1, d2});
            }
        }

        cout << res << endl;
    }
}
