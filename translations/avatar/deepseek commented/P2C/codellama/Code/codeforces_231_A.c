#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int l1[100], j, sum = 0;
        scanf("%d", &l1[0]);
        for (j = 1; j < l1[0]; j++)
        {
            scanf("%d", &l1[j]);
            sum += l1[j];
        }
        if (sum > 1)
            c++;
    }
    printf("%d", c);
    return 0;
}
