
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, arr[100], sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (arr[0] > 15)
    {
        printf("15");
    }
    else
    {
        for (i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] > 15)
            {
                printf("%d", arr[i - 1] + 15);
                break;
            }
        }
        if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90)
        {
            printf("90");
        }
        else
        {
            printf("%d", arr[n - 1] + 15);
        }
    }
    return 0;
}

