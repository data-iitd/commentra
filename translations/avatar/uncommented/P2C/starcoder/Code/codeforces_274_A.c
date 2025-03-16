#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int num, k, temp = 0, i;
    scanf("%d %d", &num, &k);
    int arr[num];
    for(i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    qsort(arr, num, sizeof(int), compare);
    for(i = 0; i < num; i++)
    {
        if(arr[i] % k!= 0 || arr[i] / k!= arr[i - 1] / k)
            temp++;
    }
    printf("%d", temp);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

