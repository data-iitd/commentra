
#include <stdio.h>
#include <string.h>

int main()
{
    int n, k, i, j, f, m;
    char v[100000], d[2][6] = {"LEFT", "RIGHT"};
    scanf("%d %d", &n, &k);
    scanf("%s", v);
    f = k - 1 < n - k;
    m = min(k - 1, n - k);
    for (i = 0; i < m; i++)
        printf("%s\n", d[!f]);
    for (i = 0, j = 0; i < n; i++)
    {
        if (i == k - 1 || i == n - k)
            printf("PRINT %c\n", v[j++]);
        if (i == k - 1)
            printf("%s\n", d[f]);
    }
    return 0;
}

