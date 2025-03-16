

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int max = 0;

    while (n-- > 0) {
        int f, t;
        cin >> f >> t;

        if (max < f + t) {
            max = f + t;
        }
    }

    cout << max << endl;

    return 0;
}

