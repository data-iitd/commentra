#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K, i, j, p, m, x, y, lastx, lasty, ans;
    scanf("%d %d", &N, &K);
    int *lst = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", &lst[i]);
    int *lst_p = (int *)malloc(N * sizeof(int));
    int *lst_m = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        if (lst[i] == 0)
            K--;
        else if (lst[i] > 0)
            lst_p[p++] = lst[i];
        else
            lst_m[m++] = lst[i];
    }
    p = 0, m = 0, x = 0, y = m - 1;
    lastx = p, lasty = m;
    ans = 1000000000;
    for (j = 0; j <= K; j++)
    {
        if (j > lastx || K - j > lasty)
            continue;
        if (j == 0)
            p = 0;
        else
            p = lst_p[j - 1];
        if (K - j == 0)
            m = 0;
        else
            m = lst_m[lasty - (K - j)];
        ans = min(ans, 2 * p + abs(m), p + 2 * abs(m));
    }
    printf("%d", ans);
    return 0;
}

