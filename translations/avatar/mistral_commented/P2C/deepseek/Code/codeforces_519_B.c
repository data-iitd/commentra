#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x = 0, y = 0, z = 0;

    // Read the number of test cases
    scanf("%d", &n);

    // Read the first list 'a' of numbers
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        x += a[i];
    }

    // Read the second list 'b' of numbers
    int b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        y += b[i];
    }

    // Read the third list 'c' of numbers
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        z += c[i];
    }

    // Print the absolute difference between 'x' and 'y'
    printf("%d\n", abs(x - y));

    // Print the absolute difference between 'y' and 'z'
    printf("%d\n", abs(y - z));

    return 0;
}
