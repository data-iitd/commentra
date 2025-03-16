
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    int **points = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        points[i] = (int *)malloc(d * sizeof(int));
        for (int j = 0; j < d; j++)
        {
            scanf("%d", &points[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double tmp = 0.0;
            for (int k = 0; k < d; k++)
            {
                tmp += (points[i][k] - points[j][k]) * (points[i][k] - points[j][k]);
            }
            if (sqrt(tmp) == (int)sqrt(tmp))
            {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}

