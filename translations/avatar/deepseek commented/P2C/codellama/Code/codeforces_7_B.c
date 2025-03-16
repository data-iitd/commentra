
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, m, i, j, pos, ind = 1, cnt;
    char op[100];
    int *alocuente;
    alocuente = (int *)malloc(m * sizeof(int));
    scanf("%d %d", &t, &m);
    for (i = 0; i < m; i++)
    {
        alocuente[i] = 0;
    }
    for (i = 0; i < t; i++)
    {
        scanf("%s", op);
        if (strcmp(op, "alloc") == 0)
        {
            scanf("%d", &pos);
            for (j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    pos++;
                    if (pos == atoi(op + 5))
                    {
                        for (j = j - atoi(op + 5) + 1; j <= j; j++)
                        {
                            alocuente[j] = ind;
                        }
                        printf("%d\n", ind);
                        ind++;
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
            scanf("%d", &pos);
            if (alocuente[pos - 1] != pos || alocuente[pos - 1] == 0)
            {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            }
            else
            {
                alocuente[pos - 1] = 0;
            }
        }
        if (strcmp(op, "defragment") == 0)
        {
            cnt = 0;
            for (i = 0; i < m; i++)
            {
                if (alocuente[i] == 0)
                {
                    cnt++;
                }
            }
            alocuente = (int *)realloc(alocuente, (m - cnt) * sizeof(int));
            for (i = 0; i < cnt; i++)
            {
                alocuente[m - cnt + i] = 0;
            }
        }
    }
    return 0;
}
