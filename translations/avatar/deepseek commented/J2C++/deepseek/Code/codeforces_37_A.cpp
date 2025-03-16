#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create an instance of FastScanner to read input efficiently
    unordered_map<int, int> map;
    
    // Read the number of integers
    int n;
    cin >> n;
    
    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        map[val]++;
    }
    
    // Initialize max to the smallest possible integer value
    int max = INT_MIN;
    
    // Iterate through the hash map to find the maximum count
    for (auto& entry : map) {
        int value = entry.second;
        max = std::max(max, value);
    }
    
    // Print the maximum count and the size of the hash map
    cout << max << " " << map.size() << endl;
    
