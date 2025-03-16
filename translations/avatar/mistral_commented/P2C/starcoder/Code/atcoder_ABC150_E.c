#include <stdio.h>
#include <stdlib.h>

// Set the value of modulo for modular arithmetic calculations
#define mod 1000000007

// Function to calculate the value of b using the formula 2^(2*n-2) modulo mod
int calculate_b(int n) {
    return pow(2, 2 * n - 2, mod);
}

// Function to calculate the value of a as 2*b modulo mod
int calculate_a(int b) {
    return 2 * b % mod;
}

// Function to calculate the value of ans as the sum of the product of each element in the list c with the sum of a and i*b
int calculate_ans(int *c, int n, int a, int b) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i] * (a + i * b);
        ans %= mod;
    }
    return ans;
}

// Function to print the value of ans as the output
void print_ans(int ans) {
    printf("%d\n", ans);
}

// Function to read an integer n from the standard input
int read_n() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read n integers from the standard input and store them in a list c in descending order
void read_c(int *c, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i] < c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Read an integer n from the standard input
    int n = read_n();

    // Declare an array c of size n
    int *c = (int *) malloc(n * sizeof(int));

    // Read n integers from the standard input and store them in a list c in descending order
    read_c(c, n);

    // Calculate the value of b using the formula 2^(2*n-2) modulo mod
    int b = calculate_b(n);

    // Calculate the value of a as 2*b modulo mod
    int a = calculate_a(b);

    // Calculate the value of ans as the sum of the product of each element in the list c with the sum of a and i*b
    int ans = calculate_ans(c, n, a, b);

    // Print the value of ans as the output
    print_ans(ans);

    // Free the memory allocated to c
    free(c);

    // Return from main function
    return 0;
}

