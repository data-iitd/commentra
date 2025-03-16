

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare and initialize a constant integer
    int num = 998244353;

    // Create an array to store the pairs of integers
    int a[100000][2];

    // Read the number of elements 'n' from the input
    int n;
    scanf("%d", &n);

    // Read the pairs of integers from the input and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    // Sort the array using qsort
    qsort(a, n, sizeof(a[0]), cmpfunc);

    // Check if 'n' is odd or even
    if (n % 2 == 1) {
        // If 'n' is odd, calculate the range by subtracting the middle element of 'a' from the middle element of 'a' and add 1
        printf("%d\n", a[n / 2][1] - a[n / 2][0] + 1);
    } else {
        // If 'n' is even, calculate the range by averaging the middle elements of 'a' and 'a' and multiply by 2, then add 1
        double b = (a[n / 2][0] + a[n / 2 - 1][0]) / 2.0;
        double c = (a[n / 2][1] + a[n / 2 - 1][1]) / 2.0;
        printf("%d\n", (int)(2 * (c - b) + 1));
    }

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return ((int *)a)[0] - ((int *)b)[0];
}

// END-OF-CODE