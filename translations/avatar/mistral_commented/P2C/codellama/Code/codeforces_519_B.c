#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, x, y, z;

    // Take the number of test cases as input
    scanf("%d", &n);

    // Read the first list 'a' of numbers from the standard input
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Read the second list 'b' of numbers from the standard input
    int b[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    // Read the third list 'c' of numbers from the standard input
    int c[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }

    // Initialize variables x, y, and z to 0
    x = 0;
    y = 0;
    z = 0;

    // Iterate through each number in list 'a' and add it to the variable 'x'
    for (i = 0; i < n; i++)
    {
        x += a[i];
    }

    // Iterate through each number in list 'b' and add it to the variable 'y'
    for (i = 0; i < n; i++)
    {
        y += b[i];
    }

    // Iterate through each number in list 'c' and add it to the variable 'z'
    for (i = 0; i < n; i++)
    {
        z += c[i];
    }

    // Print the absolute difference between 'x' and 'y'
    printf("%d\n", abs(x - y));

    // Print the absolute difference between 'y' and 'z'
    printf("%d\n", abs(y - z));

    return 0;
}

