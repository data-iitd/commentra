#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l, r, curr, s, first, second, ans;
    scanf("%d %d", &l, &r);
    curr = r;
    s = 0;
    while (curr)
    {
        s++;
        curr /= 10;
    }
    first = 10 ** s;
    second = first / 2;
    ans = -1;
    for (int i = l; i <= r; i++)
    {
        if (i >= l && i <= r)
        {
            curr = i;
            char rev[100];
            for (int k = 0; k < strlen(rev); k++)
            {
                rev[k] = '9' - rev[k];
            }
            ans = max(ans, atoi(rev) * curr);
        }
    }
    printf("%d\n", ans);
    return 0;
}

