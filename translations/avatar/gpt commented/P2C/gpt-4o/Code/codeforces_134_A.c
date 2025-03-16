#include <stdio.h>

int main() {
    int n;
    
    // Read the number of elements
    scanf("%d", &n);
    
    int w[n];
    long long x = 0; // Use long long to avoid overflow for large sums
    
    // Read the list of integers and calculate the sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        x += w[i];
    }
    
    // Initialize an array to store indices (maximum size n)
    int d[n];
    int count = 0; // To count valid indices
    
    // Iterate through each element in the list
    for (int i = 0; i < n; i++) {
        // Check if removing the current element results in an average equal to the current element
        if ((x - w[i]) / (n - 1) == w[i]) {
            // If the condition is met, store the 1-based index
            d[count++] = i + 1;
        }
    }
    
    // Print the number of valid indices found
    printf("%d\n", count);
    
    // Print the valid indices as a space-separated string
    for (int i = 0; i < count; i++) {
        printf("%d", d[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
