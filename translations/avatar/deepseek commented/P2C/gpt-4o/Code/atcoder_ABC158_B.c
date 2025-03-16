#include <stdio.h>

#define MOD 1000000007

// Function to read an integer
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read multiple integers
void readInts(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

// Main function
int main() {
    int N, A, B;  // Variables to hold N, A, and B
    readInts(&N, &A, &B);  // Reading N, A, and B

    long long ans = 0;  // Initializing the result variable

    // Calculating the number of complete cycles of A + B within N
    long long rep = N / (A + B);

    // Updating the result with the number of complete cycles multiplied by A
    ans += rep * A;

    // Calculating the remaining days after the complete cycles
    long long res = N - rep * (A + B);

    // Updating the result with the minimum of the remaining days and A
    ans += (res < A) ? res : A;

    // Printing the final result
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
