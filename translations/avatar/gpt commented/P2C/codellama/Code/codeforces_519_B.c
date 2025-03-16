#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, x, y, z;

    // Read an integer input which represents the number of elements in the lists
    scanf("%d", &n);

    // Read three lists of integers from input
    int a[n], b[n], c[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }

    // Initialize variables to hold the sum of each list
    x = 0;
    y = 0;
    z = 0;

    // Calculate the sum of elements in list 'a'
    for (i = 0; i < n; i++)
    {
        x += a[i];
    }

    // Calculate the sum of elements in list 'b'
    for (i = 0; i < n; i++)
    {
        y += b[i];
    }

    // Calculate the sum of elements in list 'c'
    for (i = 0; i < n; i++)
    {
        z += c[i];
    }

    // Print the absolute difference between the sums of list 'a' and list 'b'
    printf("%d\n", abs(x - y));

    // Print the absolute difference between the sums of list 'b' and list 'c'
    printf("%d\n", abs(y - z));

    return 0;
}

