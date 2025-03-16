#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read an integer input which represents the number of elements
    int n;
    cin >> n;
    
    // Read a line of input, split it by spaces, and convert it to a list of integers
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    // Initialize the current level and counters
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;  // Start with -1 to account for the first turn increment
    
    // Loop until all elements have been processed
    while (counter < a.size()) {
        counter_turns += 1;  // Increment the turn counter
        
        // Iterate through the list to find elements that can be processed
        for (int i = 0; i < a.size(); i++) {
            // Check if the current element is not marked (-1) and is less than or equal to the current counter
            if (a[i]!= -1 && a[i] <= counter) {
                counter += 1;  // Increment the counter as we can process this element
                a[i] = -1;  // Mark the element as processed by setting it to -1
        }
        
        // Reverse the list to prepare for the next round of processing
        reverse(a.begin(), a.end());
    }
    
    // Print the total number of turns taken to process all elements
    cout << counter_turns << endl;
}

