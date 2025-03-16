
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int dp[N];
    dp[0] = 0;
    for (int i = 1; i < N; i++)
    {
        if (A[i] <= A[dp[i - 1]])
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = i;
        }
    }
    int K = 0;
    for (int i = 0; i < N; i++)
    {
        if (dp[i] < K)
        {
            K = dp[i];
        }
    }
    printf("%d\n", K);
    return 0;
}

