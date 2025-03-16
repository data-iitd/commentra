#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k = accumulate(a, a + n, 0) / (n * (n + 1) / 2);

    a[n] = a[0];
    if (accumulate(a + 1, a + n + 1, 0) % n ||
        accumulate(a + 1, a + n + 1, 0) / n < 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}

