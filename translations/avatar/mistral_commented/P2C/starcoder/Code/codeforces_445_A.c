#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char **l = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        char *row = (char*)malloc(m * sizeof(char));
        scanf("%s", row);
        for (int j = 0; j < m; j++)
        {
            if (row[j] == '.')
            {
                if ((i + j) % 2)
                {
                    row[j] = 'W';
                }
                else
                {
                    row[j] = 'B';
                }
            }
        }
        l[i] = row;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", l[i]);
    }
    return 0;
}
