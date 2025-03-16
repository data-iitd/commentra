// problem_b.c

#include <stdio.h>
#include <stdlib.h>

// Define a constant for modulus operation
#define CONST_MOD (1000000007)

// Function to read an integer from input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read n integers into an array
int* getIntSlice(int n) {
    int* ns = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

// Function to compute the greatest common divisor of a and b
int numGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return numGcd(b, a % b);
}

// Function to compute the least common multiple of a and b
int numLcm(int a, int b) {
    return a * (b / numGcd(a, b));
}

// Function to solve the problem
void solve() {
    // Read n and m from input
    int n = getInt();
    int m = getInt();
    
    // Read n integers into array a
    int* a = getIntSlice(n);

    // Calculate the sum of all elements in a
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    // Count how many elements in a meet the required rate
    int count = 0;
    double rate = (double)sum / (4 * m);
    for (int i = 0; i < n; i++) {
        if ((double)a[i] >= rate) {
            count++;
        }
    }

    // Output "Yes" if count is greater than or equal to m, otherwise "No"
    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free allocated memory
    free(a);
}

// Main function initializes the program and calls solve
int main() {
    // Call the solve function to execute the main logic
    solve();
    return 0;
}

// <END-OF-CODE>
