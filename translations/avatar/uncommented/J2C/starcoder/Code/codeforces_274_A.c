#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    long k;
    scanf("%d", &n);
    scanf("%ld", &k);
    long arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    qsort(arr, n, sizeof(long), compare);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % k!= 0)
        {
            count++;
        }
        else
        {
            for(int j = i + 1; j < n; j++)
            {
                if(arr[j] == arr[i] / k)
                {
                    count++;
                    break;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}

