#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, count = 0;
    long k, arr[100000];
    scanf("%d", &n);
    scanf("%ld", &k);
    for (i = 0; i < n; i++)
        scanf("%ld", &arr[i]);
    qsort(arr, n, sizeof(long), cmpfunc);
    for (i = 0; i < n; i++)
    {
        if (arr[i] % k!= 0 && arr[i] / k!= k)
        {
            count++;
            arr[i] = arr[i] / k;
        }
    }
    printf("%d\n", count);
    return 0;
}

