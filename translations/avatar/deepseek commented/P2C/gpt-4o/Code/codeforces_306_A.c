#include <stdio.h>

int main() {
    int n, m;  // Declare variables for total items and number of groups
    scanf("%d %d", &n, &m);  // Take two integers n and m as input

    int q = n / m;  // Calculate the quotient
    int r = n % m;  // Calculate the remainder

    int a[m];  // Initialize an array a of length m

    for (int i = 0; i < m; i++) {
        a[i] = q;  // Set each element in the array to q
    }

    for (int i = 0; i < r; i++) {
        a[i] += 1;  // Distribute the remaining items
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);  // Print each element separated by a space
    }
    
    return 0;  // Return success
}

// <END-OF-CODE>
