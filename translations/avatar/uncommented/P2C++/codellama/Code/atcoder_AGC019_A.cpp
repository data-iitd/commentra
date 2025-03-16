
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    int best1L = min(q * 4, h * 2, s);
    int best2L = min(d, best1L * 2);
    if (n % 2 == 0) {
        cout << best2L * (n / 2) << endl;
    } else {
        cout << best2L * (n / 2) + best1L << endl;
    }
    return 0;
}

