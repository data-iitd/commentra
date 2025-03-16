#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    sort(c.rbegin(), c.rend());
    
    long long b = pow(2, 2 * n - 2) % mod;
    long long a = (2 * b) % mod;
    long long ans = 0;
    
    for (int i = 0; i < n; ++i) {
        ans = (ans + c[i] * (a + i * b)) % mod;
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
