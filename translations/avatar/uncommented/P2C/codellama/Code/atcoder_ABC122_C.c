#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, q, i, j, k, l, r, total;
    char s[100000];
    scanf("%d %d", &n, &q);
    scanf("%s", s);
    int problems[q][2];
    for (i = 0; i < q; i++)
    {
        scanf("%d %d", &problems[i][0], &problems[i][1]);
    }
    int cumsum[n + 1];
    cumsum[0] = 0;
    for (i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'A' && s[i] == 'C')
        {
            cumsum[i] = cumsum[i - 1] + 1;
        }
        else
        {
            cumsum[i] = cumsum[i - 1];
        }
    }
    for (i = 0; i < q; i++)
    {
        l = problems[i][0];
        r = problems[i][1];
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }
    return 0;
}
