
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long int ans = 0;
    long long int mod = 1000000007;
    long long int lcm = 1;
    for (int i = 0; i < n; i++) {
        lcm = lcm / __gcd(lcm, a[i]) * a[i];
    }
    for (int i = 0; i < n; i++) {
        ans = (ans + (a[i] / lcm) % mod) % mod;
    }
    cout << ans << "\n";
    return 0;
}

