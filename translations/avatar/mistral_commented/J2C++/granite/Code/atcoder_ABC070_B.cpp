

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (c > b) {
        cout << 0 << endl;
        return 0;
    }

    if (a > d) {
        cout << 0 << endl;
        return 0;
    }

    if (a < c) {
        int diff = min(b, d) - c;
        cout << diff << endl;
        return 0;
    }

    vector<int> v = {a, b, c, d};
    sort(v.begin(), v.end());

    int diff = v[2] - v[1];
    cout << diff << endl;

    return 0;
}

