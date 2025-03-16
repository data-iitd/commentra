#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);  // Take two integers n and m as input
    // These integers represent the total number of items n and the number of groups m

    int q = n / m;  // Calculate the quotient, which is the number of items each group will have
    int r = n % m;  // Calculate the remainder, which is the number of items that will be left over

    int a[m];  // Initialize an array a of length m
    for (int i = 0; i < m; i++) {
        a[i] = q;  // Set each element in the array a to q
    }
    // This represents the initial distribution of items among the groups

    for (int i = 0; i < r; i++) {  // Loop for the number of remaining items r
        a[i] += 1;  // Increment the corresponding element in the array a by 1
        // Ensuring that the remaining items are distributed evenly
    }

    for (int i = 0; i < m; i++) {  // Loop to print the elements of the array a
        printf("%d ", a[i]);  // Print each element separated by a space
    }

    printf("\n");  // Print a newline character at the end

    return 0;
}
