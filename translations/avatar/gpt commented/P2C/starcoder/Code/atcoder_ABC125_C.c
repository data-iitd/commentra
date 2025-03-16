#include <stdio.h>
#include <stdlib.h>

// Define the operation to find the GCD of two numbers
int op(int a, int b) {
    return a == 0? b : op(b % a, a);
}

// Function to calculate the cumulative GCD from the left
int *ruiseki_lr(int *array, int n) {
    // Initialize the identity element for GCD
    int e = 0;
    
    // Create lists to store cumulative GCD from the left and right
    int *left = (int *) malloc((n + 1) * sizeof(int));
    int *right = (int *) malloc((n + 1) * sizeof(int));
    
    // Calculate cumulative GCD from the left
    for (int i = 0; i < n; i++) {
        left[i + 1] = op(left[i], array[i]);
    }
    
    // Calculate cumulative GCD from the right
    for (int i = n - 1; i >= 0; i--) {
        right[i] = op(right[i + 1], array[i]);
    }
    
    // Return both cumulative GCD lists
    return left, right;
}

// Function to find the maximum GCD of left and right parts
int max_gcd(int *left, int *right, int n) {
    // Initialize the answer variable to store the maximum GCD found
    int ans = 0;
    
    // Iterate through the array to find the maximum GCD of left and right parts
    for (int i = 0; i < n; i++) {
        ans = max(op(left[i], right[i + 1]), ans);
    }
    
    // Return the maximum GCD found
    return ans;
}

// Main function
int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Read the array elements from input and convert them to integers
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Compute the cumulative GCD from the left and right
    int *left, *right;
    left, right = ruiseki_lr(a, n);
    
    // Find the maximum GCD of left and right parts
    int ans = max_gcd(left, right, n);
    
    // Print the maximum GCD found
    printf("%d", ans);
    
    // Free the memory allocated to the arrays
    free(a);
    free(left);
    free(right);
    
    // Return from main
    return 0;
}

