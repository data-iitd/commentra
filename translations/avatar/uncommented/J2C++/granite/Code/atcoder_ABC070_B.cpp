
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c > b) {
        cout << 0 << endl;
    } else if (a > d) {
        cout << 0 << endl;
    } else if (a < c) {
        cout << min(b, d) - c << endl;
    } else {
        vector<int> v = {a, b, c, d};
        sort(v.begin(), v.end());
        cout << v[2] - v[1] << endl;
    }
    return 0;
}
// END-OF-CODE