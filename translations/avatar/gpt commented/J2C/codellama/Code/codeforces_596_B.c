#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Creating a Scanner object to read input from the console
    int n;
    scanf("%d", &n);
    
    // Initializing an array to hold the input values
    long *arr = (long *)malloc(n * sizeof(long));
    
    // Loop to read 'n' integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
    
    // Initialize the answer with the absolute value of the first element
    long answer = abs(arr[0]);
    
    // Loop to calculate the sum of absolute differences between consecutive elements
    for (int i = 1; i < n; i++) {
        answer += abs(arr[i] - arr[i - 1]);
    }
    
    // Output the final calculated answer
    printf("%ld\n", answer);
    
    // Free the memory allocated to the array
    free(arr);
    
    return 0;
}

