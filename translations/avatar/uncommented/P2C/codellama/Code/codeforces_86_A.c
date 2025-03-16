
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100];
    int l, r, curr, s, first, second, i, j, k, ans;
    ans = -1;
    scanf("%s", str);
    l = str[0] - '0';
    r = str[2] - '0';
    curr = r;
    s = 0;
    while (curr)
    {
        s++;
        curr /= 10;
    }
    first = 10 * s;
    second = first / 2;
    for (i = l; i <= r; i++)
    {
        curr = i;
        rev = "";
        for (j = 0; j < s; j++)
        {
            k = curr % 10;
            rev = (char)((9 - k) + '0') + rev;
            curr /= 10;
        }
        ans = max(ans, (int)rev * i);
    }
    printf("%d", ans);
    return 0;
}

