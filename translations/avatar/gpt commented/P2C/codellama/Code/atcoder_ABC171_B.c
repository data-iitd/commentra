#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, sum = 0;
    scanf("%d %d", &n, &k);
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), compare);
    for (i = 0; i < k; i++)
        sum += arr[i];
    printf("%d", sum);
    free(arr);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

