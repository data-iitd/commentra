
#include <stdio.h>

int main() {
    int n, x = 0, y = 0, z = 0;

    // Read an integer input which represents the number of elements in the lists
    scanf("%d", &n);

    // Read three lists of integers from input
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        x += a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        y += b[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        z += c[i];
    }

    // Print the absolute difference between the sums of list 'a' and list 'b'
    printf("%d\n", abs(x - y));

    // Print the absolute difference between the sums of list 'b' and list 'c'
    printf("%d\n", abs(y - z));

    return 0;
}
