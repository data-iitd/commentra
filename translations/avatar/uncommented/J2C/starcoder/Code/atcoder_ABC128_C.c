#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int N, M, p, ans;
    scanf("%d %d", &N, &M);
    int a[N];
    for (int i = 0; i < N; i++)
        a[i] = 0;
    for (int i = 0; i < M; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int s;
            scanf("%d", &s);
            s--;
            a[s] |= (1 << i);
        }
    }
    scanf("%d", &p);
    ans = 0;
    for (int s = 0; s < (1 << N); s++)
    {
        int t = 0;
        for (int i = 0; i < N; i++)
        {
            if ((s >> i) & 1)
                t ^= a[i];
        }
        if (p == t)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}

