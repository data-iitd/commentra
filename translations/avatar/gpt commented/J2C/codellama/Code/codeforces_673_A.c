#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creating a Scanner object to read input from the user
    int n;
    scanf("%d", &n);
    
    // Initializing an ArrayList to store the integer values
    int *a = (int *)malloc(n * sizeof(int));
    int value;
    
    // Loop to read 'n' integers from user input and add them to the ArrayList
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        a[i] = value;
    }
    
    // Variables to hold the result, position of the last valid number, and a flag
    int result, pos = 0, flag = 0;
    
    // Check if the first element is greater than 15
    if (a[0] > 15) {
        result = 15; // If true, set result to 15
    } else {
        // Loop through the ArrayList to find the first gap greater than 15
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > 15) {
                pos = i - 1; // Store the position of the last valid number
                flag = 1; // Set flag to indicate a gap was found
                break; // Exit the loop as we found the gap
            }
        }
        // If a gap was found, calculate the result based on the last valid number
        if (flag == 1) {
            result = a[pos] + 15;
        } else {
            // If no gap was found, set result based on the last number in the list
            result = a[n - 1] + 15;
        }
    }
    
    // Ensure the result does not exceed 90
    if (result > 90) {
        result = 90; // Cap the result at 90
    }
    
    // Output the final result
    printf("%d", result);
    
    // Free the memory allocated for the ArrayList
    free(a);
    
    return 0;
}

