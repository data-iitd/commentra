#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N; // Read the number of elements in the array P
    vector<int> P(N); // Initialize the array P with N elements
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        P[i]--; // Read each element and adjust to 0-based index
    }

    // Create an unordered_map to map each value in P to its index
    unordered_map<int, int> map;
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }

    // Create a vector to store indices of elements that are out of order
    vector<int> nglist;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist.push_back(i); // Add the index to nglist if the current element is greater than the next element
        }
    }

    // If nglist is empty, the array P is already sorted
    if (nglist.empty()) {
        cout << 0 << endl; // Print 0 and return as the array is sorted
        return 0;
    }

    // Calculate the minimum number of swaps required to sort the array P
    int ans = min(N - nglist[0] - 1, nglist.back() + 1);
    for (size_t i = 0; i < nglist.size() - 1; ++i) {
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans);
    }

    // Print the minimum number of swaps required
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
