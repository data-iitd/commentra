#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, l, m, loop, div, square;
    scanf("%d", &n);
    square = n * n;
    int *odd = (int *)malloc(square * sizeof(int));
    int *even = (int *)malloc(square * sizeof(int));
    for(i = 1; i <= square; i++)
    {
        if(i % 2 == 0)
        {
            even[i - 1] = i;
        }
        else
        {
            odd[i - 1] = i;
        }
    }
    loop = square / n;
    div = loop / 2;
    for(i = 1; i <= loop; i++)
    {
        for(j = 0; j < div; j++)
        {
            if(i % 2 == 1)
            {
                printf("%d %d ", odd[0], even[square - 1]);
                for(k = 0; k < square - 2; k++)
                {
                    printf("%d %d ", odd[k + 1], even[k]);
                }
                printf("%d %d\n", odd[square - 1], even[0]);
                odd[0] = odd[0] + 1;
                even[square - 1] = even[square - 1] - 1;
            }
            else
            {
                printf("%d %d ", even[0], odd[square - 1]);
                for(l = 0; l < square - 2; l++)
                {
                    printf("%d %d ", even[l + 1], odd[l]);
                }
                printf("%d %d\n", even[square - 1], odd[0]);
                even[0] = even[0] + 1;
                odd[square - 1] = odd[square - 1] - 1;
            }
        }
    }
    return 0;
}

