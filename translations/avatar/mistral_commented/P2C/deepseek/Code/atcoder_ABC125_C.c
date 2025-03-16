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
void ruiseki_lr(int* array, int n, int* left, int* right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize the first element of left and last element of right to 0
    left[0] = 0;
    right[n] = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i + 1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n - 1; i >= 0; i--) {
        right[i] = op(right[i + 1], array[i]);
    }
}

int main() {
    int n;
    // Read input from the user: number of elements in the array and the array itself
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Initialize empty arrays 'left' and 'right' of size 'n+1'
    int left[n + 1];
    int right[n + 1];
    // Perform Ruiseki algorithm on the given array and get the left and right arrays
    ruiseki_lr(a, n, left, right);
    // Initialize answer variable with 0
    int ans = 0;
    // Iterate through the array and find the maximum GCD between adjacent elements in the left and right arrays
    for (int i = 0; i < n; i++) {
        int current_gcd = gcd(left[i], right[i + 1]);
        if (current_gcd > ans) {
            ans = current_gcd;
        }
    }
    // Print the final answer
    printf("%d\n", ans);
    return 0;
}
