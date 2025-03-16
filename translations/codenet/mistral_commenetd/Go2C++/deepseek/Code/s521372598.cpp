#include <bits/stdc++.h>
using namespace std;

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

void solve() {
    int n = getInt();
    vector<int> as = getIntSlice(n);

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

const long long inf = 1LL << 60;

int getInt() {
    int ret;
    cin >> ret;
    return ret;
}

vector<int> getIntSlice(int n) {
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
        cin >> ret[i];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
