#include <stdio.h>
#include <stdlib.h>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: find the GCD of b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Main function
int main() {
    // Read input from the user: number of elements in the array and the array itself
    int n;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Perform Ruiseki algorithm on the given array and get the left and right arrays
    int *left = (int *) malloc((n+1) * sizeof(int));
    int *right = (int *) malloc((n+1) * sizeof(int));
    ruiseki_lr(a, n, left, right);
    // Initialize answer variable with 0
    int ans = 0;
    // Iterate through the array and find the maximum GCD between adjacent elements in the left and right arrays
    for (int i = 0; i < n; i++) {
        ans = max(gcd(left[i], right[i+1]), ans);
    }
    // Print the final answer
    printf("%d", ans);
    return 0;
}

