#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool found = false;
    for (int i = 0; i < a.size(); i++) {
        if (i + 1 < a.size() && i + 2 < a.size()) {
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
                found = true;
            }
        }
    }
    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
