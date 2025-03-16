
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    vector<bool> good(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        good[i] = true;
    }

    for (int i = 0; i < m; i++) {
        int ai, bi;
        cin >> ai >> bi;

        if (h[ai - 1] > h[bi - 1]) {
            good[bi - 1] = false;
        } else if (h[ai - 1] < h[bi - 1]) {
            good[ai - 1] = false;
        } else {
            good[ai - 1] = false;
            good[bi - 1] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

