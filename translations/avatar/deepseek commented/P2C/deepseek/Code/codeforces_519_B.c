#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements in each list

    int a[n], b[n], c[n];
    int x = 0, y = 0, z = 0;

    // Read the first list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read the second list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // Read the third list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Calculate the sum of elements in each list
    for (int i = 0; i < n; i++) {
        x += a[i];  // Add each element of list a to x
    }
    for (int i = 0; i < n; i++) {
        y += b[i];  // Add each element of list b to y
    }
    for (int i = 0; i < n; i++) {
        z += c[i];  // Add each element of list c to z
    }

    // Print the absolute differences between the sums of the lists
    printf("%d\n", abs(x - y));  // Print the absolute difference between the sums of lists a and b
    printf("%d\n", abs(y - z));  // Print the absolute difference between the sums of lists b and c

    return 0;
}
