#include <iostream>
#include <vector>
#include <algorithm>

void main_function() {
    // Read the number of elements from the user
    int n;
    std::cin >> n;
    
    // Read the list of integers from the user input
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    // Initialize variables to track the current level and the number of turns
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;
    
    // Start a while loop that continues until all elements are processed
    while (counter < n) {
        // Increment the turn counter
        counter_turns++;
        // Iterate over the list 'a' to process each element
        for (int i = 0; i < n; ++i) {
            // Check if the element is not -1 and is less than or equal to the current level
            if (a[i] != -1 && a[i] <= current_level) {
                // Increment the counter and mark the element as processed
                counter++;
                a[i] = -1;
            }
        }
        // Reverse the list 'a' to process elements in a different order in the next iteration
        std::reverse(a.begin(), a.end());
    }
    
    // Print the number of turns taken to process all elements
    std::cout << counter_turns << std::endl;
}

int main() {
    main_function();
    return 0;
}

