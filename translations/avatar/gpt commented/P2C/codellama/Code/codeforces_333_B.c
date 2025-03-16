#include <stdio.h>

int main()
{
    int n, m, i, r, c;
    int b[2 * 100000];

    // Read input from the user
    scanf("%d %d", &n, &m);

    // Initialize a list b of size 2*n with all elements set to 1
    // This list will represent the state of the cells (1 for unblocked, 0 for blocked)
    for (i = 0; i < 2 * n; i++)
        b[i] = 1;

    // Set specific positions in the list b to 0 to indicate they are blocked
    // The first and last elements of the first half and the last half are blocked
    b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;

    // Process each blocked cell based on user input
    for (i = 0; i < m; i++)
    {
        // Read the row (r) and column (c) of the blocked cell
        scanf("%d %d", &r, &c);
        // Mark the corresponding positions in the list b as blocked (0)
        b[r - 1] = b[n + c - 1] = 0;
    }

    // If n is odd and the middle cells are unblocked, block them
    if (n % 2 && b[n / 2] && b[n + n / 2])
        b[n / 2] = 0;

    // Output the total number of unblocked cells by summing the list b
    printf("%d\n", sum(b, 2 * n));

    return 0;
}

int sum(int *b, int n)
{
    int i, s = 0;
    for (i = 0; i < n; i++)
        s += b[i];
    return s;
}

