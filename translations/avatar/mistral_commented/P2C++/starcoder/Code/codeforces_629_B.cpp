#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int m[N], f[N];
    for (int i = 0; i < N; i++) {
        cin >> m[i] >> f[i];
    }

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < N; i++) {
        a += m[i];
        b += f[i];
        c = min(a, b);
    }

    cout << c << "\n";

    return 0;
}

