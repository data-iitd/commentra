
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, k, i, j, temp, arr[100000], count = 0;
    scanf("%d %d", &num, &k);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < num; i++)
    {
        if (arr[i] % k != 0)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

