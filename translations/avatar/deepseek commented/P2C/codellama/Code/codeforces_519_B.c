
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, x, y, z;

    printf("Enter the number of elements in each list: ");
    scanf("%d", &n);

    int a[n], b[n], c[n];

    printf("Enter the first list of integers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the second list of integers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Enter the third list of integers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }

    x = 0;
    y = 0;
    z = 0;

    for (i = 0; i < n; i++)
    {
        x += a[i];
    }

    for (i = 0; i < n; i++)
    {
        y += b[i];
    }

    for (i = 0; i < n; i++)
    {
        z += c[i];
    }

    printf("The absolute difference between the sums of the lists is: %d\n", abs(x - y));
    printf("The absolute difference between the sums of the lists is: %d\n", abs(y - z));

    return 0;
}

