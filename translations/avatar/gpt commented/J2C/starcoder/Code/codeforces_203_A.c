#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x, t, a, b, da, db;
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);
    int first, second;
    int i, j;
    for (i = 0; i < t; i++)
    {
        first = a - (da * i);
        for (j = 0; j < t; j++)
        {
            second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0)
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
