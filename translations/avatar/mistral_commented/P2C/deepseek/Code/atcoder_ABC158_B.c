#include <stdio.h>

#define MOD 1000000007

// Function to read an integer
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read multiple integers
void readInts(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

// Main function
void main() {
    // Setting the modulus value
    const int mod = MOD;

    // Reading input values: N, A, and B
    int N, A, B;
    readInts(&N, &A, &B);

    // Initializing the answer variable to 0
    int ans = 0;

    // Calculating the number of repetitions
    int rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += (res < A) ? res : A;

    // Printing the final answer
    printf("%d\n", ans);
}
