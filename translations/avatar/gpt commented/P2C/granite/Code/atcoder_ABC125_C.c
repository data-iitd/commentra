
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: call gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to calculate the cumulative GCD from the left and right
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define the operation to find the GCD of two numbers
    int (*op)(int, int) = &gcd;
    
    // Initialize the identity element for GCD
    int e = 0;
    
    // Calculate cumulative GCD from the left
    left[0] = e;
    for (int i = 0; i < n; i++) {
        left[i + 1] = op(left[i], array[i]);
    }
    
    // Calculate cumulative GCD from the right
    right[n] = e;
    for (int i = n - 1; i >= 0; i--) {
        right[i] = op(right[i + 1], array[i]);
    }
}

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Read the array elements from input and convert them to integers
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Compute the cumulative GCD from the left and right
    int *left = (int *)malloc((n + 1) * sizeof(int));
    int *right = (int *)malloc((n + 1) * sizeof(int));
    ruiseki_lr(a, n, left, right);
    
    // Initialize the answer variable to store the maximum GCD found
    int ans = 0;
    
    // Iterate through the array to find the maximum GCD of left and right parts
    for (int i = 0; i < n; i++) {
        ans = fmax(gcd(left[i], right[i + 1]), ans);
    }
    
    // Print the maximum GCD found
    printf("%d\n", ans);
    
    // Free the allocated memory
    free(a);
    free(left);
    free(right);
    
    return 0;
}

