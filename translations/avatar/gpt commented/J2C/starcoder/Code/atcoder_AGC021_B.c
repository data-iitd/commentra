#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);
    int x[N], y[N];
    for (int i = 0; i < N; i++)
        scanf("%d %d", &x[i], &y[i]);
    for (int i = 0; i < N; i++)
    {
        double thetas[N];
        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;
            thetas[j] = atan2(y[j] - y[i], x[j] - x[i]);
        }
        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;
            thetas[j] += 2 * M_PI;
        }
        double ans = 0;
        for (int j = 0; j < N - 1; j++)
            ans = fmax(ans, thetas[j + 1] - thetas[j] - M_PI);
        printf("%.10lf\n", ans / (M_PI * 2));
    }
    return 0;
}
