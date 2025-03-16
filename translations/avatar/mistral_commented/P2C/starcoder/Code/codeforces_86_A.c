#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l, r, curr, s, first, second, ans;
    char rev[100];

    scanf("%d %d", &l, &r);
    curr = r;
    s = 0;
    while (curr)
    {
        s++;
        first = pow(10, s);
        second = first / 2;
        ans = -1;
        for (int i = l; i <= r; i++)
        {
            if (i >= l && i <= r)
            {
                curr = i;
                rev[0] = '\0';
                for (int k = 0; k < strlen(itoa(curr)); k++)
                {
                    strcat(rev, itoa(9 - atoi(itoa(curr)[k])));
                }
                ans = max(ans, atoi(rev) * curr);
            }
        }
    }
    printf("%d", ans);
    return 0;
}

