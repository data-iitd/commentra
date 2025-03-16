
#include <stdio.h>
#include <stdlib.h>

// Defines a lambda function to compute GCD
int op(int a, int b) {
    return (a > b)? op(b, a) : (b == 0)? a : op(b, a % b);
}

// Computes the greatest common divisor (GCD) of a and b
int gcd(int a, int b) {
    return op(a, b);
}

// Computes the prefix and suffix GCD arrays
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Initial GCD value
    int e = 0;
    // Initialize prefix and suffix GCD arrays
    for (int i = 0; i <= n; i++) {
        left[i] = e;
        right[i] = e;
    }
    // Compute prefix GCD array
    for (int i = 0; i < n; i++) {
        left[i + 1] = gcd(left[i], array[i]);
    }
    // Compute suffix GCD array
    for (int i = n - 1; i >= 0; i--) {
        right[i] = gcd(right[i + 1], array[i]);
    }
}

// Main function
int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);
    // Read the list of elements
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Compute prefix and suffix GCD arrays
    int *left = (int *) malloc((n + 1) * sizeof(int));
    int *right = (int *) malloc((n + 1) * sizeof(int));
    ruiseki_lr(a, n, left, right);
    // Initialize the answer variable
    int ans = 0;
    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; i++) {
        ans = max(gcd(left[i], right[i + 1]), ans);
    }
    // Print the result
    printf("%d\n", ans);
    return 0;
}

