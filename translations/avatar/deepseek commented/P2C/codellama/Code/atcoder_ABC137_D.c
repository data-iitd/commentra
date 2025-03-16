
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

int main()
{
    int n, m;
    int x[MAX_N];
    int y[MAX_M];
    int i, j, k;
    int d, s;
    int r;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &d, &s);
        x[i] = -d;
        y[i] = -s;
    }

    for (i = 0; i < n; i++)
    {
        d = x[i];
        s = y[i];
        r = m - i;

        if (r >= -d)
        {
            printf("%d ", s);
        }
        else
        {
            printf("%d ", s);
            printf("%d ", y[i - 1]);
            break;
        }
    }

    printf("\n");

    return 0;
}

