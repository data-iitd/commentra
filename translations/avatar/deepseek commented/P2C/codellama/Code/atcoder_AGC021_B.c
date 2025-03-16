#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, i, j, x, y, X, Y;
    double D[100000], ans;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        XY[i][0] = x;
        XY[i][1] = y;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i != j)
            {
                D[j] = atan2(XY[j][0] - XY[i][0], XY[j][1] - XY[i][1]);
            }
        }

        D[N] = D[0] + 2 * pi;

        ans = 0;
        for (j = 0; j < N; j++)
        {
            if (D[j + 1] - D[j] >= pi)
            {
                ans = (D[j + 1] - D[j]) - pi;
            }
        }

        printf("%.6lf\n", ans / (2 * pi));
    }

    return 0;
}

