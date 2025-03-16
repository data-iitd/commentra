#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int nextInt() {
    int i;
    cin >> i;
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = nextInt();
    int m = nextInt();
    vector<int> h(n);
    vector<bool> good(n, true);

    for (int i = 0; i < n; i++) {
        h[i] = nextInt();
    }

    for (int i = 0; i < m; i++) {
        int ai = nextInt() - 1;
        int bi = nextInt() - 1;
        if (h[ai] > h[bi]) {
            good[bi] = false;
        } else if (h[ai] < h[bi]) {
            good[ai] = false;
        } else {
            good[ai] = false;
            good[bi] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
