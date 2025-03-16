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
        if (find(l.begin(), l.end(), l[i] + 1) != l.end() && find(l.begin(), l.end(), l[i] + 2) != l.end()) {
            cout << "YES" << endl;
            break;
        }
    }
    if (i == n) {
        cout << "NO" << endl;
    }
    return 0;
}

