#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<int> left;
    vector<int> answer(n, -1);

    // Adding all the indices to the set and initializing the answer array with -1
    for (int i = 0; i < n; i++) {
        left.insert(i);
    }

    int q;
    cin >> q;

    // Processing each query
    while (q--) {
        int l, r, win;
        cin >> l >> r >> win;
        l--; r--; // Convert to 0-based index
        win--; // Convert to 0-based index

        // Update the answer for the winning index and all the indices between the left and right indices
        auto it = left.lower_bound(l);
        while (it != left.end() && *it <= r) {
            int curr = *it;
            answer[curr] = win;
            it = left.erase(it);
        }

        // Update the answer for the winning index in the answer array
        answer[win] = 0;

        // Add the winning index back to the set
        left.insert(win);
    }

    // Print the answer for each index in the answer array
    for (int i = 0; i < n; i++) {
        cout << answer[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}
