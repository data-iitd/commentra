
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % (n * (n + 1) / 2)!= 0) {
        cout << "NO" << endl;
    } else {
        int k = sum / (n * (n + 1) / 2);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = (k - a[i] + a[(i + 1) % n]) % n;
        }
        if (accumulate(b.begin(), b.end(), 0)!= 0) {
            cout << "NO" << endl;
        } else {
            vector<int> c(n);
            for (int i = 0; i < n; i++) {
                c[i] = (k - a[i] + a[(i + 1) % n]) / n;
            }
            if (accumulate(c.begin(), c.end(), 0) >= 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

