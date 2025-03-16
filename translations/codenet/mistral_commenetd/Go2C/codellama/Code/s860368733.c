
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }
    int counter = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        if (h[a - 1] < h[b - 1])
        {
            counter++;
        }
        else if (h[a - 1] > h[b - 1])
        {
            counter++;
        }
        else if (h[a - 1] == h[b - 1])
        {
            counter++;
        }
    }
    printf("%d", n - counter);
    return 0;
}

