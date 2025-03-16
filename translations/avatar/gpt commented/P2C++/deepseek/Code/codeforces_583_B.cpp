#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;  // Start with -1 to account for the first turn increment
    
    while (counter < n) {
        counter_turns += 1;  // Increment the turn counter
        
        // Iterate through the vector to find elements that can be processed
        for (int i = 0; i < n; ++i) {
            // Check if the current element is not marked (-1) and is less than or equal to the current counter
            if (a[i] != -1 && a[i] <= counter) {
                counter += 1;  // Increment the counter as we can process this element
                a[i] = -1;  // Mark the element as processed by setting it to -1
            }
        }
        
        // Reverse the vector to prepare for the next round of processing
        std::reverse(a.begin(), a.end());
    }
    
    // Print the total number of turns taken to process all elements
    std::cout << counter_turns << std::endl;
    
    return 0;
}

