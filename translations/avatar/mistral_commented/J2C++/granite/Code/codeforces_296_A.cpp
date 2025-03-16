

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1001] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int max_freq = -1;
    for (int i = 1; i <= 1000; i++) {
        max_freq = max(max_freq, a[i]);
    }
    if (n % 2 == 0) {
        if (max_freq <= n / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (max_freq <= n / 2 + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

