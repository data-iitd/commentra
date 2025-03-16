#######
# Code
#######

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, s, f, t, l, r, i, j, k, d;
    char c;
    scanf("%d %d %d %d", &n, &m, &s, &f);
    if (s < f)
    {
        d = 1;
        c = 'R';
    }
    else
    {
        d = -1;
        c = 'L';
    }
    res = "";
    i = 1;
    j = s;
    scanf("%d %d %d", &t, &l, &r);
    k = 1;
    while (j!= f)
    {
        if (i > t && k < m)
        {
            scanf("%d %d %d", &t, &l, &r);
            k += 1;
        }
        if (i == t && (l <= j <= r || l <= j + d <= r))
        {
            res += 'X';
        }
        else
        {
            res += c;
            j += d;
        }
        i += 1;
    }
    printf("%s", res);
    return 0;
}

