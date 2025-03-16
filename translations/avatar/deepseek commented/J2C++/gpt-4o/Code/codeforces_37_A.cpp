#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // Read the number of integers
    int n;
    cin >> n;

    // Create an unordered_map to store the frequency of each integer
    unordered_map<int, int> map;

    // Read n integers and update their counts in the unordered_map
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        map[val]++;
    }

    // Initialize max to the smallest possible integer value
    int max_count = numeric_limits<int>::min();

    // Iterate through the unordered_map to find the maximum count
    for (const auto& entry : map) {
        max_count = max(max_count, entry.second);
    }

    // Print the maximum count and the size of the unordered_map
    cout << max_count << map.size() << endl;

    return 0;
}

// <END-OF-CODE>
