#include <stdio.h>
#include <math.h>

int main() {
    // Declare and initialize two integer variables n and m
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the value of x using the given formula
    int x = m * 1900 + (n - m) * 100;

    // Print the result
    printf("%d\n", x * (int)pow(2.0, (double)m));

    return 0;
}

// <END-OF-CODE>
