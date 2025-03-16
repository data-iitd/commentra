#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Main {
    const int INF = INT_MAX;
public:
    void solve() {
        int N;
        long long X;
        cin >> N >> X;
        vector<long long> x(N);
        vector<long long> xsum(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            cin >> x[i];
            xsum[i + 1] = xsum[i] + x[i];
        }
        long long ans = X * N + 5 * xsum[N];
        for (int i = 1; i < N; ++i) {
            long long cost = X * i + 5 * (xsum[N] - xsum[N - i]);
            for (int j = 5, k = N - i; k >= 0; j += 2, --k) {
                if (cost > ans) {
                    break;
                }
                cost += j * (xsum[k] - xsum[max(k - i, 0)]);
            }
            ans = min(ans, cost);
        }
        cout << ans + N * X << endl;
    }
};

int main() {
    Main().solve();
    return 0;
}

