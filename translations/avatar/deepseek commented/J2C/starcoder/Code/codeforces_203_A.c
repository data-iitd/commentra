#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, t, a, b, da, db, first, second;
    scanf("%d", &x);
    scanf("%d", &t);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &da);
    scanf("%d", &db);
    for (int i = 0; i < t; i++)
    {
        first = a - (da * i);
        for (int j = 0; j < t; j++)
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
