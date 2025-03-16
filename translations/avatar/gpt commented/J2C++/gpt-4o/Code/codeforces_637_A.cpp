#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // Create an input stream for input and output stream for output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the number of elements
    int n;
    cin >> n;
    
    // Initialize a vector to store the elements
    vector<int> ara(n);
    
    // Create a map to count the frequency of each element
    unordered_map<int, int> map;
    
    // Read elements and populate the frequency map
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ara[i] = v;
        // Increment the count for the element
        map[v]++;
    }
    
    // Find the maximum frequency among the elements
    int max_freq = 0;
    for (const auto& pair : map) {
        max_freq = max(max_freq, pair.second);
    }
    
    // Create another map to track the order of elements while checking frequency
    unordered_map<int, int> mm;
    
    // Iterate through the original array to find the first element with maximum frequency
    for (int i = 0; i < n; i++) {
        if (mm[ara[i]] == 0) {
            mm[ara[i]] = 1;
            // Check if the current element's frequency matches the maximum frequency
            if (map[ara[i]] == max_freq) {
                cout << ara[i] << endl;
                break;
            }
        } else {
            // Increment the count for the existing element
            mm[ara[i]]++;
            // Check if the current element's frequency matches the maximum frequency
            if (map[ara[i]] == max_freq) {
                cout << ara[i] << endl;
                break;
            }
        }
    }
    
    return 0;
}

// <END-OF-CODE>
