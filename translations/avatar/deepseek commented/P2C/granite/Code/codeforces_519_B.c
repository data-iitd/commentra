

#include <stdio.h>

int main() {
    int n;  // Number of elements in each list
    int a[1000];  // First list of integers
    int b[1000];  // Second list of integers
    int c[1000];  // Third list of integers
    int x = 0;  // Sum of elements in list a
    int y = 0;  // Sum of elements in list b
    int z = 0;  // Sum of elements in list c
    int i;

    // Read the number of elements in each list
    scanf("%d", &n);

    // Read the first list of integers
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Read the ith element of list a
        x += a[i];  // Add the ith element of list a to x
    }

    // Read the second list of integers
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);  // Read the ith element of list b
        y += b[i];  // Add the ith element of list b to y
    }

    // Read the third list of integers
    for (i = 0; i < n; i++) {
        scanf("%d", &c[i]);  // Read the ith element of list c
        z += c[i];  // Add the ith element of list c to z
    }

    // Print the absolute differences between the sums of the lists
    printf("%d\n", abs(x - y));  // Print the absolute difference between the sums of lists a and b
    printf("%d\n", abs(y - z));  // Print the absolute difference between the sums of lists b and c

    return 0;
}
