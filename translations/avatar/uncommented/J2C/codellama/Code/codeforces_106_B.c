
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i, j, fl;
    int ans, ansprice;
    int **vec;

    scanf("%d", &n);

    vec = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        vec[i] = (int *)malloc(4 * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3]);
    }

    ans = 500;
    ansprice = 20000;
    for (i = 0; i < n; i++)
    {
        fl = 1;
        for (j = 0; j < n; j++)
        {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2])
            {
                fl = 0;
            }
        }
        if (fl == 1)
        {
            if (vec[i][3] < ansprice)
            {
                ansprice = vec[i][3];
                ans = i + 1;
            }
        }
    }

    printf("%d", ans);

    for (i = 0; i < n; i++)
    {
        free(vec[i]);
    }
    free(vec);

    return 0;
}

