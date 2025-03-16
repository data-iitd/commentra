#include <stdio.h>

int main()
{
    int n, m, q, r, i;

    // Read two integers from input: n (total items) and m (number of groups)
    scanf("%d %d", &n, &m);

    // Calculate the quotient (q) and remainder (r) when n is divided by m
    q = n / m;  // Number of items each group will get
    r = n % m;  // Remaining items after equal distribution

    // Create a list 'a' initialized with 'm' elements, each set to the quotient 'q'
    int a[m];
    for (i = 0; i < m; i++)
        a[i] = q;

    // Distribute the remainder 'r' among the first 'r' groups
    for (i = 0; i < r; i++)
        a[i] += 1;  // Increment the count for the first 'r' groups by 1

    // Print the final distribution of items in each group
    for (i = 0; i < m; i++)
        printf("%d ", a[i]);  // Print each group's item count on the same line

    printf("\n");

    return 0;
}

