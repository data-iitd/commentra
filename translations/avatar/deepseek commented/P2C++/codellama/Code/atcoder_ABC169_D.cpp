#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> fac_;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            fac_.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        fac_.push_back(n);
    }

    map<int, int> fac;
    for (int i = 0; i < fac_.size(); i++) {
        fac[fac_[i]]++;
    }

    int ans = 0;
    for (auto p : fac) {
        int x = p.second;
        for (int i = 1; i < 99999999; i++) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

