
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, m, gcd;
    string s, t;
    cin >> n >> m;
    gcd = __gcd(n, m);
    cin >> s >> t;
    for (int i = 0; i < gcd; i++) {
        if (s[i * n / gcd]!= t[i * m / gcd]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << (long long)n * m / gcd << endl;
    return 0;
}

