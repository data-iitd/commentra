#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int n, a[100], b[100], sum = 0;
    scanf("%d", &n); // Read the number of elements

    // Read n integers into array a
    rep(i, n) scanf("%d", &a[i]);

    // Read n integers into array b
    rep(i, n) {
        scanf("%d", &b[i]);
        if (a[i] - b[i] > 0) { // Check if a[i] is greater than b[i]
            sum += a[i] - b[i]; // Add the difference to sum
        }
    }

    // Output the sum
    printf("%d\n", sum);
}

