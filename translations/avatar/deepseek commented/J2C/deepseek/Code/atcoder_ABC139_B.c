#include <stdio.h>

int main() {
    int A, B;
    int result, amari;

    // Step 1: Read the first integer A from the input.
    scanf("%d %d", &A, &B);

    // Step 2: Initialize variables to store the quotient and remainder.
    amari = 0;
    result = 0;

    // Step 3: Calculate the quotient (result) by dividing (B-1) by (A-1).
    result = (B - 1) / (A - 1);

    // Step 4: Calculate the remainder (amari) by taking the modulus of (B-1) by (A-1).
    amari = (B - 1) % (A - 1);

    // Step 5: If the remainder is not zero, increment the result by 1.
    if (amari != 0) {
        result += 1;
    }

    // Step 6: Print the result to the standard output.
    printf("%d\n", result);

    return 0;
}
