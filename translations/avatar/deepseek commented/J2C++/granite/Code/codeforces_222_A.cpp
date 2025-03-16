

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, c = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            c++;
        } else {
            c = 1;
        }
        if (c + k > n) {
            cout << n - c << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

