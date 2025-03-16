#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reva(vector<int>& b) {
    reverse(b.begin(), b.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int b, e;
        cin >> b >> e;
        reva(vector<int>(a.begin() + b, a.begin() + e));
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

// <END-OF-CODE>
