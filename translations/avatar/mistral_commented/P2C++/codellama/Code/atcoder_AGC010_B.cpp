#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    k = 0;
    for (int i = 0; i < n; i++) {
        k += a[i];
    }
    k /= (n * (n + 1) / 2);

    a.push_back(a[0]);
    for (int i = 1; i <= n; i++) {
        if ((k - a[i] + a[i - 1]) % n || (k - a[i] + a[i - 1]) / n < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

