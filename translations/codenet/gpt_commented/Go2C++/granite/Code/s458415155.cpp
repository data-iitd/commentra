
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> t(n, 1e9);
    t[0] = 0;
    for (int i = 1; i < n; i++) {
        t[i] = min(t[i-1] + abs(heights[i] - heights[i-1]), t[i]);
        if (i >= 2) {
            t[i] = min(t[i-2] + abs(heights[i] - heights[i-2]), t[i]);
        }
    }

    cout << t[n-1] << endl;

    return 0;
}
