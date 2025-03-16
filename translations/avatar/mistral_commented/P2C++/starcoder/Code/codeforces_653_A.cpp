
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    for (int i = 0; i < n; i++) {
        if (l[i] + 1 < n && l[i] + 2 < n) {
            cout << "YES" << endl;
            break;
        }
    }
    if (i == n - 1) {
        cout << "NO" << endl;
    }
    return 0;
}

