#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

int main()
{
    int N, K, S[100000], temp, ans;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &S[i]);
    temp = 0;
    ans = INT_MAX;
    if (K == 1)
    {
        for (int i = 0; i < N; i++)
        {
            temp = S[i];
            ans = min(abs(temp), ans);
        }
        printf("%d\n", ans);
    }
    else if (N - K!= 0)
    {
        for (int i = 0; i <= N - K; i++)
        {
            int min = S[i];
            int max = S[i + K - 1];
            if (min < 0 && max > 0)
                temp = min(2 * (-min) + max, (-min) + 2 * max);
            else
                temp = max(abs(min), abs(max));
            ans = min(ans, temp);
        }
        printf("%d\n", ans);
    }
    else
    {
        int min = S[0];
        int max = S[N - 1];
        if (min < 0 && max > 0)
            printf("%d\n", min(2 * (-min) + max, (-min) + 2 * max));
        else
            printf("%d\n", max(abs(min), abs(max)));
    }
    return 0;
}

