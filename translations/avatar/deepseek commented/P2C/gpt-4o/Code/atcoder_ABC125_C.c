#include <stdio.h>

int gcd(int a, int b) {
    // Recursively calculates the greatest common divisor (GCD) of a and b
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void ruiseki_lr(int array[], int n, int left[], int right[]) {
    // Initial GCD value
    int e = 0;
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
    // Read the number of elements
    int n;
    scanf("%d", &n);
    
    // Read the list of elements
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Initialize prefix and suffix GCD arrays
    int left[n + 1];
    int right[n + 1];
    left[0] = 0; // Initial value for left GCD
    right[n] = 0; // Initial value for right GCD
    
    // Compute prefix and suffix GCD arrays
    ruiseki_lr(a, n, left, right);
    
    // Initialize the answer variable
    int ans = 0;
    
    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; i++) {
        ans = (gcd(left[i], right[i + 1]) > ans) ? gcd(left[i], right[i + 1]) : ans;
    }
    
    // Print the result
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
