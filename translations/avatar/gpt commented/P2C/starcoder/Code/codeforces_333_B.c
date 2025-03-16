#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, r, c;
    int *b;

    scanf("%d %d", &n, &m);
    b = (int *)malloc(2 * n * sizeof(int));
    for (i = 0; i < 2 * n; i++)
        b[i] = 1;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &r, &c);
        b[r - 1] = b[n + c - 1] = 0;
    }
    if (n % 2 && b[n / 2] && b[n + n / 2])
        b[n / 2] = 0;
    printf("%d\n", sum(b, 2 * n));
    return 0;
}

