
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, x, *w, *d;

    // Read the number of elements in the list `w`
    scanf("%d", &n);

    // Allocate memory for the list `w`
    w = (int *)malloc(n * sizeof(int));

    // Read `n` integers from the standard input and store them in the list `w`
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    // Calculate the sum of all elements in the list `w`
    x = 0;
    for (i = 0; i < n; i++)
    {
        x += w[i];
    }

    // Initialize an empty list `d` to store the indices of elements that satisfy the condition
    d = (int *)malloc(n * sizeof(int));
    int d_len = 0;

    // Iterate over each element in the list `w`
    for (i = 0; i < n; i++)
    {
        // Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
        if ((x - w[i]) / (n - 1) == w[i])
        {
            // Append the 1-based index of the element to the list `d`
            d[d_len++] = i + 1;
        }
    }

    // Print the length of the list `d`
    printf("%d\n", d_len);

    // Print the indices in `d` separated by spaces
    for (i = 0; i < d_len; i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");

    // Free the memory allocated for the list `w`
    free(w);

    // Free the memory allocated for the list `d`
    free(d);

    return 0;
}

