
#include <stdio.h>

int main(void) {
    // Setting the modulus value
    const int mod = 100000007;

    // Reading input values: N, A, and B
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    // Initializing the answer variable to 0
    int ans = 0;

    // Calculating the number of repetitions
    int rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += (res < A? res : A);

    // Printing the final answer
    printf("%d\n", ans);

    return 0;
}

