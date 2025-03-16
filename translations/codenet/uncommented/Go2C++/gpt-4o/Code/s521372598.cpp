#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int abs(int n) {
    return n < 0 ? -n : n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; ++i) {
        cin >> as[i];
    }

    vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
        xs[i] = as[i] - i + 1;
    }
    sort(xs.begin(), xs.end());

    int b = xs[n / 2];
    int ans = 0;
    for (int x : xs) {
        ans += abs(x - b);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// <END-OF-CODE>
