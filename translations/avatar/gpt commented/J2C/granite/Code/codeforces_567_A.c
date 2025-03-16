
#include <stdio.h> // Include the standard input/output library

int main() {
    // Declare and initialize variables for the number of elements and the array
    int a, ar[a];
    
    // Read the number of elements from the user
    scanf("%d", &a);
    
    // Read the integers into the array
    for (int i = 0; i < a; i++) {
        scanf("%d", &ar[i]);
    }
    
    // Variables to hold the maximum and minimum differences
    int max = 0, min = 0;
    
    // Loop to calculate and print the min and max differences for each element
    for (int i = 0; i < a; i++) {
        // Calculate the maximum difference from the first and last elements
        max = (ar[i] - ar[0]) > (ar[a - 1] - ar[i])? (ar[i] - ar[0]) : (ar[a - 1] - ar[i]);
        
        // Calculate the minimum difference based on the position of the current element
        if (i == 0) {
            // If it's the first element, compare with the second element
            min = ar[i + 1] - ar[i];
        } else if (i == a - 1) {
            // If it's the last element, compare with the second last element
            min = ar[i] - ar[i - 1];
        } else {
            // For middle elements, compare with both neighbors
            min = (ar[i] - ar[i - 1]) < (ar[i + 1] - ar[i])? (ar[i] - ar[i - 1]) : (ar[i + 1] - ar[i]);
        }
        
        // Print the minimum and maximum differences for the current element
        printf("%d %d\n", min, max);
    }
    
    // Return 0 to indicate successful execution
    return 0;
}
