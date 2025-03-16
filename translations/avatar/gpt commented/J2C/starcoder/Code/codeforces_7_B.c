#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, m, n, x, i, j, d, len, allocIdx, hasErased;
    int *memory;
    char cmd[10];

    scanf("%d", &t);
    scanf("%d", &m);

    memory = (int *)malloc(m * sizeof(int));
    allocIdx = 0;

    for (j = 0; j < t; j++)
    {
        scanf("%s", cmd);

        if (strcmp(cmd, "alloc") == 0)
        {
            scanf("%d", &n);
            len = 0;
            canAlloc = false;

            for (i = 0; i < m; i++)
            {
                if (memory[i] == 0)
                    len++;
                else
                    len = 0;

                if (len == n)
                {
                    canAlloc = true;
                    len = i - n + 1;
                    break;
                }
            }

            if (canAlloc)
            {
                allocIdx++;
                for (i = len; i < len + n; i++)
                    memory[i] = allocIdx;
                printf("%d\n", allocIdx);
            }
            else
                printf("NULL\n");
        }
        else if (strcmp(cmd, "erase") == 0)
        {
            scanf("%d", &x);

            if (x <= 0)
            {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                break;
            }

            hasErased = false;

            for (i = 0; i < m; i++)
            {
                if (memory[i] == x)
                {
                    memory[i] = 0;
                    hasErased = true;
                }
            }

            if (!hasErased)
                printf("ILLEGAL_ERASE_ARGUMENT\n");
        }
        else if (strcmp(cmd, "defragment") == 0)
        {
            d = 0;

            for (i = 0; i < m; i++)
            {
                if (memory[i] == 0)
                    d++;
                else
                    memory[i - d] = memory[i];
            }

            for (i = m - d; i < m; i++)
                memory[i] = 0;
        }
        else
        {
            printf("h\n");
        }
    }

    free(memory);
    return 0;
}

