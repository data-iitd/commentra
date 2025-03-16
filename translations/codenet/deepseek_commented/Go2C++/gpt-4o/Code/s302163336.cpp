#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Read the number of elements and comparisons
    vector<int> h(n); // Initialize vector to store heights
    vector<bool> good(n, true); // Initialize vector to track "good" status

    for (int i = 0; i < n; i++) {
        cin >> h[i]; // Read the height of each element
    }

    for (int i = 0; i < m; i++) {
        int ai, bi;
        cin >> ai >> bi; // Read the indices
        ai--; // Adjust for 0-based index
        bi--; // Adjust for 0-based index

        if (h[ai] > h[bi]) { // Compare heights and update "good" status
            good[bi] = false; // Mark the second element as not good if overshadowed
        } else if (h[ai] < h[bi]) {
            good[ai] = false; // Mark the first element as not good if overshadowed
        } else {
            good[ai] = false; // Mark both elements as not good if heights are equal
            good[bi] = false;
        }
    }

    int ans = 0; // Initialize the count of good elements
    for (int i = 0; i < n; i++) {
        if (good[i]) { // Count the elements that are still good
            ans++;
        }
    }

    cout << ans << endl; // Print the number of good elements
    return 0;
}

// <END-OF-CODE>
