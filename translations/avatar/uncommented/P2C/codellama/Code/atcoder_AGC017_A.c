
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, P;
    scanf("%d %d", &N, &P);

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

    int ans = 0;
    int lis[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &lis[i]);
    }
    int ls[N];
    for (int a = 0; a < N; a++)
    {
        ls[a] = lis[a] % 2;
    }
    int one = 0, zero = 0;
    for (int a = 0; a < N; a++)
    {
        if (ls[a] == 1)
        {
            one++;
        }
        else
        {
            zero++;
        }
    }
    int pattern_a = 0, pattern_b = 0;
    for (int j = 0; j <= zero; j++)
    {
        pattern_b += combi(zero, j);
    }
    int time = 0;
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

