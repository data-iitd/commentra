
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    long long b = pow(2, n);
    long long a = pow(2, n - 2);
    long long ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % 1000000007;
        val *= c[n + 1 - i];
        val %= 1000000007;
        ans += val;
        ans %= 1000000007;
    }
    ans *= b;
    ans %= 1000000007;
    cout << ans << endl;
    return 0;
}

