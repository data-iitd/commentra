#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, m, i, j, pos, cnt, ind = 1;
    int *alocuente;
    scanf("%d %d", &t, &m);
    alocuente = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        alocuente[i] = 0;
    for (i = 0; i < t; i++)
    {
        char op[10];
        scanf("%s", op);
        if (strcmp(op, "alloc") == 0)
        {
            scanf("%d", &pos);
            for (j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    pos++;
                    if (pos == atoi(op[1]))
                    {
                        for (j = j - atoi(op[1]) + 1; j <= j; j++)
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
        else if (strcmp(op, "erase") == 0)
        {
            scanf("%d", &pos);
            if (alocuente[pos] == atoi(op[1]) && alocuente[pos]!= 0)
            {
                alocuente[pos] = 0;
            }
            else
                printf("ILLEGAL_ERASE_ARGUMENT\n");
        }
        else if (strcmp(op, "defragment") == 0)
        {
            cnt = 0;
            for (j = 0; j < m; j++)
                if (alocuente[j] == 0)
                    cnt++;
            alocuente = (int *)realloc(alocuente, (m - cnt) * sizeof(int));
            for (j = m - cnt; j < m; j++)
                alocuente[j] = 0;
        }
    }
    return 0;
}
