#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int gcd = __gcd(n, m);
    string s, t;
    cin >> s >> t;

    cout << IntStream(0, gcd).filter(k -> s[k * n / gcd]!= t[k * m / gcd]).mapToLong(k -> -1).findAny().orElse(
        n * m / gcd
    ) << endl;
}

