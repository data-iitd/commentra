#include <stdio.h>

int main()
{
    int t, s, q, ans;
    scanf("%d %d %d", &t, &s, &q);
    ans = 0;
    while (s < t)
    {
        s *= q;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
