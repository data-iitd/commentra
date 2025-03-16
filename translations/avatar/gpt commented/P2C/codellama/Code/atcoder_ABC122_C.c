#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, q, i, j, l, r, count = 0;
    char *s;
    scanf("%d %d", &n, &q);
    s = (char *)malloc(n * sizeof(char));
    scanf("%s", s);
    int *cumsum = (int *)malloc(n * sizeof(int));
    cumsum[0] = 0;
    for (i = 1; i < n; i++)
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
        scanf("%d %d", &l, &r);
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }
    free(s);
    free(cumsum);
    return 0;
}
