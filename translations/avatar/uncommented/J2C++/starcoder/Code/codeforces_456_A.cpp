#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int q = 0, w = 0, e = 0;
    bool f = false;
    for (int i = 0; i < n; i++) {
        if (q < b[i]) {
            q = b[i];
        }
        if (a[i] > w) {
            w = a[i];
            if (b[i] < e) {
                f = true;
            }
            e = b[i];
        }
        if (a[i] < w) {
            if (b[i] > e) {
                f = true;
            }
        }
    }
    if (f) {
        cout << "Happy Alex" << endl;
    } else {
        cout << "Poor Alex" << endl;
    }
    return 0;
}
