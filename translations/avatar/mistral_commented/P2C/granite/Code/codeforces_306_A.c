
#include <stdio.h>

int main() {
    int n, m, q, r, i;
    int a[100];

    // Read the input from the user
    scanf("%d %d", &n, &m);

    // Calculate the quotient and remainder of n divided by m
    q = n / m;
    r = n % m;

    // Initialize the a list with q repeated m times
    for (i = 0; i < m; i++) {
        a[i] = q;
    }

    // Increment the corresponding elements in the a list for the remaining elements
    for (i = 0; i < r; i++) {
        a[i]++;
    }

    // Print each element of the a list separated by a space
    for (i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
