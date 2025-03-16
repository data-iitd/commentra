#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    int c = 0;
    for (int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;

        int x = t - (s - f);
        if (x > c) {
            c = x;
        }
    }

    cout << s + c << "\n";

    return 0;
}

