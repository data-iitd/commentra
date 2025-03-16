#include <stdio.h>

// Function to compute the GCD of two integers
int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: call gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to compute cumulative GCD from left and right
void ruiseki_lr(int array[], int n, int left[], int right[]) {
    // Initialize the identity element for GCD
    int e = 0;

    // Calculate cumulative GCD from the left
    left[0] = e;
    for (int i = 0; i < n; i++) {
        left[i + 1] = gcd(left[i], array[i]);
    }

    // Calculate cumulative GCD from the right
    right[n] = e;
    for (int i = n - 1; i >= 0; i--) {
        right[i] = gcd(right[i + 1], array[i]);
    }
}

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Read the array elements
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Create arrays to store cumulative GCD from the left and right
    int left[n + 1];
    int right[n + 1];

    // Compute the cumulative GCD from the left and right
    ruiseki_lr(a, n, left, right);

    // Initialize the answer variable to store the maximum GCD found
    int ans = 0;

    // Iterate through the array to find the maximum GCD of left and right parts
    for (int i = 0; i < n; i++) {
        ans = (gcd(left[i], right[i + 1]) > ans) ? gcd(left[i], right[i + 1]) : ans;
    }

    // Print the maximum GCD found
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
