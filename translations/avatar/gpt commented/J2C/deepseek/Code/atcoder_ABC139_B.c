#include <stdio.h>

int main() {
    int A, B;
    int amari = 0;
    int result = 0;

    // Read two integers A and B from the input
    scanf("%d %d", &A, &B);

    // Calculate the initial result based on the formula (B - 1) / (A - 1)
    result = (B - 1) / (A - 1);

    // Calculate the remainder when (B - 1) is divided by (A - 1)
    amari = (B - 1) % (A - 1);

    // If there is a remainder, increment the result by 1
    if (amari != 0) {
        result += 1;
    }

    // Print the final result to the console
    printf("%d\n", result);

    return 0;
}
