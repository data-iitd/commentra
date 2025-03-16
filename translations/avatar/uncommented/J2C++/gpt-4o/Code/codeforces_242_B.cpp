#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 5;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int left = INF, right = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        left = min(left, a[i]);
        right = max(right, b[i]);
    }

    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            cout << (i + 1) << endl; // Output is 1-based index
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}

// <END-OF-CODE>
