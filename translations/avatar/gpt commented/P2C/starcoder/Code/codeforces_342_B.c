#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, s, f, t, l, r, i, j, k, d;
    char res[100000];

    scanf("%d %d %d %d", &n, &m, &s, &f);
    i = 1;
    j = s;
    k = 1;
    d = 1;
    if (s < f)
    {
        d = 1;
        res[0] = 'R';
    }
    else
    {
        d = -1;
        res[0] = 'L';
    }
    while (j!= f)
    {
        if (i > t && k < m)
        {
            scanf("%d %d %d", &t, &l, &r);
            k++;
        }
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r))
        {
            res[i] = 'X';
        }
        else
        {
            res[i] = res[0];
            j += d;
        }
        i++;
    }
    res[i] = '\0';
    printf("%s", res);
    return 0;
}

