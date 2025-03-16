#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector<int> a(5);
    vector<int> r(5);
    map<int, int> m;

    // Step 2: Reading input and storing remainders
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        r[i] = a[i] % 10;
        int b = 10;
        if (r[i] != 0) {
            b = 10 - r[i];
            m[b] = a[i];
        }
    }

    // Step 3: Handling edge cases
    if (m.size() == 0) {
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            ans += a[i];
        }
        cout << ans << endl;
        return 0;
    }

    // Step 4: Finding the maximum and adjusting values
    int last = m.rbegin()->second; // Get the last element (maximum key)
    int idx = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == last) {
            idx = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
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

// <END-OF-CODE>
