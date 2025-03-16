#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5];
    int r[5];
    map<int, int> map;

    // Step 2: Reading input and storing remainders
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        r[i] = a[i] % 10;
        int b = 10;
        if (r[i] != 0) {
            b = 10 - r[i];
            map[b] = a[i];
        }
    }

    // Step 3: Handling edge cases
    if (map.size() == 0) {
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += a[i];
        }
        cout << ans << endl;
        return 0;
    }

    // Step 4: Finding the maximum and adjusting values
    int last = map.rbegin()->second;
    int idx = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] == last) {
            idx = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        if (i != idx) {
            if (a[i] % 10 == 0) {
                ans += a[i];
            } else {
                ans += a[i] + (10 - r[i]);
            }
        }
    }
    ans += last;
    cout << ans << endl;
    return 0;
}

