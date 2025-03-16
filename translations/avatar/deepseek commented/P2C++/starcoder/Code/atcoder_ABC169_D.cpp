#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    vector<int> fac;
    while (n % 2 == 0) {
        fac.push_back(2);
        n /= 2;
    }
    int f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            fac.push_back(f);
            n /= f;
        } else {
            f += 2;
        }
    }
    if (n!= 1) {
        fac.push_back(n);
    }
    map<int, int> fac_cnt;
    for (int i : fac) {
        fac_cnt[i]++;
    }
    for (auto it = fac_cnt.begin(); it!= fac_cnt.end(); it++) {
        int p = it->first;
        int e = it->second;
        int x = e;
        for (int i = 1; i < 99999999; i++) {
            if (x >= i) {
                x -= i;
                ans += 1;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

