#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    int array[3 * n];
    for (int i = 0; i < 3 * n; i++) {
        cin >> array[i];
    }
    sort(array, array + 3 * n);
    int head = 3 * n - 2;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }
    cout << res;
    return 0;
}

