
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q, b, e;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> b >> e;
        reverse(a.begin() + b, a.begin() + e);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    return 0;
}

