#include <stdio.h>

void main_function() {
    // Read an integer input which represents the number of elements
    int n;
    scanf("%d", &n);
    
    // Read the elements into an array
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Initialize the current level and counters
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;  // Start with -1 to account for the first turn increment
    
    // Loop until all elements have been processed
    while (counter < n) {
        counter_turns++;  // Increment the turn counter
        
        // Iterate through the array to find elements that can be processed
        for (int i = 0; i < n; i++) {
            // Check if the current element is not marked (-1) and is less than or equal to the current counter
            if (a[i] != -1 && a[i] <= counter) {
                counter++;  // Increment the counter as we can process this element
                a[i] = -1;  // Mark the element as processed by setting it to -1
            }
        }
        
        // Reverse the array to prepare for the next round of processing
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
    }
    
    // Print the total number of turns taken to process all elements
    printf("%d\n", counter_turns);
}

int main() {
    main_function();
    return 0;
}

// <END-OF-CODE>
