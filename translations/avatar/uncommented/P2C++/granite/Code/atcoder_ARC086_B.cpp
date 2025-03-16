
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_val = 0, max_sign = 0, max_index = -1;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = (a[i] > 0) - (a[i] < 0);
            max_index = i;
        }
    }
    if (max_sign == 0) {
        cout << 0 << endl;
    } else if (max_sign == 1) {
        cout << 2 * n - 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = 0; i < n - 1; i++) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        cout << 2 * n - 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = n - 1; i > 0; i--) {
            cout << i + 1 << " " << i << endl;
        }
    }
    return 0;
}

