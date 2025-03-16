#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char grid[n][m];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                if ((i + j) % 2)
                {
                    grid[i][j] = 'W';
                }
                else
                {
                    grid[i][j] = 'B';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
