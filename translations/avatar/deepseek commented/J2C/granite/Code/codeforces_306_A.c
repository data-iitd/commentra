

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the values of n and m from the user
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an array of size m
    int a[m];

    // Check if n is divisible by m
    if (n % m == 0) {
        // Fill the array with equal parts if n is divisible by m
        for (int i = 0; i < m; i++) {
            a[i] = n / m;
        }
    } else {
        // Calculate the base part size
        int sub = n / m;

        // Fill the array with the base part size
        for (int i = 0; i < m; i++) {
            a[i] = sub;
        }

        // Distribute the remainder
        int test = n - (sub * m);
        int count = 0;
        for (int i = 0; i < test; i++) {
            a[count] = a[count] + 1;
            count++;
            if (count >= m) count = 0;
        }
    }

    // Print the array elements in reverse order
    for (int i = m - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }

    return 0;
}
