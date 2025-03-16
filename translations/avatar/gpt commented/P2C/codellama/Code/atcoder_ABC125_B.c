#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int V[N];
    int C[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &C[i]);
    }

    int profit_differences[N];
    profit_differences[0] = 0;

    int ans = 0;

    int X = 0;
    int Y = 0;

    for (int i = 0; i < N; i++)
    {
        if (V[i] - C[i] > 0)
        {
            X = V[i];
            Y = C[i];
            profit_differences[i + 1] = X - Y;
        }
    }

    for (int i = 0; i < N; i++)
    {
        ans += profit_differences[i];
    }

    printf("%d", ans);

    return 0;
}

