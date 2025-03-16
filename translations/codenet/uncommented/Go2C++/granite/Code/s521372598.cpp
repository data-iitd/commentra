
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = a[i] - i + 1;
    }
    sort(x.begin(), x.end());

    int b = x[n/2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(x[i] - b);
    }
    cout << ans << endl;

    return 0;
}

