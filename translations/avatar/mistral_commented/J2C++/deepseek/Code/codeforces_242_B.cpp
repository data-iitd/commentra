#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a, b;
    int left = INT_MAX, right = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        left = min(left, a[i]);
        right = max(right, b[i]);
    }

    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}

