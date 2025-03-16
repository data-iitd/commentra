#include <stdio.h>
#include <stdlib.h>

// Define the modulo constant
#define mod 1000000007

// Function to calculate the value of a
int calc_a(int b) {
    return (2 * b) % mod;
}

// Function to calculate the value of b
int calc_b(int n) {
    return pow(2, 2 * n - 2, mod);
}

// Function to calculate the answer
int calc_ans(int n, int c[], int b, int a) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i] * (a + i * b);
        ans %= mod;
    }
    return ans;
}

// Main function
int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the list of integers and convert them to a list of integers
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Sort the list in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i] < c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    // Calculate the value of b
    int b = calc_b(n);

    // Calculate the value of a
    int a = calc_a(b);

    // Calculate the answer
    int ans = calc_ans(n, c, b, a);

    // Print the final result
    printf("%d\n", ans);

    // Return from the main function
    return 0;
}

