#include <stdio.h>
#include <stdlib.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int H, W, N;

    // Read three integers from input: H, W, and N
    scanf("%d %d %d", &H, &W, &N);

    // Calculate the maximum of H and W
    int A = max(H, W);

    // Calculate and print the number of full groups needed to accommodate N items
    printf("%d\n", (N + A - 1) / A);

    return 0;
}

/* <END-OF-CODE> */
