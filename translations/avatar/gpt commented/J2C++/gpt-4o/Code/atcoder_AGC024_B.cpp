#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // Create a variable to read the number of elements
    int N;
    cin >> N;

    // Initialize a vector to store the elements, adjusting for zero-based indexing
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        P[i]--; // Store input values after decrementing by 1
    }

    // Create a map to store the index of each element for quick lookup
    unordered_map<int, int> map;
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i; // Map each value to its index
    }

    // Vector to store indices where the order is not increasing
    vector<int> nglist;
    for (int i = 0; i < N - 1; ++i) {
        // Check if the current index is greater than the next index in the map
        if (map[i] > map[i + 1]) {
            nglist.push_back(i); // Add the index to the nglist if the order is violated
        }
    }

    // If there are no indices in nglist, print 0 and exit
    if (nglist.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // Calculate the minimum number of moves required to fix the order
    int ans = min(N - nglist[0] - 1, nglist.back() + 1);
    for (size_t i = 0; i < nglist.size() - 1; ++i) {
        // Update ans with the minimum moves needed between consecutive indices in nglist
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans);
    }

    // Print the result which is the minimum number of moves
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
