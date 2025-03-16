#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100000

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int lst[MAX];
    for(int i = 0; i < N; i++)
        scanf("%d", &lst[i]);
    int lst_p[MAX], lst_m[MAX];
    int p = 0, m = 0, x = 0, y = 0, lastx = 0, lasty = 0;
    for(int i = 0; i < N; i++)
    {
        if(lst[i] == 0)
            K--;
        if(lst[i] > 0)
        {
            lst_p[lastx++] = lst[i];
        }
        else
        {
            lst_m[lasty++] = lst[i];
        }
    }
    int ans = 1000000000;
    for(int k = 0; k <= K; k++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(j > lastx || k - j > lasty)
                continue;
            if(j == 0)
                p = 0;
            else
                p = lst_p[j - 1];
            if(k - j == 0)
                m = 0;
            else
                m = lst_m[lasty - (k - j)];
            ans = min(ans, 2 * p + abs(m), p + 2 * abs(m));
        }
    }
    printf("%d\n", ans);
    return 0;
}
