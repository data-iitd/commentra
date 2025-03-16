#include <iostream>
#include <vector>
#include <sstream>

void main_function() {
    // Read an integer input which represents the number of elements
    int n;
    std::cin >> n;
    
    // Read a line of input and convert it to a vector of integers
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    // Initialize the current level and counters
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;  // Start with -1 to account for the first turn increment
    
    // Loop until all elements have been processed
    while (counter < a.size()) {
        counter_turns++;  // Increment the turn counter
        
        // Iterate through the vector to find elements that can be processed
        for (int i = 0; i < a.size(); ++i) {
            // Check if the current element is not marked (-1) and is less than or equal to the current counter
            if (a[i] != -1 && a[i] <= counter) {
                counter++;  // Increment the counter as we can process this element
                a[i] = -1;  // Mark the element as processed by setting it to -1
            }
        }
        
        // Reverse the vector to prepare for the next round of processing
        std::reverse(a.begin(), a.end());
    }
    
    // Print the total number of turns taken to process all elements
    std::cout << counter_turns << std::endl;
}

// Call the main function to execute the code
int main() {
    main_function();
    return 0;
}

// <END-OF-CODE>
