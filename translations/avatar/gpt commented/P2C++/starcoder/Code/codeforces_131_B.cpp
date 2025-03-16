#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements
    int n; cin >> n;

    // Read the elements and count their occurrences using Counter
    map<int, int> w;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        w[x]++;
    }

    // Initialize a counter for pairs that sum to zero
    int c = 0;

    // Iterate through each unique number in the counter
    for (auto i : w) {
        // Check if the number is zero
        if (i.first == 0) {
            // For zero, count pairs (w[i] choose 2) since both numbers are the same
            c += w[i.first] * (w[i.first] - 1);
        } else {
            // Check if the negative counterpart exists in the counter
            if (-i.first in w) {
                // Count pairs formed by the number and its negative counterpart
                c += w[i.first] * w[-i.first];
            }
        }
    }

    // Since each pair is counted twice, divide the total count by 2 before printing
    cout << c / 2 << endl;

    return 0;
}

