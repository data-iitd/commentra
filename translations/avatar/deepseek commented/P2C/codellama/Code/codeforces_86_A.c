
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int l, r, curr, s, first, second, ans, i, k;
    char rev[100];

    scanf("%d %d", &l, &r);

    curr = r;
    s = 0;
    while (curr)
    {
        s++;
        curr /= 10;
    }

    first = 10 * s;
    second = first / 2;

    ans = -1;

    for (i = l; i <= r; i++)
    {
        curr = i;
        rev[0] = '\0';
        for (k = 0; k < s; k++)
        {
            rev[k] = (9 - (curr % 10)) + '0';
            curr /= 10;
        }
        ans = max(ans, (atoi(rev) * i));
    }

    printf("%d", ans);

    return 0;
}

