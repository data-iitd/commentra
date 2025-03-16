#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000

int main()
{
    int n, x, i, ans = 0;
    int a[MAX_INPUT];

    // Read the number of elements (n) and the initial value (x) from input
    scanf("%d %d", &n, &x);

    // Read and sort the list of integers
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);

    // Check if the smallest element in the sorted list is greater than x
    if (a[0] > x)
    {
        // If true, print 0 and exit since no elements can be subtracted from x
        printf("0\n");
        return 0;
    }

    // Iterate through the sorted list of integers
    for (i = 0; i < n; i++)
    {
        // If the current element is greater than x, set x to 0 and break the loop
        if (a[i] > x)
        {
            x = 0;
            break;
        }
        // Subtract the current element from x
        x -= a[i];
        // Increment the answer counter
        ans += 1;
    }

    // If there is any remaining value in x, decrement the answer counter
    if (x != 0)
    {
        ans -= 1;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

