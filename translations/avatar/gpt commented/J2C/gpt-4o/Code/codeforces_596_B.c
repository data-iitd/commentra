#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for abs function

int main() {
    // Reading the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Initializing an array to hold the input values
    long arr[n];
    
    // Loop to read 'n' integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
    
    // Initialize the answer with the absolute value of the first element
    long answer = labs(arr[0]);
    
    // Loop to calculate the sum of absolute differences between consecutive elements
    for (int i = 1; i < n; i++) {
        answer += labs(arr[i] - arr[i - 1]);
    }
    
    // Output the final calculated answer
    printf("%ld\n", answer);
    
    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
