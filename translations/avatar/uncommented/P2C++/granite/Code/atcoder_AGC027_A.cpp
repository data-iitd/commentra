
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    if (a[0] > x) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            x = 0;
            break;
        }
        x -= a[i];
        ans += 1;
    }
    if (x!= 0) {
        ans -= 1;
    }
    cout << ans << endl;
    return 0;
}

