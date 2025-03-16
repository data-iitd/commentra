
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int t, m, i, j, pos, cnt, ind = 1;
    int *alocuente;
    scanf("%d %d", &t, &m);
    alocuente = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        alocuente[i] = 0;
    for (i = 0; i < t; i++)
    {
        char *op = (char *)malloc(100 * sizeof(char));
        scanf("%s", op);
        if (strcmp(op, "alloc") == 0)
        {
            pos = 0;
            for (j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    pos++;
                    if (pos == atoi(op + 6))
                    {
                        alocuente[j - atoi(op + 6) + 1 : j + 1] = (int *)malloc(atoi(op + 6) * sizeof(int));
                        for (j = j - atoi(op + 6) + 1; j < j + atoi(op + 6); j++)
                            alocuente[j] = ind;
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
            if (atoi(op + 6) == 0 || atoi(op + 6) > m || alocuente[atoi(op + 6) - 1] == 0)
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            else
            {
                for (j = 0; j < m; j++)
                {
                    if (atoi(op + 6) > 0 && alocuente[j] == atoi(op + 6))
                    {
                        alocuente[j] = 0;
                        break;
                    }
                }
            }
        }
        if (strcmp(op, "defragment") == 0)
        {
            cnt = 0;
            for (j = 0; j < m; j++)
                if (alocuente[j] == 0)
                    cnt++;
            for (j = 0; j < cnt; j++)
                alocuente[j] = 0;
            for (j = cnt; j < m; j++)
                alocuente[j - cnt] = alocuente[j];
            for (j = m - cnt; j < m; j++)
                alocuente[j] = 0;
        }
        free(op);
    }
    free(alocuente);
    return 0;
}

