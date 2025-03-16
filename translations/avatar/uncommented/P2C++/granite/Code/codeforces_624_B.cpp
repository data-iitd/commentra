
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0, pre = 1e9;
    for (int i = 0; i < n; i++) {
        ans += max(0, min(pre - 1, a[i]));
        pre = max(0, min(pre - 1, a[i]));
    }
    cout << ans << endl;
    return 0;
}

