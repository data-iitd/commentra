
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int N, M, p, s, t, x, k, i, j, ans;
    scanf("%d %d", &N, &M);
    int a[N];
    for(i = 0; i < N; i++)
        a[i] = 0;
    for(i = 0; i < M; i++)
    {
        scanf("%d", &k);
        for(j = 0; j < k; j++)
        {
            scanf("%d", &s);
            s--;
            a[s] |= (1 << i);
        }
    }
    scanf("%d", &p);
    ans = 0;
    for(s = 0; s < (1 << N); s++)
    {
        t = 0;
        for(i = 0; i < N; i++)
        {
            if((s >> i) & 1)
                t ^= a[i];
        }
        if(p == t)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}

