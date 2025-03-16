
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y, i, j, k, arr[100], n;
    scanf("%d", &y);
    for (i = 0; i < y; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (k = 0; k < y; k++)
            {
                if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j])
                {
                    printf("%d %d %d", k + 1, j + 1, i + 1);
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}
