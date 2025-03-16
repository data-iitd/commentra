#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to compute prefix and suffix GCD arrays
void ruiseki_lr(int* array, int n, int* left, int* right) {
    // Initialize prefix and suffix GCD arrays
    int e = 0;
    left[0] = e;
    right[n] = e;

    // Compute prefix GCD array
    for (int i = 0; i < n; i++) {
        left[i + 1] = gcd(left[i], array[i]);
    }

    // Compute suffix GCD array
    for (int i = n - 1; i >= 0; i--) {
        right[i] = gcd(right[i + 1], array[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Allocate memory for prefix and suffix GCD arrays
    int* left = (int*)malloc((n + 1) * sizeof(int));
    int* right = (int*)malloc((n + 1) * sizeof(int));

    // Compute prefix and suffix GCD arrays
    ruiseki_lr(a, n, left, right);

    // Initialize the answer variable
    int ans = 0;

    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; i++) {
        int current_gcd = gcd(left[i], right[i + 1]);
        if (current_gcd > ans) {
            ans = current_gcd;
        }
    }

    // Print the result
    printf("%d\n", ans);

    // Free allocated memory
    free(left);
    free(right);

    return 0;
}
