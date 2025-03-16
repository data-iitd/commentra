
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    // Read the number of required items (n) and the number of available items (m)
    int n, m;
    cin >> n >> m;

    // Initialize vectors to store the required items and the available items
    vector<int> req(n);
    vector<int> pre(m);

    // Read the required items from the input and store them in the req vector
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }

    // Read the available items from the input and store them in the pre vector
    for (int i = 0; i < m; i++) {
        cin >> pre[i];
    }

    // Sort the required items and the available items in descending order
    sort(req.begin(), req.end(), greater<int>());
    sort(pre.begin(), pre.end(), greater<int>());

    // Initialize pointers for the required items (i) and available items (j)
    int i = 0, j = 0;

    // Variable to count how many required items can be satisfied
    int ans = 0;

    // Compare the required items with the available items from the end of both vectors
    while (i < n && j < m) {
        // If the current required item is greater than the current available item
        if (req[i] > pre[j]) {
            // Increment the count of satisfied items
            ans++;
            // Move to the next required item
            i++;
        } else {
            // Move to the next available item if the current one cannot satisfy the requirement
            j++;
        }
    }

    // Print the total number of satisfied items plus the remaining unsatisfied required items
    cout << ans + n - i << endl;

    return 0;
}
