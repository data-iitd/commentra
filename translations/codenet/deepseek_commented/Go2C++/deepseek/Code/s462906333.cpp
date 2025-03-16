#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

const long long INF = 1e14; // Define a large value to represent infinity for cost comparisons

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = INF;
    for (int k = 0; k < n; k++) {
        long long kans = 0;
        vector<int> v = a;
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

    cout << ans << '\n';
    return 0;
}

