
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int iabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int solve(int n, vector<int> heights) {
    vector<int> t(n+1, 1000000000);
    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (t[i-1] + iabs(heights[i]-heights[i-1]) < t[i]) {
            t[i] = t[i-1] + iabs(heights[i]-heights[i-1]);
        }
        if (1 < i) {
            if (t[i-2] + iabs(heights[i]-heights[i-2]) < t[i]) {
                t[i] = t[i-2] + iabs(heights[i]-heights[i-2]);
            }
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

