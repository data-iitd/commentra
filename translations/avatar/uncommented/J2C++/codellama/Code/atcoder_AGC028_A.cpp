#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n, m, gcd;
    cin >> n >> m;
    gcd = gcd(n, m);
    string s, t;
    cin >> s >> t;
    cout << accumulate(s.begin(), s.begin() + gcd, 0, [&](int a, int b) {
        return a + (s[b] != t[b]);
    }) << endl;
    return 0;
}
