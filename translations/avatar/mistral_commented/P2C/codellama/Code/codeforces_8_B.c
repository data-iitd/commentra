#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *record_of_movements = (char *)malloc(1000000 * sizeof(char));
    scanf("%s", record_of_movements);

    int x = 0, y = 0;
    int d_movement[4][2] = {
        {0, -1},
        {0, 1},
        {1, 0},
        {-1, 0}
    };
    int d[1000000][2];
    int bug = 0;

    d[0][0] = x;
    d[0][1] = y;

    for (int i = 0; i < strlen(record_of_movements); i++)
    {
        int temp[2];
        temp[0] = x;
        temp[1] = y;

        x += d_movement[record_of_movements[i] - 'A'][0];
        y += d_movement[record_of_movements[i] - 'A'][1];

        if (d[x][y] == 0)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((x + d_movement[j][0]) != temp[0] && (x + d_movement[j][0]) != temp[1] && d[x + d_movement[j][0]][y + d_movement[j][1]] != 0)
                {
                    bug = 1;
                    break;
                }
            }
        }

        d[x][y] = 1;
    }

    if (bug == 1)
    {
        printf("BUG\n");
    }
    else
    {
        printf("OK\n");
    }

    free(record_of_movements);
    return 0;
}

