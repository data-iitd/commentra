#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creating a Scanner object to read input from the console
    int n, d;
    scanf("%d %d", &n, &d);
    
    // Initializing an array to hold the numbers
    int* nums = (int*) malloc(n * sizeof(int));
    
    // Reading n integers from user input and storing them in the nums array
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    // Initializing result variable to count the total adjustments made
    int result = 0;
    int a = 0; // Variable to hold the difference between consecutive elements
    
    // Looping through the nums array starting from the second element
    for (int i = 1; i < n; i++) {
        // Calculating the difference between the previous and current element
        a = (nums[i - 1] - nums[i]);
        
        // If the difference is non-negative, adjustments are needed
        if (a >= 0) {
            // Calculating how many times we can adjust the current element
            result += a / d + 1; 
            
            // Adjusting the current element to maintain the required condition
            nums[i] += (a / d + 1) * d; 
        }
    }
    
    // Printing the total number of adjustments made
    printf("%d", result);
    
    return 0;
}

