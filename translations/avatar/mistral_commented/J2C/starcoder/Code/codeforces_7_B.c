
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int t, m, n, x, len, allocIdx, d, newSize, k;
    int *memory, *newMemory;
    scanf("%d", &t);
    for(int j = 0; j < t; j++)
    {
        scanf("%s", &m);
        if(m == "alloc")
        {
            scanf("%d", &n);
            len = 0;
            allocIdx = 0;
            for(int i = 0; i < m; i++)
            {
                if(memory[i] == 0)
                {
                    len++;
                }
                else
                {
                    len = 0;
                }
                if(len == n)
                {
                    allocIdx++;
                    len = i - n + 1;
                    break;
                }
            }
            if(allocIdx > 0)
            {
                printf("%d\n", allocIdx);
                for(int i = len; i < len + n; i++)
                {
                    memory[i] = allocIdx;
                }
            }
            else
            {
                printf("NULL\n");
            }
        }
        else if(m == "erase")
        {
            scanf("%d", &x);
            if(x <= 0)
            {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                break;
            }
            for(int i = 0; i < m; i++)
            {
                if(memory[i] == x)
                {
                    memory[i] = 0;
                    break;
                }
            }
        }
        else if(m == "defragment")
        {
            d = 0;
            for(int i = 0; i < m; i++)
            {
                if(memory[i] == 0)
                {
                    d++;
                }
            }
            newSize = m - d;
            newMemory = (int *)malloc(newSize * sizeof(int));
            k = 0;
            for(int i = 0; i < m; i++)
            {
                if(memory[i]!= 0)
                {
                    newMemory[k] = memory[i];
                    k++;
                }
            }
            memory = newMemory;
        }
        else
        {
            printf("h\n");
        }
    }
    return 0;
}

