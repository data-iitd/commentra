#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, gcd;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    gcd = __gcd ( n, m );
    cout << ( s.substr ( 0, gcd )!= t.substr ( 0, gcd )? -1 : n * m / gcd ) << endl;
    return 0;
}
