#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, h, s, d;
    cin >> q >> h >> s >> d;
    int n;
    cin >> n;

    int best1L = min(q * 4, h * 2, s);
    int best2L = min(d, best1L * 2);

    if (n % 2 == 0) {
        cout << best2L * (n / 2);
    } else {
        cout << best2L * (n / 2) + best1L;
    }

    return 0;
}

