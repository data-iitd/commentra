#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, P, ans = 0, one, zero, pattern_a = 0, pattern_b = 0, time = 0;
    int *lis, *ls;

    scanf("%d %d", &N, &P);
    lis = (int *)malloc(N * sizeof(int));
    ls = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &lis[i]);
        ls[i] = lis[i] % 2;
    }

    one = ls[0];
    zero = ls[0];

    for (int i = 1; i < N; i++)
    {
        one += ls[i];
        zero += ls[i];
    }

    for (int j = 0; j <= zero; j++)
    {
        pattern_b += combi(zero, j);
    }

    while (time <= one)
    {
        if (time % 2 == P)
        {
            pattern_a += combi(one, time);
        }
        time++;
    }

    printf("%d", pattern_a * pattern_b);

    return 0;
}

int combi(int N, int K)
{
    int a = 1;
    for (int i = 0; i < K; i++)
    {
        a *= N - i;
    }
    for (int j = 0; j < K; j++)
    {
        a /= j + 1;
    }
    return a;
}

