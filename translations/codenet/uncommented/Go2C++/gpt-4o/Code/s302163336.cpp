#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<bool> good(n, true);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < m; i++) {
        int ai, bi;
        cin >> ai >> bi;
        ai--; // Convert to 0-based index
        bi--; // Convert to 0-based index
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

    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
