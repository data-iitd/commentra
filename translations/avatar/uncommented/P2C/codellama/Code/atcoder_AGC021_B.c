#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main()
{
    int N, i, j, x, y, X, Y;
    double a, b, ans;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        double D[N];
        for (j = 0; j < N; j++)
        {
            scanf("%d %d", &X, &Y);
            D[j] = atan2(X - x, Y - y);
        }
        D[N] = D[0] + 2 * PI;
        ans = 0;
        for (j = 0; j < N; j++)
        {
            a = D[j];
            b = D[j + 1];
            if (b - a >= PI)
            {
                ans = (b - a) - PI;
            }
        }
        printf("%.10lf\n", ans / (2 * PI));
    }
    return 0;
}