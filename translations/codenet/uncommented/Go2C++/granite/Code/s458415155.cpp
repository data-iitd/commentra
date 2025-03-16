
```cpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(int n, vector<int> &heights) {
    vector<int> t(n+1, INT_MAX);
    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (t[i-1] + abs(heights[i]-heights[i-1]) < t[i]) {
            t[i] = t[i-1] + abs(heights[i]-heights[i-1]);
        }
        if (1 < i && t[i-2] + abs(heights[i]-heights[i-2]) < t[i]) {
            t[i] = t[i-2] + abs(heights[i]-heights[i-2]);
        }
    }
    return t[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << solve(n, heights) << endl;
    return 0;
}

