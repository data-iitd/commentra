#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, sum = 0;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}
