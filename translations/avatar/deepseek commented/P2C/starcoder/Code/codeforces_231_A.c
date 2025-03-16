#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, c, i;
    scanf("%d", &n);
    c = 0;
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
        {
            c++;
        }
    }
    printf("%d", c);
    return 0;
}
