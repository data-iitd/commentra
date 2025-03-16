#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class FastScanner {
public:
    FastScanner() {
        // Initialize input stream
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    int nextInt() {
        int val;
        cin >> val;
        return val;
    }
};

int main() {
    // Create a FastScanner object to read input efficiently
    FastScanner input;

    // Read the number of integers to be processed
    int n = input.nextInt();

    // Initialize an unordered_map to store the frequency of each integer
    unordered_map<int, int> map;

    // Loop through the input integers and populate the frequency map
    for (int i = 0; i < n; i++) {
        int val = input.nextInt();
        // Update the count of the integer in the map
        map[val]++;
    }

    // Initialize a variable to track the maximum frequency found
    int max = INT_MIN;

    // Iterate through the entries in the frequency map to find the maximum frequency
    for (const auto& entry : map) {
        int value = entry.second;
        // Update max if the current frequency is greater than the current max
        max = std::max(max, value);
    }

    // Print the maximum frequency and the number of unique integers
    cout << max << map.size() << endl;

    return 0;
}

// <END-OF-CODE>
