#include <bits/stdc++.h>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit);
    int n, m;
    cin >> n >> m;
    int arr[n];
    int gen[11];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        gen[arr[i]]++;
    }
    long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= m; k++) {
            if (i!= k) {
                ans += (long) gen[i] * gen[k];
            }
        }
    }
    cout << ans / 2 << "\n";
    return 0;
}

