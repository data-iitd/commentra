
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, j, sum = 0;
    scanf("%d %d", &n, &k);
    int *numbers = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (i = 0; i < k; i++)
    {
        sum += numbers[i];
    }
    printf("%d", sum);
    free(numbers);
    return 0;
}

