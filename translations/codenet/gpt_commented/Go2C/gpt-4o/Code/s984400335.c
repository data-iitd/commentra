#include <stdio.h>

// min function takes two integers and returns the minimum value among them.
int min(int x, int y) {
    return (x < y) ? x : y;
}

int main() {
    // Declare variables to hold input values
    int n, a, b;
    // Read three integers from standard input
    scanf("%d %d %d", &n, &a, &b);

    // Calculate the minimum of n*a and b, and print the result
    printf("%d\n", min(n * a, b));

    return 0;
}

// <END-OF-CODE>
