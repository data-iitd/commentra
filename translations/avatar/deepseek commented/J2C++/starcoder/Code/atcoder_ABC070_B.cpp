
#include <bits/stdc++.h>
using namespace std;

// Define a nested static class for reading input from the standard input stream

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c > b) {
        cout << 0 << endl;
    } else if (a > d) {
        cout << 0 << endl;
    } else if (a < c) {
        cout << min(b, d) - c << endl;
    } else {
        vector<int> l;
        l.push_back(a);
        l.push_back(b);
        l.push_back(c);
        l.push_back(d);
        sort(l.begin(), l.end());
        cout << l[2] - l[1] << endl;
    }
    return 0;
}

