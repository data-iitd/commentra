#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, s, f, d, i, j, t, l, r, k;
    char c;
    char res[100000];
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
    i = 1;
    j = s;
    t = l = r = 0;
    k = 1;
    while (j != f)
    {
        if (i > t && k < m)
        {
            scanf("%d %d %d", &t, &l, &r);
            k++;
        }
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r))
        {
            res[j - s] = 'X';
        }
        else
        {
            res[j - s] = c;
            j += d;
        }
        i++;
    }
    printf("%s", res);
    return 0;
}

