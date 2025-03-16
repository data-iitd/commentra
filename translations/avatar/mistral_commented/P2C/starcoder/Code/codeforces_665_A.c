#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, at, b, bt, t1, t2, st, fin, now, ans;
    scanf("%d %d %d %d %d:%d %d:%d", &a, &at, &b, &bt, &t1, &t2, &st, &fin);
    now = 0;
    ans = 0;
    while (now < fin && now < 1140)
    {
        if (now + bt > st)
        {
            ans++;
        }
        now += b;
    }
    printf("%d", ans);
    return 0;
}
