
#include <stdio.h>
#include <string.h>

int main()
{
    int n, k, m, f, i;
    char v[1000], d[2][6] = {"LEFT", "RIGHT"};

    scanf("%d %d", &n, &k);
    scanf("%s", v);

    f = k - 1 < n - k;
    m = k - 1 < n - k ? k - 1 : n - k;

    for (i = 0; i < m; i++)
    {
        printf("%s\n", d[!f]);
    }

    for (i = 0; i < strlen(v); i += 2 * f - 1)
    {
        printf("PRINT %c\n", v[i]);
        printf("%s\n", d[f]);
    }

    return 0;
}

