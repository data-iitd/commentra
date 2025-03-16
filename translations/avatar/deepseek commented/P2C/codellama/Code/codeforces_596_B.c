
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, ans, r[1000];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &r[i]);
    }

    ans = abs(r[0]);

    for (i = 1; i < n; i++)
    {
        ans += abs(r[i] - r[i - 1]);
    }

    printf("%d", ans);

    return 0;
}

