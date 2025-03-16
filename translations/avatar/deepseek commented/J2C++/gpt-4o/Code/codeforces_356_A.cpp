#include <iostream>
#include <set>
#include <vector>
#include <string>
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
    FastReader in; // Initialize FastReader for fast input
    int n = in.nextInt(); // Read the value of n
    set<int> left; // Initialize a set to keep track of indices
    vector<int> answer(n, 0); // Initialize a vector to store the results

    for (int i = 0; i < n; i++) {
        left.insert(i); // Add indices from 0 to n-1 to the set
    }

    int q = in.nextInt(); // Read the number of queries
    while (q-- > 0) { // Process each query
        int l = in.nextInt() - 1; // Read the left index and adjust for 0-based indexing
        int r = in.nextInt() - 1; // Read the right index and adjust for 0-based indexing
        int win = in.nextInt(); // Read the winning index

        auto it = left.lower_bound(l); // Get the iterator to the first element >= l
        while (it != left.end() && *it <= r) { // While there are elements in the range
            int curr = *it; // Get the current element
            answer[curr] = win; // Assign the winning index to the current element
            it = left.erase(it); // Remove the current element from the set and get the next iterator
        }
        answer[win - 1] = 0; // Set the winning index (adjusted for 0-based indexing) to 0
        left.insert(win - 1); // Add the winning index back to the set
    }

    stringstream ans; // Initialize a stringstream for efficient string concatenation
    for (int i = 0; i < n; i++) {
        ans << answer[i]; // Append each element of the answer vector to the stringstream
    }
    cout << ans.str() << endl; // Print the final result

    return 0;
}

// <END-OF-CODE>
