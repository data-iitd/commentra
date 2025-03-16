#include <bits/stdc++.h>

using namespace std;

int main() {
    // Record the start time for performance measurement
    auto start = chrono::high_resolution_clock::now();

    // Create a Scanner object for input
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit);
    cout.exceptions(ios::badbit);
    istream& cin = ws;
    int n;
    cin >> n;
    long long A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    long long ans = 0;
    for (int i = 0; i < 60; i++) {
        long long a = 0;
        long long count1 = 0;
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i & 1) == 1) {
                count1++;
            }
        }
        a = a + count1 * (n - count1);
        for (int j = 0; j < i; j++) {
            a = (a << 1) % 1000000007;
        }
        ans += a;
        ans %= 1000000007;
    }
    cout << ans << "\n";

    // Record the end time for performance measurement
    auto stop = chrono::high_resolution_clock::now();

    // Elapsed time in milliseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << duration.count() << " ms" << "\n";
}

