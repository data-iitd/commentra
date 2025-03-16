
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Reading the number of elements in the array
    
    long arr[n]; // Initializing an array to hold the input values
    
    // Loop to read 'n' integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
    
    long answer =labs(arr[0]); // Initialize the answer with the absolute value of the first element
    
    // Loop to calculate the sum of absolute differences between consecutive elements
    for (int i = 1; i < n; i++) {
        answer +=labs(arr[i] - arr[i - 1]);
    }
    
    // Output the final calculated answer
    printf("%ld\n", answer);
    
    return 0;
}
