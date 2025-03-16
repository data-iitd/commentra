#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, P, i, j, one, zero, pattern_a, pattern_b, time;
    int *lis, *ls;

    scanf("%d %d", &N, &P);
    lis = (int *) malloc(N * sizeof(int));
    ls = (int *) malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &lis[i]);
        ls[i] = lis[i] % 2;
    }
    one = 0;
    zero = 0;
    for (i = 0; i < N; i++)
    {
        if (ls[i] == 1)
            one++;
        else
            zero++;
    }
    pattern_a = 0;
    pattern_b = 0;
    for (j = 0; j <= zero; j++)
        pattern_b += combi(zero, j);
    time = 0;
    while (time <= one)
    {
        if (time % 2 == P)
            pattern_a += combi(one, time);
        time++;
    }
    printf("%d", pattern_a * pattern_b);
    return 0;
}

int combi(int N, int K)
{
    int a = 1;
    for (int i = 0; i < K; i++)
        a *= N - i;
    for (int j = 0; j < K; j++)
        a /= j + 1;
    return a;
}

