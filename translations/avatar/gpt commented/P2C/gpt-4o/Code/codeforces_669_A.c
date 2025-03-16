#include <stdio.h>

int main() {
    // Read an integer input from the user
    int n;
    scanf("%d", &n);

    // Calculate the result using the formula (n * 2 + 1) / 3
    // This formula effectively computes (2n + 1) divided by 3 and returns the integer part
    int result = (n * 2 + 1) / 3;

    // Print the calculated result
    printf("%d\n", result);

    return 0;
}

// <END-OF-CODE>
