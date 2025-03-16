//go:generate echo "https://atcoder.jp/contests/dp/tasks/dp_a"
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int solve(int n, const vector<int>& heights) {
    vector<int> t(n + 1, numeric_limits<int>::max());
    t[0] = 0;

    for (int i = 1; i < n; i++) {
        t[i] = min(t[i], t[i - 1] + abs(heights[i] - heights[i - 1]));
        if (i > 1) {
            t[i] = min(t[i], t[i - 2] + abs(heights[i] - heights[i - 2]));
        }
    }

    return t[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int ans = solve(n, heights);
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
