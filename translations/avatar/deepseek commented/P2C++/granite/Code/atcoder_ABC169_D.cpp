
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;

template<typename T> void chmin(T &a, T b) { a = min(a, b); }
template<typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> prime;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            prime.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n!= 1) prime.push_back(n);

    int ans = 0;
    for (int p : prime) {
        int x = 0;
        while (n % p == 0) {
            n /= p;
            x++;
        }
        for (int i = 1; i <= x; i++) {
            ans += x / i;
        }
    }

    cout << ans << endl;

    return 0;
}

