
#include <bits/stdc++.h>
using namespace std;

int modPower(int x, int y, int mod) {
    int res = 1;
    x %= mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main() {
    long a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    cout << max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])));
    return 0;
}

