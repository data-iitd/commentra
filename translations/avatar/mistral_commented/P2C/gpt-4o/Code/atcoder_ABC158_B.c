#include <stdio.h>

#define MOD 1000000007

// Function to read an integer
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Main function
int main() {
    // Reading input values: N, A, and B
    int N = readInt();
    int A = readInt();
    int B = readInt();

    // Initializing the answer variable to 0
    long long ans = 0;

    // Calculating the number of repetitions
    int rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += (res < A) ? res : A;

    // Printing the final answer
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
