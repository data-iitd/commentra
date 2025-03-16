

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 2;
    }
    long long lcm = 1;
    for (int i = 0; i < n; i++) {
        long long g = gcd(lcm, a[i]);
        lcm = lcm * a[i] / g;
        if (lcm > m) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((lcm / a[i]) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (m / lcm + 1) / 2 << endl;
    return 0;
}
