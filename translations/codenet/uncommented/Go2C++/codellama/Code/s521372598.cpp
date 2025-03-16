
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }
    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }
    sort(xs.begin(), xs.end());
    int b = xs[n / 2];
    int ans = 0;
    for (int x : xs) {
        ans += abs(x - b);
    }
    cout << ans << endl;
    return 0;
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

