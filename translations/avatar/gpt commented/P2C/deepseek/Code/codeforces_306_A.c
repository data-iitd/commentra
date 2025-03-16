#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int q = n / m;  // Number of items each group will get
    int r = n % m;  // Remaining items after equal distribution

    int a[m];
    for (int i = 0; i < m; i++) {
        a[i] = q;  // Initialize each group with the quotient 'q'
    }

    // Distribute the remainder 'r' among the first 'r' groups
    for (int i = 0; i < r; i++) {
        a[i]++;  // Increment the count for the first 'r' groups by 1
    }

    // Print the final distribution of items in each group
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);  // Print each group's item count on the same line
    }

    return 0;
}
