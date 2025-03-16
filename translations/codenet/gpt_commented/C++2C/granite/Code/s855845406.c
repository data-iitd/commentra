
#include <stdio.h>

int main() {
    // Declare variables to hold input values
    int N, A;

    // Read an integer value for N from standard input
    scanf("%d", &N);

    // Read an integer value for A from standard input
    scanf("%d", &A);

    // Calculate the result by squaring N and subtracting A, then output the result
    printf("%d\n", N * N - A);

    return 0; // Indicate that the program ended successfully
}
