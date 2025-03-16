

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    // Recursively calculates the greatest common divisor (GCD) of a and b
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Defines a lambda function to compute GCD
    int (*op)(int, int) = &gcd;
    // Initial GCD value
    int e = 0;
    // Initialize prefix and suffix GCD arrays
    left[0] = e;
    right[n] = e;
    // Compute prefix GCD array
    for (int i = 0; i < n; i++) {
        left[i + 1] = op(left[i], array[i]);
    }
    // Compute suffix GCD array
    for (int i = n - 1; i >= 0; i--) {
        right[i] = op(right[i + 1], array[i]);
    }
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);
    // Read the list of elements
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Compute prefix and suffix GCD arrays
    int *left = (int *)malloc(sizeof(int) * (n + 1));
    int *right = (int *)malloc(sizeof(int) * (n + 1));
    ruiseki_lr(a, n, left, right);
    // Initialize the answer variable
    int ans = 0;
    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; i++) {
        ans = fmax(gcd(left[i], right[i + 1]), ans);
    }
    // Print the result
    printf("%d\n", ans);
    // Free memory
    free(a);
    free(left);
    free(right);
    return 0;
}
