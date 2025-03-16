#include <iostream>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

class FastReader {
public:
    FastReader() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
};

int main() {
    FastReader in;

    // Read the number of elements
    int n = in.nextInt();

    // Create a set to keep track of available positions on the left
    set<int> left;

    // Initialize a vector to store the answers
    vector<int> answer(n, 0);

    // Populate the set with indices from 0 to n-1
    for (int i = 0; i < n; i++) {
        left.insert(i);
    }

    // Read the number of queries
    int q = in.nextInt();

    // Process each query
    while (q-- > 0) {
        // Read the range [l, r] and the winning index
        int l = in.nextInt() - 1;
        int r = in.nextInt() - 1;
        int win = in.nextInt();

        // Update the answer vector for all positions in the range [l, r]
        auto it = left.lower_bound(l);
        while (it != left.end() && *it <= r) {
            int curr = *it; // Get the smallest index >= l
            answer[curr] = win; // Set the answer for this position
            it = left.erase(it); // Remove this position from available positions
        }

        // Mark the winning index as available again
        answer[win - 1] = 0;
        left.insert(win - 1); // Add the winning index back to available positions
    }

    // Build the output string from the answer vector
    stringstream ans;
    for (int i = 0; i < n; i++) {
        ans << answer[i] << " "; // Append each answer to the stringstream
    }

    // Print the final answer
    cout << ans.str() << endl;

    return 0;
}

// <END-OF-CODE>
