#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum, c;
    scanf("%d", &n);
    int arr[n];
    sum = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    c = 0;
    for (i = 0; i < n; i++)
    {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i])
        {
            c++;
            printf("%d ", i + 1);
        }
    }
    printf("\n%d\n", c);
    return 0;
}

