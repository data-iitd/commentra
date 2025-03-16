#include <stdio.h>

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
void ruiseki_lr(int array[], int n, int left[], int right[]) {
    // Initialize left and right arrays
    left[0] = 0;
    right[n] = 0;

    // Calculate the left array
    for (int i = 0; i < n; i++) {
        left[i + 1] = gcd(left[i], array[i]);
    }

    // Calculate the right array
    for (int i = n - 1; i >= 0; i--) {
        right[i] = gcd(right[i + 1], array[i]);
    }
}

int main() {
    // Read input from the user: number of elements in the array
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize left and right arrays
    int left[n + 1];
    int right[n + 1];

    // Perform Ruiseki algorithm on the given array
    ruiseki_lr(a, n, left, right);

    // Initialize answer variable with 0
    int ans = 0;

    // Find the maximum GCD between adjacent elements in the left and right arrays
    for (int i = 0; i < n; i++) {
        ans = (gcd(left[i], right[i + 1]) > ans) ? gcd(left[i], right[i + 1]) : ans;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
