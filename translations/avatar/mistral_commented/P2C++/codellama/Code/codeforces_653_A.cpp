
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
    for (int i = 0; i < n - 2; i++) {
        if (l[i] + 1 == l[i + 1] && l[i] + 2 == l[i + 2]) {
            cout << "YES" << endl;
            break;
        }
    }
    if (i == n - 2) {
        cout << "NO" << endl;
    }
    return 0;
}

