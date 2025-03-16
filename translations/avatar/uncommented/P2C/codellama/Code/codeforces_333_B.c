#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, r, c, i;
    int *b;
    char *str;

    scanf("%d %d", &n, &m);
    b = (int *)malloc(n * 2 * sizeof(int));
    memset(b, 1, n * 2 * sizeof(int));
    b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &r, &c);
        b[r - 1] = b[n + c - 1] = 0;
    }
    if (n % 2 && b[n / 2] && b[n + n / 2])
        b[n / 2] = 0;
    printf("%d", sum(b));

    free(b);
    return 0;
}

