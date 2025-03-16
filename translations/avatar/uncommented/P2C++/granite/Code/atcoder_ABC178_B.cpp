
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({a * c, b * d, a * d, b * c});
    return 0;
}
// END-OF-CODE