#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, m, i, j, pos, cnt;
    int *alocuente;
    char *op, *op1;
    alocuente = (int *)malloc(m * sizeof(int));
    scanf("%d %d", &t, &m);
    for (i = 0; i < m; i++)
    {
        alocuente[i] = 0;
    }
    for (i = 0; i < t; i++)
    {
        op = (char *)malloc(10 * sizeof(char));
        op1 = (char *)malloc(10 * sizeof(char));
        scanf("%s %s", op, op1);
        if (strcmp(op, "alloc") == 0)
        {
            pos = 0;
            for (j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    pos++;
                    if (pos == atoi(op1))
                    {
                        for (j = j - atoi(op1) + 1; j <= j; j++)
                        {
                            alocuente[j] = i + 1;
                        }
                        printf("%d\n", i + 1);
                        i++;
                        break;
                    }
                }
                else
                {
                    pos = 0;
                }
            }
            if (j == m)
            {
                printf("NULL\n");
            }
        }
        if (strcmp(op, "erase") == 0)
        {
            pos = 0;
            for (j = 0; j < m; j++)
            {
                if (alocuente[j] == atoi(op1))
                {
                    alocuente[j] = 0;
                    break;
                }
            }
            if (j == m)
            {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            }
        }
        if (strcmp(op, "defragment") == 0)
        {
            cnt = 0;
            for (j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    cnt++;
                }
            }
            alocuente = (int *)realloc(alocuente, (m - cnt) * sizeof(int));
            for (j = 0; j < cnt; j++)
            {
                alocuente[m - cnt + j] = 0;
            }
        }
    }
    return 0;
}