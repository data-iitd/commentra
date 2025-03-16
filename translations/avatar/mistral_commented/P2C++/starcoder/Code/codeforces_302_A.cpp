#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int sa = 0;
    for (int i = 0; i < n; i++) {
        if (cin.get() == '-') sa++;
    }

    sa = min(n - sa, sa);

    vector<string> ss;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        b -= a;
        if (b % 2 == 0 or b > sa << 1) ss.push_back("1\n");
        else ss.push_back("0\n");
    }

    cout << string(ss.begin(), ss.end());

    return 0;
}

