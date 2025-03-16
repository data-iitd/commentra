
#include <stdio.h>

int main(void)
{
    int t, s, q, ans = 0;
    scanf("%d %d %d", &t, &s, &q);
    while (s < t)
    {
        s *= q;
        ans++;
    }
    printf("%d", ans);
    return 0;
}

