#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int j;
    for (j = 0; j < n; j++)
    {
        if (arr[j] == 1)
        {
            printf("%d ", j);
        }
    }
    printf("\n");
    return 0;
}

