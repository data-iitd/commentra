#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = n * (n + 1) / 4;
    int ans = 0;
    int l = 0, r = 1000000000;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
