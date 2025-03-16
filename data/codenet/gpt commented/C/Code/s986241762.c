#include <stdio.h>

int main() {
    // Declare variables
    int n; // Number of elements in the array
    long sum = 0; // Variable to store the total sum of differences

    // Read the number of elements from user input
    scanf("%d", &n);
    
    // Declare an array of size n
    int a[n];

    // Read n elements into the array from user input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Iterate through the array to calculate the sum of differences
    for (int i = 1; i < n; i++) {
        // Check if the previous element is greater than the current element
        if (a[i - 1] > a[i]) {
            // Calculate the difference and add it to the sum
            sum += a[i - 1] - a[i];
            // Update the current element to be equal to the previous element
            a[i] = a[i - 1];
        }
    }

    // Print the total sum of differences
    printf("%ld\n", sum);
}
