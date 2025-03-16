#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, d, i, j, count = 0;
    scanf("%d %d", &n, &d);
    int *points = (int *)malloc(n * d * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < d; j++)
            scanf("%d", &points[i * d + j]);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (floor(sqrt(pow(points[i * d] - points[j * d], 2) + pow(points[i * d + 1] - points[j * d + 1], 2))) == sqrt(pow(points[i * d] - points[j * d], 2) + pow(points[i * d + 1] - points[j * d + 1], 2)))
                count++;
    printf("%d", count);
    return 0;
}

