
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
        x += a[i];
        y += b[i];
        z += c[i];
    }

    cout << abs(x - y) << endl;
    cout << abs(y - z) << endl;

    return 0;
}
