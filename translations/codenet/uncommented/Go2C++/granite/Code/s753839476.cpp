
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, a;
    cin >> n >> t >> a;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int minDiff = abs(t - heights[0] * 0.006 - a);
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        int diff = abs(t - heights[i] * 0.006 - a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i + 1;
        }
    }
    cout << minIdx << endl;

    return 0;
}

