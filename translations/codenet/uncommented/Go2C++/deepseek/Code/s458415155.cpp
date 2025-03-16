#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int iabs(int x) {
    return x < 0 ? -x : x;
}

int solve(int n, vector<int>& heights) {
    vector<int> t(n+1, INT_MAX);
    t[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (t[i-1] + iabs(heights[i] - heights[i-1]) < t[i]) {
            t[i] = t[i-1] + iabs(heights[i] - heights[i-1]);
        }
        if (i > 1 && t[i-2] + iabs(heights[i] - heights[i-2]) < t[i]) {
            t[i] = t[i-2] + iabs(heights[i] - heights[i-2]);
        }
    }
    return t[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    int ans = solve(n, heights);
    cout << ans << endl;
    return 0;
}

