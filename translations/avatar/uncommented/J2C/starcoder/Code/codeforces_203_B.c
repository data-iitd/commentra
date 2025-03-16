#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, x, y, black[100][100];
    scanf("%d %d", &N, &M);
    for (int m = 1; m <= M; m++)
    {
        scanf("%d %d", &x, &y);
        for (int xx = x - 1; xx <= x + 1; xx++)
        {
            for (int yy = y - 1; yy <= y + 1; yy++)
            {
                if (++black[xx][yy] == 9)
                {
                    printf("%d\n", m);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
