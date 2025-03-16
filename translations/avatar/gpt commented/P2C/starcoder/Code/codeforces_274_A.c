#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, k, i, j, temp, *arr, size;
    scanf("%d %d", &num, &k);
    arr = (int *)malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    qsort(arr, num, sizeof(int), compare);
    temp = 0;
    size = 0;
    for (i = 0; i < num; i++)
    {
        if (arr[i] % k!= 0 ||!arr[i] / k in arr)
        {
            arr[size++] = arr[i];
        }
        temp = max(size, temp);
    }
    printf("%d", temp);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

