
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, k, i, j, temp;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < k; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int sum = 0;
    for (i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}

