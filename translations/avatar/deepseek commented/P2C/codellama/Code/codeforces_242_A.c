
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    int games[100000];
    int i, j, k = 0;
    for (i = a; i <= x; i++)
    {
        if (i <= b)
            continue;
        else
        {
            for (j = b; j <= y; j++)
            {
                if (i > j)
                {
                    games[k] = i;
                    games[k + 1] = j;
                    k = k + 2;
                }
            }
        }
    }
    printf("%d\n", k / 2);
    for (i = 0; i < k; i = i + 2)
    {
        printf("%d %d\n", games[i], games[i + 1]);
    }
    return 0;
}
