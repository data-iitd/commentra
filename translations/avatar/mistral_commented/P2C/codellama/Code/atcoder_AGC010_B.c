#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, sum = 0;
    int *a;

    // Take input from the user
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Check if the sum of the elements in the list is divisible by the formula
    for (i = 0; i < n; i++)
    {
        sum += a[i];
    }
    if (sum % (n * (n + 1) / 2))
    {
        printf("NO\n");
        return 0;
    }

    // Calculate the average of the elements in the list
    k = sum / (n * (n + 1) / 2);

    // Add the first element to the end of the list for simplification
    a[n] = a[0];

    // Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
    for (i = 1; i <= n; i++)
    {
        if (((k - a[i - 1] + a[i]) % n) || ((k - a[i - 1] + a[i]) / n < 0))
        {
            printf("NO\n");
            return 0;
        }
    }

    // If all checks pass, print YES
    printf("YES\n");

    // End of code
    return 0;
}
