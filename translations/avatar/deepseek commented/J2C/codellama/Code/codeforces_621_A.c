
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    long *list = (long *)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &list[i]);
    }

    long *odd = (long *)malloc(n * sizeof(long));
    long sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (list[i] % 2 == 0)
        {
            sum += list[i];
        }
        else
        {
            odd[i] = list[i];
        }
    }

    qsort(odd, n, sizeof(long), compare);

    for (int i = 0; i < n; i++)
    {
        sum += odd[i];
    }

    if (n % 2 != 0)
    {
        sum -= odd[0];
    }

    printf("%ld", sum);

    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(long *)a - *(long *)b);
}

