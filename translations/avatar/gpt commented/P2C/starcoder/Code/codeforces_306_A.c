#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, q, r, i;
    scanf("%d %d", &n, &m);
    q = n / m;
    r = n % m;
    int *a = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        a[i] = q;
    for (i = 0; i < r; i++)
        a[i]++;
    for (i = 0; i < m; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
