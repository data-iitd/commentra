#include <stdio.h> // Including standard input-output library

int main() {
    // Variable to hold the number of elements to be inputted
    int a;
    
    // Reading the number of elements
    scanf("%d", &a);
    
    // Initializing an array to hold the input integers
    int ar[a];
    
    // Variables to hold the maximum and minimum differences
    int max = 0, min = 0;
    
    // Loop to read integers into the array
    for (int i = 0; i < a; i++) {
        scanf("%d", &ar[i]); // Reading each integer into the array
    }
    
    // Loop to calculate and print the min and max differences for each element
    for (int i = 0; i < a; i++) {
        // Calculating the maximum difference from the first and last elements
        max = (ar[i] - ar[0] > ar[a - 1] - ar[i]) ? (ar[i] - ar[0]) : (ar[a - 1] - ar[i]);
        
        // Calculating the minimum difference based on the position of the current element
        if (i == 0) {
            // If it's the first element, compare with the second element
            min = ar[i + 1] - ar[i];
        } else if (i == a - 1) {
            // If it's the last element, compare with the second last element
            min = ar[i] - ar[i - 1];
        } else {
            // For middle elements, compare with both neighbors
            min = (ar[i] - ar[i - 1] < ar[i + 1] - ar[i]) ? (ar[i] - ar[i - 1]) : (ar[i + 1] - ar[i]);
        }
        
        // Printing the minimum and maximum differences for the current element
        printf("%d %d\n", min, max);
    }
    
    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
