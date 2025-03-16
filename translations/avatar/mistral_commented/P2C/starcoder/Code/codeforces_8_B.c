#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *record_of_movements = "LURD";
    int x = 0, y = 0;
    int d_movement[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int d[100][100] = {0};
    int bug = 0;

    for (int i = 0; i < 4; i++)
    {
        if (d[x + d_movement[i][0]][y + d_movement[i][1]] == 1)
        {
            bug = 1;
            break;
        }
        d[x + d_movement[i][0]][y + d_movement[i][1]] = 1;
        x += d_movement[i][0];
        y += d_movement[i][1];
    }

    if (bug)
    {
        printf("BUG");
    }
    else
    {
        printf("OK");
    }

    return 0;
}

