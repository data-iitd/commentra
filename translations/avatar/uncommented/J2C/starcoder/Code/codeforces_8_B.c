#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, x = 0, y = 0, k = 0, dx, dy;
    int co[2][101];
    char ch[100];
    char *s;
    int len;
    int flag = 1;

    scanf("%s", ch);
    len = strlen(ch);
    co[0][k] = x;
    co[1][k] = y;
    k++;
    for (i = 0; i < len; i++)
    {
        switch (ch[i])
        {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        }
        co[0][k] = x;
        co[1][k] = y;
        k++;
    }
    for (i = 0; i < k - 3; i++)
    {
        for (j = i + 3; j < k; j++)
        {
            dx = co[0][i] - co[0][j];
            dy = co[1][i] - co[1][j];
            if (dx < 0)
                dx *= (-1);
            if (dy < 0)
                dy *= (-1);
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0))
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
            break;
    }
    if (flag)
        printf("OK\n");
    else
        printf("BUG\n");
    return 0;
}

