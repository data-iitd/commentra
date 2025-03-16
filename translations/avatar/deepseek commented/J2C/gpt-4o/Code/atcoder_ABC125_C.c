#include <stdio.h>

int A[100000]; // Array to store the input elements (assuming a maximum size)
int L[100000]; // Array to store the prefix GCDs
int R[100000]; // Array to store the suffix GCDs

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    int tmp;
    if (b > a) { // Ensure a is greater than b
        tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0) { // Base case for GCD
        return a;
    }
    int r;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0); // Continue until r is 0
    return a;
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements

    // Read the elements of A from the input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the prefix GCD array L
    L[0] = A[0];
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]);
    }

    // Calculate the suffix GCD array R
    R[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i]);
    }

    // Initialize the answer with the maximum of the GCD of the first and last elements of L and R
    int answer = (N > 1) ? (L[N - 2] > R[1] ? L[N - 2] : R[1]) : 0;

    // Iterate through the array to find the maximum GCD
    for (int i = 1; i < N - 1; i++) {
        int currentGCD = gcd(L[i - 1], R[i + 1]);
        if (currentGCD > answer) {
            answer = currentGCD;
        }
    }

    // Print the final answer
    printf("%d\n", answer);
    return 0;
}

// <END-OF-CODE>
