#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n; // Number of elements
    cin >> n; // Read the number of elements
    vector<int> ara(n); // Initialize vector to store elements
    unordered_map<int, int> map; // Unordered map to count occurrences of each element

    // Populate the vector and the map with element counts
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; // Read each element
        ara[i] = v;
        map[v]++; // Increment count for the element
    }

    int max_freq = 0; // Initialize max_freq to track the highest frequency
    // Find the maximum frequency in the map
    for (const auto& pair : map) {
        max_freq = max(max_freq, pair.second);
    }

    unordered_map<int, int> mm; // Unordered map to track occurrences as elements appear
    // Find the most frequent element
    for (int i = 0; i < n; i++) {
        mm[ara[i]]++; // Increment count for the element
        if (mm[ara[i]] == max_freq) {
            cout << ara[i] << endl; // Print the most frequent element
            break; // Exit the loop after finding the most frequent element
        }
    }

    return 0; // End of the program
}

// <END-OF-CODE>
