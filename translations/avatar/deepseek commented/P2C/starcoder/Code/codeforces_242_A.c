
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    int games[1000000];
    int i, j;
    for (i = a; i <= x; i++)
    {
        if (i <= b)
            continue;
        for (j = b; j <= y; j++)
        {
            if (i > j)
            {
                games[i - a] = j - b;
            }
        }
    }
    printf("%d\n", i - a);
    for (i = 0; i < i - a; i++)
    {
        printf("%d %d\n", games[i] + a, games[i] + b);
    }
    return 0;
}

