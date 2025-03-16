#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, sum;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (k = 0; k < n; k++)
            {
                if (arr[k]!= arr[j] && arr[k]!= arr[i] && arr[k] == arr[i] + arr[j])
                {
                    printf("%d %d %d\n", k + 1, j + 1, i + 1);
                    exit(0);
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
