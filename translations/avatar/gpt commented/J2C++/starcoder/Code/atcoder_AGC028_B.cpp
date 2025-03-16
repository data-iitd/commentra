#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;
    
    // Read the elements
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Initialize the cumulative sums
    vector<long long> q(n);
    q[0] = 1;
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + (i + 1) * (modinv(i + 1, 1000000007))) % 1000000007;
    }
    
    // Initialize the answer
    long long ans = 0;
    
    // Calculate the answer
    for (int i = 0; i < n; i++) {
        long long val = q[i] + q[n - i - 1] - 1;
        val *= a[i];
        val %= 1000000007;
        val *= (1LL * (n - i) * (n - i + 1) / 2) % 1000000007;
        val %= 1000000007;
        ans += val;
        ans %= 1000000007;
    }
    
    // Print the answer
    cout << ans << endl;
    
    return 0;
}

