#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i] * 2 && a[i]!= a[i + 1]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}

