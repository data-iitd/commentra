
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int square = n * n;
    int loop = square / n;
    int div = loop / 2;
    int i, j;
    int odd[square], even[square];
    for (i = 1; i <= square; i++)
    {
        if (i % 2 == 0)
        {
            even[i - 1] = i;
        }
        else
        {
            odd[i - 1] = i;
        }
    }
    for (i = 1; i <= loop; i++)
    {
        for (j = 0; j < div; j++)
        {
            if (i % 2 == 1)
            {
                printf("%d %d ", odd[0], even[square - 1]);
                odd[0] = odd[0] + 1;
                even[square - 1] = even[square - 1] - 1;
            }
            else
            {
                printf("%d %d ", even[0], odd[square - 1]);
                even[0] = even[0] + 1;
                odd[square - 1] = odd[square - 1] - 1;
            }
        }
        printf("\n");
    }
    return 0;
}

