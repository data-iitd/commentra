
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    for (int i = 0; i < n - 2; i++) {
        if (binary_search(l.begin(), l.end(), l[i] + 1) && binary_search(l.begin(), l.end(), l[i] + 2)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

