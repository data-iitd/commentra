#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read an array of integers from standard input
    int arr[2];
    scanf("%d %d", &arr[0], &arr[1]);
    
    // Assign the first two elements of the array to variables a and b
    int a = arr[0], b = arr[1];
    
    // Initialize the number of taps needed to 0
    int tap = 0;
    
    // Initialize the consent variable to 1 (the starting point)
    int consent = 1;
    
    // Loop until the consent value is less than b
    while (consent < b) {
        // Update consent by adding (a - 1) to it
        consent += a - 1;
        // Increment the tap count
        tap++;
    }
    
    // Print the total number of taps needed
    printf("%d\n", tap);
    
    return 0;
}

// <END-OF-CODE>
