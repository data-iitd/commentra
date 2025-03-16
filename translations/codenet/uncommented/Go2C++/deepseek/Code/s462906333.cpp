#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

const long long INF = 1e14;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v = a;
    long long ans = INF;
    for (int k = 0; k < n; k++) {
        long long kans = 0;
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = min(v[i], a[n + i - k]);
            } else {
                v[i] = min(v[i], a[i - k]);
            }
            kans += v[i];
        }
        ans = min(ans, kans + k * x);
    }
    cout << ans << endl;
    return 0;
}

