#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    if (n < 1)
    {
        if (m < 1)
        {
            printf("%d %d", n, m);
            return 0;
        }
        printf("Impossible");
        return 0;
    }

    if (m > n)
    {
        int min = m;
        int max = n + m - 1;
        printf("%d %d", min, max);
    }
    else if (m <= n)
    {
        int min = n;
        int max = n + m - 1;
        if (m == 0)
        {
            max = n;
        }
        printf("%d %d", min, max);
    }

    return 0;
}
