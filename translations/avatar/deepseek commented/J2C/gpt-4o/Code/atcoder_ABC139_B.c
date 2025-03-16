#include <stdio.h>

int main() {
    // Step 1: Declare variables for input and output.
    int A, B;
    int amari = 0;
    int result = 0;

    // Step 2: Read the first integer A from the input.
    scanf("%d", &A);

    // Step 3: Read the second integer B from the input.
    scanf("%d", &B);

    // Step 4: Calculate the quotient (result) by dividing (B-1) by (A-1).
    result = (B - 1) / (A - 1);

    // Step 5: Calculate the remainder (amari) by taking the modulus of (B-1) by (A-1).
    amari = (B - 1) % (A - 1);

    // Step 6: If the remainder is not zero, increment the result by 1.
    if (amari != 0) {
        result += 1;
    }

    // Step 7: Print the result to the standard output.
    printf("%d\n", result);

    return 0; // Step 8: Return 0 to indicate successful completion.
}

// <END-OF-CODE>
