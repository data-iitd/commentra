#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, m, n, x, d, i, j, k, len, allocIdx, canAlloc, hasErased;
    int *memory;
    scanf("%d", &t);
    scanf("%d", &m);
    memory = (int *)malloc(m * sizeof(int));
    allocIdx = 0;
    for (j = 0; j < t; j++)
    {
        scanf("%s", &n);
        if (n == 5)
        {
            scanf("%d", &n);
            len = 0;
            canAlloc = 0;
            for (i = 0; i < m; i++)
            {
                if (memory[i] == 0)
                    len++;
                else
                    len = 0;
                if (len == n)
                {
                    canAlloc = 1;
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
        else if (n == 4)
        {
            scanf("%d", &x);
            if (x <= 0)
            {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                break;
            }
            hasErased = 0;
            for (i = 0; i < m; i++)
            {
                if (memory[i] == x)
                {
                    memory[i] = 0;
                    hasErased = 1;
                }
            }
            if (!hasErased)
                printf("ILLEGAL_ERASE_ARGUMENT\n");
        }
        else if (n == 7)
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
            printf("h\n");
    }
    free(memory);
    return 0;
}

