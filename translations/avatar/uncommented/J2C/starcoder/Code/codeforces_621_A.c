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
    long long int *list = (long long int *)malloc(n * sizeof(long long int));
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &list[i]);
    }
    long long int *odd = (long long int *)malloc(n * sizeof(long long int));
    for(int i = 0; i < n; i++)
    {
        if(list[i] % 2 == 0)
        {
            sum += list[i];
        }
        else
        {
            odd[i] = list[i];
        }
    }
    qsort(odd, n, sizeof(long long int), compare);
    for(int i = 0; i < n; i++)
    {
        sum += odd[i];
    }
    if(n % 2!= 0)
    {
        sum -= odd[0];
    }
    printf("%lld\n", sum);
    return 0;
}

