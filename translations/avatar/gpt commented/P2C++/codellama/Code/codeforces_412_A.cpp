#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    string v;
    string d[2] = {"LEFT", "RIGHT"};
    bool f;
    int m;
    string a[100000];
    int i;

    cin >> n >> k;
    cin >> v;

    f = k - 1 < n - k;
    m = min(k - 1, n - k);

    for (i = 0; i < m; i++) {
        a[i] = d[!f];
    }

    for (i = 0; i < v.length(); i++) {
        a[i + m] = "PRINT " + v[i];
        a[i + m + 1] = d[f];
    }

    for (i = 0; i < v.length() + m + 1; i++) {
        cout << a[i] << endl;
    }

    return 0;
}

