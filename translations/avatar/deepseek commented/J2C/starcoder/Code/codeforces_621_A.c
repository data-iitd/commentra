
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long int sum = 0;
    long long int *arr = (long long int *)malloc(n * sizeof(long long int));
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        if(arr[i] % 2 == 0)
            sum += arr[i];
    }
    long long int *odd = (long long int *)malloc(n * sizeof(long long int));
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2!= 0)
        {
            odd[count] = arr[i];
            count++;
        }
    }
    if(count % 2!= 0)
        sum -= odd[0];
    qsort(odd, count, sizeof(long long int), compare);
    for(int i = 0; i < count; i++)
        sum += odd[i];
    printf("%lld\n", sum);
    return 0;
}

