#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int n, m, gcd;
    string s, t;

    cin >> n >> m;
    gcd = gcd(n, m);
    cin >> s >> t;

    for (int k = 0; k < gcd; k++) {
        if (s[k * n / gcd] != t[k * m / gcd]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << (long long)n * m / gcd << endl;

    return 0;
}

