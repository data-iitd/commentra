

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    int k;
    cin >> a >> b >> c >> k;

    vector<int> patterns;
    for (int i = 0; i < (1 << k); i++) {
        int r = a, g = b, b = c;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                if (j == 0) r *= 2;
                if (j == 1) g *= 2;
                if (j == 2) b *= 2;
            }
        }
        if (g > r && b > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}

