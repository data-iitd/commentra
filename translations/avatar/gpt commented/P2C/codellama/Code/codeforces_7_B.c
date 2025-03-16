#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, m, i, j, pos, ind = 1;
    int *alocuente;
    char *op;

    scanf("%d %d", &t, &m);
    alocuente = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        alocuente[i] = 0;

    for (i = 0; i < t; i++)
    {
        scanf("%s", op);
        if (strcmp(op, "alloc") == 0)
        {
            pos = 0;
            for (j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    pos++;
                    if (pos == atoi(op[1]))
                    {
                        alocuente[j - atoi(op[1]) + 1:j + 1] = ind;
                        printf("%d\n", ind);
                        ind++;
                        break;
                    }
                }
                else
                    pos = 0;
            }
            if (j == m)
                printf("NULL\n");
        }
        if (strcmp(op, "erase") == 0)
        {
            pos = 0;
            for (j = 0; j < m; j++)
            {
                if (alocuente[j] == atoi(op[1]))
                {
                    alocuente[j] = 0;
                    break;
                }
            }
            if (j == m)
                printf("ILLEGAL_ERASE_ARGUMENT\n");
        }
        if (strcmp(op, "defragment") == 0)
        {
            int cnt = 0;
            for (j = 0; j < m; j++)
                if (alocuente[j] == 0)
                    cnt++;
            alocuente = (int *)realloc(alocuente, (m - cnt) * sizeof(int));
            for (j = 0; j < cnt; j++)
                alocuente[m - cnt + j] = 0;
        }
    }
    free(alocuente);
    return 0;
}

