#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read an integer input which represents the number of elements in the lists
    int n;
    scanf("%d", &n);

    // Declare three arrays to hold the integers
    int a[n], b[n], c[n];

    // Read three lists of integers from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Initialize variables to hold the sum of each list
    int x = 0, y = 0, z = 0;

    // Calculate the sum of elements in list 'a'
    for (int i = 0; i < n; i++) {
        x += a[i];
    }

    // Calculate the sum of elements in list 'b'
    for (int i = 0; i < n; i++) {
        y += b[i];
    }

    // Calculate the sum of elements in list 'c'
    for (int i = 0; i < n; i++) {
        z += c[i];
    }

    // Print the absolute difference between the sums of list 'a' and list 'b'
    printf("%d\n", abs(x - y));

    // Print the absolute difference between the sums of list 'b' and list 'c'
    printf("%d\n", abs(y - z));

    return 0;
}

// <END-OF-CODE>
